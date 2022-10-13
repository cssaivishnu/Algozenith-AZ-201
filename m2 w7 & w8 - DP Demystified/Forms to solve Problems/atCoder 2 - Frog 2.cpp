#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, k;
int h[100100], dp[100100];

int rec(int level){
    if(level == 0){
        return 0;
    }
    if(dp[level] != -1){
        return dp[level];
    }
    int ans;
    ans = rec(level-1) + abs(h[level]-h[level-1]);
    for(int i=2; i<=k; i++){
        if(level >= i)
        ans = min(ans, rec(level-i) + abs(h[level]-h[level-i]));
    }
    return dp[level] = ans;
}

void solve()
{
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    for(int i=0; i<n; i++){
        dp[i] = -1;
    }
    cout<<rec(n-1)<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}