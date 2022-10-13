#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<pii>
int mod=1e9+7;

int n, m;

void dfs(int node, int p, vi &par, vi &intime, vi &lotime, vi &numsplit, int &timer, vvi &g, vi &arti, vp &brdg){
    par[node] = p;
    intime[node] = ++timer;
    lotime[node] = timer;
    numsplit[node] = 1;
    int child = 0;
    int isarti = 0;
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        if(intime[neigh] == 0){
            child++;
            dfs(neigh, node, par, intime, lotime, numsplit, timer, g, arti, brdg);
            lotime[node] = min(lotime[node], lotime[neigh]);
            if(lotime[neigh] >= intime[node]){
                // node is an articulation point
                numsplit[node]++;
                isarti = 1;
            }
            if(lotime[neigh] > intime[node]){
                // node-neigh is a bridge
                brdg.push_back({node,neigh});
            }
        }else{
            lotime[node] = min(lotime[node], intime[neigh]); 
        }
    }
    if((p == 0 && child > 1) || (p != 0 && isarti == 1)){
        arti.push_back(node);
    }
    if(p == 0){
        numsplit[node] = child;
    }
}

void solve()
{
    cin>>n>>m;
    vvi g(n+1);
    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi par(n+1), intime(n+1,0), lotime(n+1,0), numsplit(n+1);
    vi arti;
    vp brdg;
    int timer=0;
    dfs(1, 0, par, intime, lotime, numsplit, timer, g, arti, brdg);
    cout<<"Articulation Points : ";
    for(auto x:arti){
        cout<<x<<" ";
    }cout<<endl;
    cout<<"Bridges : [ ";
    for(auto x:brdg){
        cout<<x.first<<','<<x.second<<' ';
    }cout<<']'<<endl;
    cout<<"Number of Splits : ";
    for(int i=1; i<=n; i++){
        cout<<i<<'-'<<numsplit[i]<<' ';
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