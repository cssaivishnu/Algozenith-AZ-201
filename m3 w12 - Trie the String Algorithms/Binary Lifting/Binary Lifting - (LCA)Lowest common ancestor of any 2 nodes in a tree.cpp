#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n, root;

void dfs(int node, int p, int d, vvi &g, vvi &par, vi &depth){
    depth[node] = d;
    par[node][0] = p;
    for(int i=1; i<20; i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        dfs(neigh, node, d+1, g, par, depth);
    }
}

int lca(int u, int v, vi &depth, vvi &par, vvi &g){
    int dif=depth[v]-depth[u];
    for(int i=19; i>=0; i--){
        if((dif>>i)&1){
            v = par[v][i];
        }
    }
    if(u == v){
        return u;
    }
    for(int i=19; i>=0; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
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
    cin>>root;
    vi depth(n+1);
    vvi par(n+1, vi(20));
    dfs(root, 0, 0, g, par, depth);
    int q;
    cin>>q;
    while(q--){
        int u, v;
        cin>>u>>v;
        if(depth[u] > depth[v]){
            swap(u,v);
        }
        cout<<lca(u,v,depth,par,g)<<endl;
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