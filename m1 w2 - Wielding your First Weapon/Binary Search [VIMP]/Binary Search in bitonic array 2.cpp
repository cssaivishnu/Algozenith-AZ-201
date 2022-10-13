#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

bool check(lli a[], lli i){
    if(i == 0)
        return 1;
    return (a[i] > a[i-1]);
}

lli check1(lli a[], lli mid, lli k){
    if(a[mid] <= k)
        return 1;
    return 0;
}

lli check2(lli a[], lli mid, lli k){
    if(a[mid] >= k)
        return 1;
    return 0;
}

void solve()
{
    lli i, n, q, k, ans1;
    cin>>n>>q;
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
    while(q--){
        lli mid;
        cin>>k;
        lo = 0;
        hi = ans-1;
        ans1 = -1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(check1(a,mid,k) == 1){
                ans1 = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        if(ans1 != -1){
            if(a[ans1] == k){
                cout<<ans1+1<<" ";
            }
        }
        lo = ans;
        hi = n-1;
        ans1 = -1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(check2(a,mid,k) == 1){
                ans1 = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        if(ans1 != -1){
            if(a[ans1] == k){
                cout<<ans1+1<<" ";
            }
        }
        cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}


// 1
// 6 4
// 1 2 5 3 2 1
// 1
// 2
// 5
// 3

// 1 6
// 2 5
// 3
// 4