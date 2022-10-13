#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n, m, one=1;

// there are m students and n ranks [m > n]
// a student may or maynot get a rank
// happy[i][j] is happiness of student i if he gets j rank
// distruibute ranks to get maximum happiness among students

int rec(int level, int mask, vvi &happy, vvi &dp){
    if(level == m){
        return 0;
    }
    if(dp[level][mask] != -1){
        return dp[level][mask];
    }
    int ans = rec(level+1, mask, happy, dp);
    for(int i=0; i<n; i++){
        if((mask>>i)&1){
        }else{
            ans = max(ans, happy[level][i] + rec(level+1, mask|(one<<i), happy, dp));
        }
    }
    return dp[level][mask] = ans;
}

void solve()
{
    cin>>n>>m;
    vvi happy = vvi(m, vi(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>happy[i][j];
        }           // happy[i][j] is happiness of ith student on getting rank j
    }
    vvi dp(m, vi(one<<n,-1));
    int ans = rec(0, 0, happy, dp);
    cout<<ans<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}