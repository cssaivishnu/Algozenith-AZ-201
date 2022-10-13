#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n;
vvi g, par, gcd;
vi depth, val;

int findgcd(int u, int v){
    if(u == 0 || v == 0){
        return u+v;
    }
    if(u == 1 || v == 1){
        return 1;
    }
    if(u > v){
        return findgcd(u%v, v);
    }
    return findgcd(u, v%u);
}

void dfs(int node, int p, int d){
    depth[node] = d;
    par[node][0] = p;
    gcd[node][0] = val[node];
    for(int i=1; i<20; i++){
        par[node][i] = par[par[node][i-1]][i-1];
        gcd[node][i] = findgcd(gcd[node][i-1],gcd[par[node][i-1]][i-1]);
    }
    for(auto neigh:g[node]){
        if(neigh == p)	continue;
        dfs(neigh, node, d+1);
    }
}

int getgcd(int u, int v){
    if(depth[u] > depth[v]){
        swap(u,v);
    }
    int ans = 0;
    int dif=depth[v]-depth[u];
    for(int i=19; i>=0; i--){
        if((dif>>i)&1){
            ans = findgcd(ans, gcd[v][i]);
            v = par[v][i];
        }
    }
    if(u == v){
        ans = findgcd(ans, val[u]);
        return ans;
    }
    for(int i=19; i>=0; i--){
        if(par[u][i] != par[v][i]){
            ans = findgcd(ans, gcd[u][i]);
            u = par[u][i];
            ans = findgcd(ans, gcd[v][i]);
            v = par[v][i];
        }
    }
    ans = findgcd(ans, val[u]);
    u = par[u][0];
    ans = findgcd(ans, val[v]);
    v = par[v][0];
    ans = findgcd(ans, val[u]);
    return ans;
}

void solve()
{
    cin>>n;
    val = vi(n+1);
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }
    g = vvi(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    depth = vi(n+1);
    par = vvi(n+1, vi(20));
    gcd = vvi(n+1, vi(20));
    dfs(1, 0, 0);
    int q;
    cin>>q;
    while(q--){
        int x, y;
        cin>>x>>y;
        cout<<getgcd(x, y)<<endl;
    }
}

#undef int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}