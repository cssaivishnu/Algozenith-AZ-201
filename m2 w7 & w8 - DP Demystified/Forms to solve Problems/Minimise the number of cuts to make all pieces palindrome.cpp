#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

string s;
int n, dp1[1010][1010], dp[1010];

int rec1(int l, int r){
    if(l == r){
        return dp1[l][r] = 1;
    }
    if(dp1[l][r] != -1){
        return dp1[l][r];
    }
    if(r == l+1){
        return dp1[l][r] = 1;
    }
    int ans;
    ans = rec1(l+1,r-1) && (s[l]==s[r]);
    return dp1[l][r] = ans;
}

int rec(int level){
    if(dp[level] != -1){
        return dp[level];
    }
    int ans;
    if(level >= 1){
        ans = rec(level-1) + 1;
    }
    for(int j=level-2; j>=0; j--){
        if(rec1(j+1,level)){
            ans = min(ans,rec(j)+1);
        }
    }
    if(rec1(0,level)){
        ans = 0;
    }
    return dp[level] = ans;
}

void solve()
{
    cin>>s;
    n = s.length();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp1[i][j] = -1;
        }
    }
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    cout<<rec(n-1)<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}