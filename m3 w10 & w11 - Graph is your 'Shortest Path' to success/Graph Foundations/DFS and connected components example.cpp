#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

int n, m, nodeVisited, ncomp;
vector<vector<int>> g;
vector<int> vis, comp;

void dfs(int node){
    nodeVisited++;
    vis[node] = ncomp;
    for(auto x:g[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n+1, 0);
    ncomp=0;
    comp.clear();
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            nodeVisited = 0;
            ncomp++;
            dfs(i);
            comp.push_back(nodeVisited);
        }
    }
    for(auto x:comp){
        cout<<x<<" ";
    }cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<vis[i]<<" ";
    }cout<<endl;
    int pre=0, ans=0;
    for(auto x:comp){
        ans += pre*x;
        pre += x;
    }
    cout<<"number of connected components = "<<ncomp<<endl;
    cout<<"number of unordered pairs (x,y) of nodes such that adding edge between them reduces number of connected components = "<<ans<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}