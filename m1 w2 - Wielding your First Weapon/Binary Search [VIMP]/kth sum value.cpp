#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

lli check(lli a[], lli n, lli b[], lli m, lli x, lli k){
    // check if the number of elements in c[] <= x, are >= k
    // c[] is a[i] + b[j] for all i,j in their respective range
    lli i, j, sum=0;
    j = m-1;
    for(i=0; i<n; i++){
        lli temp = x - a[i];
        while(j>-1){
            if(b[j] > temp){
                j--;
            }
            else{
                break;
            }
        }
        sum += j+1;
    }
    return (sum >= k);
}

void solve()
{
    lli i, j, n, m, k, lo, hi, mid, ans=0;
    cin>>n>>m>>k;
    if(n<m){
        ans = 1;
        m = n + m;
        n = m - n;
        m = m - n;
    }
    lli a[n],b[m];
    if(ans == 1){
        for(i=0; i<m; i++){
            cin>>b[i];
        }
        for(i=0; i<n; i++){
            cin>>a[i];
        }
    }
    else{
        for(i=0; i<n; i++){
            cin>>a[i];
        }
        for(i=0; i<m; i++){
            cin>>b[i];
        }
    }
    sort(a,a+n);
    sort(b,b+m);
    lo = a[0] + b[0];
    hi = a[n-1] + b[m-1];
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(a,n,b,m,mid,k) == 1){
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