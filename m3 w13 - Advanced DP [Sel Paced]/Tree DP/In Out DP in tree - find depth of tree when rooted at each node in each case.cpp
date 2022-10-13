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
vi indp, outdp, dp;

void indfs(int node, int p){
    indp[node] = 0;
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        indfs(neigh, node);
        indp[node] = max(indp[node], 1+indp[neigh]);
    }
}

void outdfs(int node, int p, int outval){
    outdp[node] = outval;
    int max1=-1, max2=-1;
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        if(indp[neigh] > max1){
            max2 = max1;
            max1 = indp[neigh];
        }else if(indp[neigh] > max2){
            max2 = indp[neigh];
        }
    }
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        if(indp[neigh] == max1){
            int outval = max(1+outdp[node], 2+max2);
            outdfs(neigh, node, outval);
        }else{
            int outval = max(1+outdp[node], 2+max1);
            outdfs(neigh, node, outval);
        }
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
    indp = vi(n+1);
    outdp = vi(n+1);
    indfs(1, 0);
    outdfs(1, 0, 0);
    dp = vi(n+1);
    for(int i=1; i<=n; i++){
        dp[i] = max(indp[i],outdp[i]);
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