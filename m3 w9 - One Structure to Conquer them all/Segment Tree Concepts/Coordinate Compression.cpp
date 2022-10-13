#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

int n, q, a[100100], t[400400];

// 1 3 5 6 8 10000

struct compressed_coordinates{
    map<int,int> compval;           // mp[-inf] = 0, mp[1] = 1, mp[3] = 2, ..., mp[10000] = 6, mp[inf] = 7
    vector<int> rev;                // rev[0] = -inf, rev[1] = 1, ..., rev[6] = 10000, rev[7] = -inf
    int cnt;
    void clear(){
        compval.clear();
        rev.clear();
    }
    void add(int x){
        compval[x] = 0;
    }
    void initialise(){
        cnt = 0;
        for(auto it=compval.begin(); it!= compval.end(); it++){
            compval[it->first] = cnt++;
        }
    }
};

void build(int index, int l, int r){
    if(l == r){
        t[index] = 0;
        return;
    }
    int mid=(l+r)/2;
    build(t[2*index], l, mid);
    build(t[2*index+1], mid+1, r);
    t[index] = 0;
}

void toggle(int index, int l, int r, int pos){
    if(l > pos || r < pos){
        return;
    }
    if(l == r){
        t[index] = 1-t[index];
        return;
    }
    int mid=(l+r)/2;
    toggle(2*index, l, mid, pos);
    toggle(2*index+1, mid+1, r, pos);
    t[index] = t[2*index] + t[2*index+1];
}

int query(int index, int l, int r, int lq, int rq){
    if(l > rq || lq > r){
        return 0;
    }
    if(lq <= l && r <= rq){
        return t[index];
    }
    int mid=(l+r)/2;
    return (query(2*index, l, mid, lq, rq)+query(2*index+1, mid+1, r, lq, rq));
}

void solve()
{
    compressed_coordinates c;
    c.clear();
    c.add(-mod*mod);
    c.add(mod*mod);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        c.add(a[i]);
    }
    c.initialise();
    build(1, 0, 100000);
    cin>>q;
    while(q--){
        int ch;
        cin>>ch;
        if(ch == 1){                        // toggle point
            int x;
            cin>>x;
            toggle(1, 0, 100000, c.compval[a[x]]);
        }else{                              // get number of values less than or equal to y
            int y;
            cin>>y;
            auto it=c.compval.upper_bound(y);
            it--;
            // cout<<it->first<<" "<<it->second<<endl<<endl;
            int ans=query(1, 0, 100000, 0, it->second);
            cout<<y<<" "<<ans<<endl;
        }
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