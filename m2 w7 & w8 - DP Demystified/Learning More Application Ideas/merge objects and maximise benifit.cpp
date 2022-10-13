#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define int_min (-1e9)

// n objects are given, u can merge any 2 neighbouring objects, benifit gaained by merging
// objects x and y is x*y, the merged node becomes (x+y)%100, maximise total benifit gained
// by doing n-1 optimal merges        [use lr dp]
int n, a[505], dp[505][505];

int rec(int l, int r){
    if(l == r){
        return 0;
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    int ans = int_min;
    int sum=0, x=0;
    for(int mid=l; mid<=r; mid++){
        sum += a[mid];
        sum %= 100;
    }
    for(int mid=l; mid<r; mid++){
        x += a[mid];
        x %= 100;
        int y = sum-x;
        y %= 100;
        ans = max(ans,rec(l,mid)+rec(mid+1,r)+x*y);
    }
    dp[l][r] = ans;
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = -1;
        }
    }
    int ans=rec(0,n-1);
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