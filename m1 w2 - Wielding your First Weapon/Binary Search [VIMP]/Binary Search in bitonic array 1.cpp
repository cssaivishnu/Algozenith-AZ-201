#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

bool check(lli a[], lli i){
    if(i == 0)
        return 1;
    return (a[i] > a[i-1]);
}

void solve()
{
    lli i, n;
    cin>>n;
    lli a[n];
    for(i=0; i<n; i++){             // input is bitonic array  -> '/\'
        cin>>a[i];
    }
    lli ans=-1, lo=0, hi=n-1;
    while(lo <= hi){
        lli mid = (lo+hi)/2;        // lo + (hi-lo)/2
        if(check(a,mid) == 1){
            lo = mid + 1;
            ans = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}