#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

lli sod(lli x){
    lli sum=0;
    while(x){
        sum += x%10;
        x /= 10;
    }
    return sum;
}

lli check(lli x, lli k){
    if(x-sod(x) >= k)
        return 1;
    return 0;
}

void solve()
{
    lli n, s, i, lo, hi, mid, ans;
    cin>>n>>s;
    lo = 1;
    hi = n;
    ans = n+1;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(mid,s) == 1){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout<<n+1-ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}


// 10
// 5 4
// 100 5
// 20 3
// 40 19
// 32 15
// 69 12
// 1000000000000000 0
// 1000000000000000000 10000000
// 9999999999999 9999999999882
// 13465751690089037 981448507916936

// 0
// 91
// 11
// 11
// 13
// 50
// 1000000000000000
// 999999999989999991
// 10
// 12484303182172038