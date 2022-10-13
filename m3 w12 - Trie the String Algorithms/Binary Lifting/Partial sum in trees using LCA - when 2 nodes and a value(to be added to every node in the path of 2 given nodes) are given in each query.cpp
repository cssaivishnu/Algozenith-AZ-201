#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n, root;
vi partial, depth;
vvi par;
vvi g;

void dfs(int node, int p, int d){
    depth[node] = d;
    par[node][0] = p;
    for(int i=1; i<20; i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
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

void addpartial(int u, int v, int val){
    int lcauv = lca(u,v);
    partial[u] += val;
    partial[v] += val;
    partial[lcauv] -= val;
    partial[par[lcauv][0]] -= val;
}

void pushall(int node, int p){
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        pushall(neigh, node);
    }
    partial[p] += partial[node];
}

void solve()
{
    cin>>n>>root;
    g = vvi(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    depth = vi(n+1,0);
    par = vvi(n+1, vi(20,0));
    dfs(root, 0, 0);
    partial = vi(n+1,0);
    int q;
    cin>>q;
    while(q--){
        int u, v, val;
        cin>>u>>v>>val;
        addpartial(u, v, val);
    }
    pushall(root, 0);
    for(int i=0; i<=n; i++){
        cout<<i<<' '<<partial[i]<<endl;
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