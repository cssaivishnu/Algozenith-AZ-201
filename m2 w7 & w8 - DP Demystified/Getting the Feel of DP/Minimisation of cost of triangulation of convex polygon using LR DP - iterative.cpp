#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, x[101], y[101], dp[101][101];

int sq(int l){
    return l*l;
}

int dist(int l, int r){
    return sq(x[l]-x[r]) + sq(y[l]-y[r]);
}

int rec(int l, int r){
    if(r-l < 3){
        return 0;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    int ans;
    ans = dist(l+1,r) + rec(l+1,r);
    ans = min(ans,dist(l,r-1)+rec(l,r-1));
    for(int x=l+2; x<=r-2; x++){
        ans = min(ans,(dist(l,x)+dist(x,r)+rec(l,x)+rec(x,r)));
    }
    return dp[l][r] = ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = -1;
        }
    }
    for(int len=1; len<=n; len++){
        for(int l=0; l<n-len+1; l++){
            int r = l + len - 1;
            if(r-l < 3){
                dp[l][r] = 0;
                continue;
            }
            int ans;
            ans = dist(l+1,r) + dp[l+1][r];
            ans = min(ans,dist(l,r-1)+dp[l][r-1]);
            for(int x=l+2; x<=r-2; x++){
                ans = min(ans,(dist(l,x)+dist(x,r)+dp[l][x]+dp[x][r]));
            }
            dp[l][r] = ans;
        }
    }
    cout<<dp[0][n-1]<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}