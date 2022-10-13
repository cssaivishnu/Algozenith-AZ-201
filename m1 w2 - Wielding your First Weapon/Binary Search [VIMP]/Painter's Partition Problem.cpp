#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

lli check(lli a[], lli x, lli n, lli k){
    lli needed, left, i;
    needed = 1;
    left = x;
    for(i=0; i<n; i++){
        if(left >= a[i]){
            left -= a[i];
        }
        else{
            needed++;
            left = x - a[i];
        }
        if(needed > k){
            return 0;
        }
    }
    return 1;
}

void solve()
{
    lli i, n, k, lo, hi, ans;
    cin>>n>>k;
    lli a[n];
    lo = 0;
    hi = 0;
    for(i=0; i<n; i++){
        cin>>a[i];
        lo = max(lo,a[i]);
        hi += a[i];
    }
    while(lo <= hi){
        lli mid=(lo+hi)/2;
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