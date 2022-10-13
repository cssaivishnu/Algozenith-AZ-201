#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli i, n, q, j, budget;
    cin>>n>>q;
    vector<lli> v(n), prefixsum(n);
    for(i=0; i<n; i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    prefixsum[0] = v[0];
    for(i=1; i<n; i++)
    {
        prefixsum[i] = prefixsum[i-1] + v[i];
    }
    for(j=0; j<q; j++)
    {
        cin>>budget;
        auto it = upper_bound(prefixsum.begin(), prefixsum.end(), budget);
        lli ans = it - prefixsum.begin();
        cout<<ans<<" ";
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}


// 1
// 6 6
// 1 3 7 5 3 5
// 8 12 17 18 23 24

// 3 4 5 5 5 6