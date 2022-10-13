#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n;
vvi g;
vi depth, par, sts, indp, outdp, dp;

void indfs(int node, int p, int d){
    depth[node] = d;
    par[node] = p;
    sts[node] = 1;
    indp[node] = 0;
    for(auto neigh:g[node]){
        if(neigh == p)    continue;
        indfs(neigh, node, d+1);
        sts[node] += sts[neigh];
        indp[node] += indp[neigh] + sts[neigh];
    }
}

void outdfs(int node, int p){
    if(node == 1){
        outdp[node] = 0;
    }else{
        outdp[node] = (outdp[p]+indp[p]) + (n-2*sts[node]) - indp[node];
    }
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        outdfs(neigh, node);
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
    depth = vi(n+1);
    par = vi(n+1);
    sts = vi(n+1);
    indp = vi(n+1);
    outdp = vi(n+1);
    indfs(1, 0, 0);
    outdfs(1, 0);
    for(int i=1; i<=n; i++){
        cout<<sts[i]<<' ';
    }cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<indp[i]<<' ';
    }cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<outdp[i]<<' ';
    }cout<<endl;
    dp = vi(n+1);
    dp[0] = 0;
    cout<<"Final array of distances"<<endl;
    for(int i=1; i<=n; i++){
        dp[i] = indp[i] + outdp[i];
        cout<<dp[i]<<' ';
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