#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

int n;
int b, k;
int p[100100];
int h[100100];

int dp[101][1001][101];

int rec(int level, int totcost, int cursize){
    // pruning

    // base case code
    if(level == n){
        return 0;
    }

    // cache check
    if(dp[level][totcost][cursize] != -1){
        return dp[level][totcost][cursize];
    }

    // transitions
    int ans = rec(level+1,totcost,cursize);
    if(totcost+p[level] <= b  &&  cursize+1 <= k){
        ans = max(ans,rec(level+1,totcost+p[level],cursize+1)+h[level]);
    }

    // save and return
    dp[level][totcost][cursize] = ans;
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>p[i]>>h[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}