#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

// count number of n length strings with 0,1 characters and should not contain '0100'
// substring           (use state diagram - automata)

int n, dp[100100][4];

int rec(int level, int state){
    if(level == n){
        return 1;
    }
    if(dp[level][state] != -1){
        return dp[level][state];
    }
    int ans;
    if(state == 0){
        ans = rec(level+1,1) + rec(level+1,0);
    }else if(state == 1){
        ans = rec(level+1,1) + rec(level+1,2);
    }else if(state == 2){
        ans = rec(level+1,0) + rec(level+1,3);
    }else if(state == 3){
        ans = rec(level+1,2);
    }
    return dp[level][state] = ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<=n; i++){
        for(int j=0; j<4; j++){
            dp[i][j] = -1;
        }
    }
    int ans=rec(0,0);
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