#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, a[2021], dp[2021][2021];
bool done[2021][2021];

int rec(int l, int r){
    if(l == r){
        return a[l];
    }

    if(done[l][r]){
        return dp[l][r];
    }
    
    int ans=a[l]-rec(l+1,r);
    ans = max(ans,a[r]-rec(l,r-1));
    done[l][r] = 1;
    return dp[l][r] = ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            done[i][j] = 0;
        }
    }
    cout<<rec(0,n-1)<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}