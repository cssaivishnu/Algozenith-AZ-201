#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

string s;
int n;

void solve()
{
    cin>>s;
    n = s.length();
    int dp[n+1], sum[n+1], last[26];
    memset(last,0,sizeof(last));
    dp[0] = 1;
    sum[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = sum[i-1];
        if(last[s[i-1]-'a'] > 0){
            dp[i] -= sum[last[s[i-1]-'a']-1];
        }
        sum[i] = sum[i-1] + dp[i];
        last[s[i-1]-'a'] = i;
    }
    cout<<sum[n]<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}