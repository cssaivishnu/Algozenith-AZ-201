#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

lli check(lli a[], lli x, lli n, lli k){
    // can maximum of distances between neighbours be <= x, when we are allowed to add k more points
    lli i, d;
    for(i=0; i<n-1; i++){
        d = a[i+1] - a[i];
        k -= ((d+x-1)/x - 1);
        if(k < 0)
            return 0;
    }
    return 1;
}

void solve()
{
    lli i, n, k, lo, hi, mid, ans;
    cin>>n>>k;
    lli a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    lo = 1;
    hi = 0;
    for(i=1; i<n; i++){
        hi = max(hi,a[i]-a[i-1]);
    }
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(a,mid,n,k) == 1){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}


// 5
// 5 5
// 1 2 3 4 5
// 5 0
// 2 5 7 8 10
// 3 2
// 100 200 230
// 6 5
// 1 3 5 7 9 11
// 6 4
// 1 4 8 13 19 26

// 1
// 3
// 34
// 1
// 4