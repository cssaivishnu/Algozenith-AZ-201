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
    map<lli,vector<lli>> mp;
    mp[0].push_back(0);
    ans = 0;
    for(i=1; i<=n; i++)
    {
        if(mp.find(p[i]-sum) != mp.end())
        {
            ans += mp[p[i]-sum].size();
            for(auto x:mp[p[i]-sum])
                cout<<"index "<<x<<" to index "<<i-1<<endl;
        }
        mp[p[i]].push_back(i);
    }
    cout<<"total = "<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// 11 6
// 3 2 1 3 2 1 1 1 2 2 2

// index 0 to index 2
// index 1 to index 3
// index 2 to index 4
// index 3 to index 5
// index 6 to index 9
// index 8 to index 10
// total = 6