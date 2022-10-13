#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

lli check(lli p1[], lli p2[], lli n, lli x, lli k){
// number of elements <= mid is >= k
    lli i, j, sum=0;
    j=n;
    for(i=0; i<=n; i++){
        lli temp = x - p1[i];
        while(j>-1){
            if(p2[j] > temp){
                j--;
            }
            else{
                break;
            }
        }
        sum += j+1;
    }
    if(sum >= k)
        return 1;
    return 0;
}

void solve()
{
    lli n, i, lo, hi, mid, ans;
    cin>>n;
    lli a[n+1], p1[n+1], p2[n+1];
    a[0] = 0;
    p1[0] = 0;
    for(i=1; i<=n; i++){
        cin>>a[i];
        p1[i] = p1[i-1] + a[i];
    }
    for(i=0; i<=n; i++){
        p2[i] = -p1[n-i];
    }
    lo = p1[0] + p2[0];
    hi = p1[n] + p2[n];
    lli k, lo_=lo, hi_=hi;
    k = (n*(n+1))/4 + ((n+2)*(n+1))/2;
    k++;
    lli z=3;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(p1,p2,n,mid,k) == 1){
            hi = mid - 1;
            ans = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    if(((n*(n+1))/2)%2 == 1){
        cout<<ans<<endl;
        return;
    }
    lo = lo_;
    hi = hi_;
    k--;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(p1,p2,n,mid,k) == 1){
            hi = mid - 1;
            ans = mid;
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
// 3
// 1 2 3
// 1
// 5
// 2
// 1 5
// 10
// 1 2 2 3 3 4 5 4 6 7
// 15
// 100 222 333 511 555 232 444 555 777 888 999 1000 1112 12345 123456

// 3
// 5
// 5
// 13
// 3629