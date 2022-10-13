#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

// fixed array a[] given
// queries of form l r k
// to find number of elements in a in [l,r] range <= k
// offline fashion

using pii = pair<int,int>;

int n, q, a[100100], b[100100];
vector<pii> v;
vector<pair<pii,pii>> queries;
int t[400400];

void build(int index, int l, int r){
    if(l == r){
        t[index] = 0;
        return;
    }
    int mid=(l+r)/2;
    build(index<<1, l, mid);
    build(index<<1|1, mid+1, r);
    t[index] = 0;
}

void update(int index, int l, int r, int pos){
    if(l > pos || r < pos){
        return;
    }
    if(l == r){
        t[index] = 1;
        return;
    }
    int mid=(l+r)>>1;
    update(index<<1, l, mid, pos);
    update(index<<1|1, mid+1, r, pos);
    t[index] = t[index<<1] + t[index<<1|1];
}

int querysum(int index, int l, int r, int lq, int rq){
    if(l > rq || lq > r){
        return 0;
    }
    if(lq<=l && r<=rq){
        return t[index];
    }
    int mid=(l+r)/2;
    return (querysum(index<<1, l, mid, lq, rq) + querysum(index<<1|1, mid+1, r, lq, rq));
}

void solve()
{
    v.clear();
    queries.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i] = 0;
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    build(1, 0, n-1);
    cin>>q;
    for(int i=0; i<q; i++){
        int l, r, k;
        cin>>l>>r>>k;
        queries.push_back(make_pair(make_pair(k,i),make_pair(l,r)));
    }
    sort(queries.begin(), queries.end());
    int ans[q];
    int p=0;
// cout<<"feqfwqfdwfwfdw"<<n<<endl;
    for(int j=0; j<q; j++){
        int k, i, l, r, t;
        k = queries[j].first.first;
        i = queries[j].first.second;
        l = queries[j].second.first;
        r = queries[j].second.second;
        pii mp = make_pair(k,n);
        auto it = upper_bound(v.begin(), v.end(), mp);
        t = it-v.begin();
        for( ; p<t; p++){
// cout<<p<<" "<<v[p].first<<" "<<v[p].second<<endl;
            update(1, 0, n-1, v[p].second);
        }
        ans[i] = querysum(1, 0, n-1, l, r);
    }
    for(int i=0; i<q; i++){
        cout<<ans[i]<<endl;
    }
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}