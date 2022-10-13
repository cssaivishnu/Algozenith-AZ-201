#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvp vector<vector<pii>>
int mod=1e9+7;

int n, root;
vi prefix, depth;
vvi par;
vvp g;

void dfs(int node, int p, int d){
    depth[node] = d;
    par[node][0] = p;
    for(int i=1; i<20; i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }
    for(auto x:g[node]){
        int neigh = x.first;
        if(neigh == p)  continue;
        int val = x.second;
        prefix[neigh] = prefix[node] + val;
        dfs(neigh, node, d+1);
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){
        swap(u,v);
    }
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
    u = par[u][0];
    v = par[v][0];
    return u;
}

int getsum(int u, int v){
    return (prefix[u] + prefix[v] - 2*prefix[lca(u,v)]);
}

void solve()
{
    cin>>n>>root;
    g = vvp(n+1);
    for(int i=0; i<n-1; i++){
        int u, v, val;
        cin>>u>>v>>val;
        g[u].push_back({v,val});
        g[v].push_back({u,val});
    }
    depth = vi(n+1,0);
    par = vvi(n+1, vi(20,0));
    prefix = vi(n+1,0);
    dfs(root, 0, 0);
    for(int i=0; i<=n; i++){
        cout<<i<<' '<<prefix[i]<<endl;
    }cout<<endl;
    int q;
    cin>>q;
    while(q--){
        int u, v;
        cin>>u>>v;
        cout<<'('<<u<<','<<v<<')'<<" = "<<getsum(u,v)<<endl;
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