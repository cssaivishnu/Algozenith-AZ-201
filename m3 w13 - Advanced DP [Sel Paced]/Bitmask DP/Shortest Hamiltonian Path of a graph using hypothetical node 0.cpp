#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvp vector<vector<pii>>
int mod=1e9+7;

// introduce 0 as an hypothetical node
// add edges from 0 to every node i with weight 0
// then we get shortest hamiltonian path of whole graph

int n, m, sn, en, one=1;
vvp g;

int dfs(int node, int p, int mask, vvi &dp){
    if(mask == (one<<(n+1))-1){
        return 0;
    }
    if(dp[node][mask] != -1){
        return dp[node][mask];
    }
    int ans = 1e18;
    for(auto x:g[node]){
        int neigh = x.first;
        if(neigh == p){
            continue;
        }
        int w = x.second;
        if((mask>>neigh)&1){
        }else{
            ans = min(ans, w+dfs(neigh, node, mask|(one<<neigh), dp));
// if(node == 0){
//     cout<<node<<' '<<(w+dfs(neigh, node, mask|(one<<(neigh-1)), dp))<<' '<<w<<endl;
// }
        }
    }
    return dp[node][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    g = vvp(n+1);
    for(int i=0; i<m; i++){
        int u, v, w=1;
        cin>>u>>v>>w;
        // cin>>u>>v;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1; i<=n; i++){
        g[0].push_back({i,0});
        g[i].push_back({0,0});
    }
    vvi dp(n+1, vi(one<<(n+1), -1));
    int ans = dfs(0, -1, 1, dp);
    if(ans == 1e18){
        cout<<"No Hamiltonian Path"<<endl;
    }else{
        cout<<"Length of shortest Hamiltonian Path = "<<ans;
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