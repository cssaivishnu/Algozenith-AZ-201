#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long
#define ld long double

ld eps = 0.000000001;

lli check(lli a[], lli b[], lli n, ld x, lli k){
    lli i;
    priority_queue<ld,vector<ld>,greater<ld>> pq;
    for(i=0; i<n; i++){
        pq.push(a[i]-x*b[i]);
        if(pq.size() > k)
            pq.pop();
    }
    ld sum=0.0;
    while(pq.size()){
        sum += pq.top();
        pq.pop();
    }
    if(sum >= 0.0)
        return 1;
    return 0;
}

void solve()
{
    lli i, n, k;
    cin>>n>>k;
    lli a[n], b[n];
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    for(i=0; i<n; i++){
        cin>>b[i];
    }
    ld lo, hi, mid, ans;
    lo = 0.0;
    hi = 100000000.0;
    while(abs(hi-lo) > eps){
        mid = (lo + hi)/2.0;
        if(check(a,b,n,mid,k) == 1){
            ans = mid;
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}


// 3
// 3 2
// 10 9 7
// 3 5 4
// 8 3
// 4 4 2 1 5 3 2 5
// 2 2 2 5 3 5 2 3
// 1 1
// 1 
// 1

// 2.428571
// 1.857143
// 1.000000