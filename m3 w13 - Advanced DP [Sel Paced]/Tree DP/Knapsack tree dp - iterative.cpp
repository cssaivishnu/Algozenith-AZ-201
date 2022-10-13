#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
int mod=1e9+7;

// given a tree with n nodes and each node has value val[1..n]
// we need to select k non neighbouring nodes such that sum of values at 
// those k nodes is maximum

int n, k;
vvi g;
vi val, sz;
vvvi dp;

void dfs(int node, int p){
    for(int i=0; i<=n; i++){
        dp[node][0][i] = (i==0?0:-1e18);
        dp[node][1][i] = (i==1?val[node]:-1e18);
    }
    sz[node] = 1;
    for(auto neigh:g[node]){
        if(neigh == p){
            continue;
        }
        dfs(neigh, node);
        for(int a=sz[node]; a>=0; a--){
            for(int b=sz[neigh]; b>=0; b--){
                dp[node][0][a+b] = max(dp[node][0][a+b],dp[node][0][a]+max(dp[neigh][0][b],dp[neigh][1][b]));
                dp[node][1][a+b] = max(dp[node][1][a+b],dp[node][1][a]+dp[neigh][0][b]);
            }
        }
        sz[node] += sz[neigh];
    }
}

void solve()
{
    cin>>n>>k;
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
    sz = vi(n+1);
    dp = vvvi(n+1, vvi(2, vi(k+1)));
    dfs(1, 0);
    cout<<max(dp[1][0][k],dp[1][1][k]);
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}