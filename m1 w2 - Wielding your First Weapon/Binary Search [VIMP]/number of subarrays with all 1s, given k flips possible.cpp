#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

// nummber of subarrays with all 1s when we can make k flips

lli check(lli p[], lli i, lli x, lli k){
    if(p[x]-p[i-1] <= k)
        return 1;
    return 0;
}

void solve()
{
    lli i, n, k, lo, hi, mid, ans;
    cin>>n>>k;
    lli a[n+1], p[n+1];
    p[0] = 0;
    for(i=1; i<=n; i++){
        cin>>a[i];
        p[i] = p[i-1];
        if(a[i] == 0){
            p[i]++;
        }
    }
    // for(i=1; i<=n; i++){
    //     cout<<p[i];
    // }
    lli sum=0;
    for(i=1; i<=n; i++){
        lo = i;
        hi = n;
        ans = i-1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(check(p,i,mid,k) == 1){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        sum += ans-i+1;
    }
    cout<<sum<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}