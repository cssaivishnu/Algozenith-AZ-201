#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

int n, D, a[100100], cnt, t[400400];
map<int,int> compval;

void initialise(){
    int x=0;
    for(auto &v:compval){
        v.second = x++;
    }
}

void build(int index, int l, int r){
    if(l == r){
        t[index] = 0;
        return;
    }
    int mid=(l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    t[index] = 0;
}

void update(int index, int l, int r, int pos, int val){
    if(l > pos || r < pos){
        return;
    }
    if(l == r){
        t[index] = max(t[index], val);
        return;
    }
    int mid=(l+r)/2;
    update(2*index, l, mid, pos, val);
    update(2*index+1, mid+1, r, pos, val);
    t[index] = max(t[2*index], t[2*index+1]);
}

int query(int index, int l, int r, int lq, int rq){
    if(l > rq || lq > r){
        return 0;
    }
    if(lq <= l && r <= rq){
        return t[index];
    }
    int mid=(l+r)/2;
    return max(query(index<<1, l, mid, lq, rq), query(index<<1|1, mid+1, r, lq, rq));
}

void solve()
{
    compval.clear();
    cnt=2;
    cin>>n;
    compval[-mod*mod];
    compval[mod*mod];
    for(int i=0; i<n; i++){
        cin>>a[i];
        compval[a[i]];
        cnt++;
    }
    cin>>D;
    initialise();
    build(1, 0, cnt-1);
    int ans=0;
    int dp[n+5];
    for(int i=0; i<n; i++){
        int hi, lo;
        lo = a[i] - D;
        hi = a[i] + D;
        auto it = compval.upper_bound(hi);
        it--; hi = it->second;
        it = compval.lower_bound(lo);
        lo = it->second;
        dp[i] = query(1, 0, cnt-1, lo, hi)+1;
        ans = max(ans, dp[i]);
        update(1, 0, cnt-1, compval[a[i]], dp[i]);
    }
    cout<<ans<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}