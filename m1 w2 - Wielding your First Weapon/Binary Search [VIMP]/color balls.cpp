#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

lli check(unordered_map<lli,lli> mp, lli x, lli n, lli k){
    lli sum = 0;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(it->second >= x){
            sum += x;
        }
        else{
            sum += it->second;
        }
    }
    if(sum >= x*k)
        return 1;
    return 0;
}

void solve()
{
    lli i, n, k, lo, hi, mid, ans;
    cin>>n>>k;
    unordered_map<lli,lli> mp;
    for(i=1; i<=n; i++){
        cin>>ans;
        mp[ans]++;
    }
    lo = 0;
    hi = n/k;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(check(mp,mid,n,k) == 1){
            ans = mid;
            lo = mid + 1;
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

    int _t; cin>>_t; while(_t--)
    solve();
}


// 3
// 5 5
// 1 2 3 4 5
// 5 2
// 1 2 3 4 5
// 6 3
// 1 2 2 1 3 3

// 1
// 2
// 2