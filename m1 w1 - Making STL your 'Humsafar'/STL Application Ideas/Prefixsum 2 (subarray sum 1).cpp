#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli i, n, sum, ans;
    cin>>n>>sum;
    vector<lli> v(n), p(n+1);
    for(i=0; i<n; i++)
        cin>>v[i];
    p[0] = 0;
    for(i=0; i<n; i++)
        p[i+1] = p[i] + v[i];
    map<lli,lli> mp;
    mp[0]++;
    ans = 0;
    for(i=1; i<=n; i++)
    {
        if(mp.find(p[i]-sum) != mp.end())
        {
            ans += mp[p[i]-sum];
        }
        mp[p[i]]++;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}