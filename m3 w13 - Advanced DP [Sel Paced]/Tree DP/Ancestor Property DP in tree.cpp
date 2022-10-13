#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

// tree with n nodes, and a value m are given
// u can assign every node with a value from range [1,m]
// number of ways to assign such that every path from root to leaf has gcd 1

int n, m;
vvi g, dp;

int gcd(int a, int b){
    if(a == 0 || b == 0){
        return a^b;
    }
    return gcd(b, a%b);
}

int dfs(int node, int p, int gc){
    if(dp[node][gc] != -1){
        return dp[node][gc];
    }
    int ans = 0;
    for(int i=1; i<=m; i++){
        int numchild = 0;
        int temp = 1;
        for(auto neigh:g[node]){
            if(neigh == p)  continue;
            numchild++;
            temp *= dfs(neigh, node, gcd(gc,i));
        }
        if(numchild == 0){
            if(gcd(i,gc) == 1){
                ans += 1;
            }
        }else{
            ans += temp;
        }
    }
    return dp[node][gc] = ans;
}

void solve()
{
    cin>>n>>m;
    g = vvi(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp = vvi(n+1, vi(m+1,-1));
    int ans = dfs(1, 0, 0);
    cout<<ans<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}