#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

bool check(lli a[], lli i, lli x){
    return (a[i] >= x);
}

void solve()
{
    lli i, n, x;
    cin>>n>>x;                      // need to find lower_bound of x
    lli a[n];
    for(i=0; i<n; i++){             // input is sorted array
        cin>>a[i];
    }
    lli ans=-1, lo=0, hi=n-1;
    while(lo <= hi){
        lli mid = (lo+hi)/2;        // lo + (hi-lo)/2
        if(check(a,mid,x) == 1){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
            ans = mid;
        }
    }
    ans++;
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}