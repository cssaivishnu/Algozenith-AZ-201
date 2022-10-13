#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
int mod=1e9+7;

// given a tree with n nodes and each node has value val[1..n]
// we need to select k non neighbouring nodes such that sum of values at those k nodes is maximum

int n, k;
vvi g, child;
vi leaf, val;
vvvi dp;

void dfsleaf(int node, int p){
    leaf[node] = 1;
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        child[node].push_back(neigh);
        leaf[node] = 0;
        dfsleaf(neigh, node);
    }
}

int rec(int node, int p, int taken, int x);

int rec1(int level, int x, int node, int taken, vvi &dp1){
    if(dp1[level][x] != -1){
        return dp1[level][x];
    }
    if(level == child[node].size()){
        if(x == 0)  return 0;
        return -1e9;
    }
    int ans = -1e9;
    for(int i=0; i<=x; i++){
        if(taken == 1){
            ans = max(ans, rec(child[node][i],node,0,i)+rec1(level+1,x-i,node,taken,dp1));
        }else{
            ans = max(ans, max(rec(child[node][i],node,0,i),rec(child[node][i],node,1,i))+rec1(level+1,x-i,node,taken,dp1));
        }
    }
    return dp1[level][x] = ans;
}

int rec(int node, int p, int taken, int x){
    if(dp[node][taken][x] != -1){
        return dp[node][taken][x];
    }
    if(leaf[node] == 1){
        if(taken == 1){
            dp[node][taken][x] = (x==1?val[node]:-1e9);
        }else{
            dp[node][taken][x] = (x==0?0:-1e9);
        }
        return dp[node][taken][x];
    }
    int ans;
    vvi dp1;
    dp1 = vvi(child[node].size()+1, vi(x+1,-1));
    ans = rec1(0,x-taken,node,taken,dp1);
    return dp[node][taken][x] = ans;
}

void solve()
{
    cin>>n>>k;
    g = vvi(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    val = vi(n+1);
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }
    leaf = vi(n+1);
    child = vvi(n+1);
    dfsleaf(1, 0);
    dp = vvvi(n+1, vvi(2, vi(k+1, -1)));
    int ans = max(rec(1, 0, 1, k),rec(1, 0, 0, k));
    cout<<ans<<' '<<rec(1,0,0,k)<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}