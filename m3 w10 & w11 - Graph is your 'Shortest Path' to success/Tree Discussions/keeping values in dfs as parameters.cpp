#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

// val[i] is the value at node i
// ans[i] is the max(abs(val[i] - val[j])) where j is ancestor of i
// ans[1] is 0 since it has no ancestors
// we use 2 values named minval, maxval in dfs tree

int n;

void dfs(int node, int p, vi &val, vvi &g, int minval, int maxval, vi &ans){
    ans[node] = max(abs(val[node] - minval), abs(val[node] - maxval));
    minval = min(minval, val[node]);
    maxval = max(maxval, val[node]);
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        dfs(neigh, node, val, g, minval, maxval, ans);
    }
}

void solve()
{
    cin>>n;
    vvi g(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi val(n+1);
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }
    vi ans(n+1);
    dfs(1, 0, val, g, val[1], val[1], ans);
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}