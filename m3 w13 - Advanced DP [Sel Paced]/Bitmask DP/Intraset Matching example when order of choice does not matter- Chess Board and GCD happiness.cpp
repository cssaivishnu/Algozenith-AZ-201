#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

// 2n players, n chessboards
// make n pairs of players and assign them n boards
// A[1..2n] is the happiness valu of ith player
// happiness of assigning i,j players to kth board is abs(A[i]-A[j])*gcd(A[i],A[j])
// we can see that here order of players choosen for boards does not matter

int n, one=1;

int gcd(int i, int j){
    if(i == 0 || j == 0){
        return i^j;
    }
    return gcd(j, i%j);
}

int rec(int board, int mask, vi &a, vi &dp){
    if(board == n){
        return 0;
    }
    if(dp[mask] != -1){
        return dp[mask];
    }
    int ans = 0, ii, jj;
    for(int i=0; i<2*n; i++){
        if((mask&(one<<i)) == 0){
            for(int j=i+1; j<2*n; j++){
                if((mask&(one<<j)) == 0){
                    ans = max(ans, abs(a[i]-a[j])*gcd(a[i],a[j])+rec(board+1, mask|(one<<i)|(one<<j), a, dp));
                }
            }
            break;
        }
    }
    return dp[mask] = ans;
}

void solve()
{
    cin>>n;
    vi a(2*n);
    for(int i=0; i<2*n; i++){
        cin>>a[i];
    }
    vi dp((one<<(2*n)), -1);
    int ans = rec(0, 0, a, dp);
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