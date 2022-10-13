#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n, one=1;
vvi edge;
vi dp;

int rec(int pos, int mask){
    if(pos == n){
        return 0;
    }
    if(dp[mask] != -1){
        return dp[mask];
    }
    int ans = 1e18;
    for(int i=0; i<n; i++){
        if(((one<<i)&mask) == 0){
            int temp = 0;
            for(int j=0; j<n; j++){
                if((one<<j)&mask){
                    temp += edge[i][j];
                }
            }
            ans = min(ans, temp+rec(pos+1, mask|(one<<i)));
        }
    }
    return dp[mask] = ans;
}

void solve()
{
    cin>>n;
    edge = vvi(n, vi(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>edge[i][j];
        }
    }
    dp = vi((one<<n), -1);
    int ans = rec(0, 0);
    cout<<ans<<endl;
}

#undef int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}