#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

// fixed array a[] given
// queries of form l r k
// to find number of elements in a in [l,r] range <= k
// online fashion

int n, q, a[100100], b[100100];
map<int,int> mp;

vector<int> t[400400];

vector<int> merge(vector<int> &a, vector<int> &b){
    int i=0, j=0;
    int alen = a.size(), blen = b.size();
    vector<int> v;
    while(i<alen && j<alen){
        if(a[i] < b[j]){
            v.push_back(a[i]);
            i++;
        }else{
            v.push_back(b[j]);
            j++;
        }
    }
    while(i<alen){
        v.push_back(a[i]);
        i++;
    }
    while(j<blen){
        v.push_back(b[j]);
        j++;
    }
    return v;
}

void build(int index, int l, int r){
    if(l == r){
        vector<int> v(1,a[l]);
        t[index] = v;
        return;
    }
    int mid=(l+r)/2;
    build(index<<1, l, mid);
    build(index<<1|1, mid+1, r);
    t[index] = merge(t[index<<1], t[index<<1|1]);
}

int query(int index, int l, int r, int lq, int rq, int k){
// cout<<index<<" "<<l<<" "<<r<<endl;
    if(l > rq || lq > r){
// cout<<"1"<<endl<<endl;
        return 0;
    }
    if(lq<=l && r<=rq){
// for(int i=l; i<=r; i++){
//     cout<<a[i]<<" ";
// }cout<<endl;
        auto it = upper_bound(t[index].begin(), t[index].end(), k);
// cout<<"2"<<it-t[index].begin()<<endl<<endl;
        return it-t[index].begin();
    }
    int mid=(l+r)/2;
    return (query(index<<1, l, mid, lq, rq, k) + query(index<<1|1, mid+1, r, lq, rq, k));
}

void solve()
{
    mp.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>b[i];
        if(mp.find(b[i]) == mp.end()){
            a[i] = -1;
        }else{
            a[i] = mp[b[i]];
        }
        mp[b[i]] = i;
    }
// for(int i=0; i<n; i++){
//     cout<<a[i]<<" ";
// }cout<<endl;
    build(1, 0, n-1);
    cin>>q;
    for(int i=0; i<q; i++){
        int l, r, k;
        cin>>l>>r;
        k = l-1;
        int ans=query(1, 0, n-1, l, r, k);
        cout<<ans<<endl;
    }
// for(auto x : t[1]){
//     cout<<x<<" ";
// }cout<<endl;
// for(auto x : t[2]){
//     cout<<x<<" ";
// }cout<<endl;
// for(auto x : t[3]){
//     cout<<x<<" ";
// }cout<<endl;
// for(auto x : t[4]){
//     cout<<x<<" ";
// }cout<<endl;
// for(auto x : t[5]){
//     cout<<x<<" ";
// }cout<<endl;
// cout<<query(1, 0, n-1, 1, 5, 0);
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}