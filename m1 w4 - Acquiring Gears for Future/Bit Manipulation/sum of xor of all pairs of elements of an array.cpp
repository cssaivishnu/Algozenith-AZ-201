#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli i, n, j;
    cin>>n;
    lli a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    lli ans=0;
    for(i=0; i<31; i++){
        lli c1=0,c0=0;
        for(j=0; j<n; j++){
            if((a[j]>>i)&1) c1++;
            else    c0++;
        }
        lli numPairs = c0*c1;
        ans += (1<<i)*numPairs;
    }
    cout<<ans<<endl;
}

// 0 0 1
// 0 1 0
// 0 1 1
// 1 0 0
// 1 0 1
// 6 6 6 -> 6+6*2+6*4=42

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}