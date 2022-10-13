#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

// Form 3 - Matching / Multisequrnce Form

int n, m, dp[2021][2021];
string s1, s2;

int rec(int level1, int level2){
    // pruning and base case code
    if(level1 == n || level2 == m){
        return 0;
    }

    // cache check
    if(dp[level1][level2] != -1){
        return dp[level1][level2];
    }

    // transitions
    int ans;
    if(s1[level1] == s2[level2]){
        ans = 1 + rec(level1+1,level2+1);
    }else{
        ans = max(rec(level1+1,level2),rec(level1,level2+1));
    }

    // save and return
    dp[level1][level2] = ans;
    return ans;
}

string curSol;

void generate(int level1, int level2){
    if(level1 == n || level2 == m){
        return;
    }
    if(s1[level1] == s2[level2]){
        curSol += s1[level1];
        generate(level1+1,level2+1);
    }else if(rec(level1+1,level2) > rec(level1,level2+1)){
        generate(level1+1,level2);
    }else{
        generate(level1,level2+1);
    }
}

void solve()
{
    cin>>s1>>s2;
    n = s1.length();
    m = s2.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
    if(rec(0,0)){
        curSol = "";
        generate(0,0);
        cout<<curSol<<endl;
    }cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}