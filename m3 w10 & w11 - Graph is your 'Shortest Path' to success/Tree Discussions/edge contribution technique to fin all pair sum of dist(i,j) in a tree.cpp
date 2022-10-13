#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n;

void dfs(int node, int p, int d, vvi &g, vi &par, vi &depth, vi &sts){
    par[node] = p;
    depth[node] = d;
    sts[node] = 1;
    for(auto neigh:g[node]){
        if(neigh == p)	continue;
        dfs(neigh, node, d+1, g, par, depth, sts);
        sts[node] += sts[neigh];
    }
}

void solve()
{
    cin>>n;
    if(n == 1){
        cout<<0<<endl;
        return;
    }
    vvi g(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi par(n+1), depth(n+1), sts(n+1);
    dfs(1, 0, 0, g, par, depth, sts);
    int ans=0;
    for(int i=1; i<=n; i++){
        ans += sts[i]*(n-sts[i]);
    }
    cout<<ans<<endl;
}

#undef int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}