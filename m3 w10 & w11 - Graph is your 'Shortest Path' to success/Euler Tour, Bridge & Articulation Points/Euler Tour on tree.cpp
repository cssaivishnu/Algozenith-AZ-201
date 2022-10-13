#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n;

void dfs(int node, int p, vvi &g, vi &intime, vi &outtime, int &timer){
    intime[node] = ++timer;
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        dfs(neigh, node, g, intime, outtime, timer);
    }
    outtime[node] = ++timer;
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
    vi intime(n+1,0), outtime(n+1,0);
    int timer=0;
    dfs(1, 0, g, intime, outtime, timer);
    int q;
    cin>>q;
    while(q--){
        int u, v;
        cin>>u>>v;
        if(intime[u]<intime[v] && outtime[u]>outtime[v]){
            cout<<u<<" is an ancestor of "<<v<<endl;
        }else{
            cout<<u<<" is not an ancestor of "<<v<<endl;
        }
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