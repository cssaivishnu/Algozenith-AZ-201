#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
int mod=1e9+7;

// tree with n nodes and value at each node val[1..n] is given
// we can choose any number of nodes but no neighbouring nodes are selected
// sum of values at selected nodes need to be maximised

int n;
vi val;
vvi g, dp;

int dfs(int node, int p){
    dp[node][0] = 0;
    dp[node][1] = val[node];
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        dfs(neigh, node);
        dp[node][0] += max(dp[neigh][0],dp[neigh][1]);
        dp[node][1] += dp[neigh][0];
    }
}

void solve()
{
    cin>>n;
    g = vvi(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    val = vi(n+1);
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }
    dp = vvi(n+1, vi(2,-1));
    dfs(1, 0);
    int ans = max(dp[1][0],dp[1][1]);
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