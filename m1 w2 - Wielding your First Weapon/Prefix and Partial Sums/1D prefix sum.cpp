#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n, i, q, l, r, mod=1e9+7;
    cin>>n>>q;
    vector<lli> a(n+1), p(n+1);
	a[0] = 0;
    for(i=1; i<=n; i++){
        cin>>a[i];
    }
    p[0] = 0;
    for(i=1; i<=n; i++){
        p[i] = (p[i-1] + a[i])%mod;
    }
    while(q--){
        cin>>l>>r;
		lli ans = p[r]-p[l-1];
		ans = ((ans%mod)+mod)%mod;
        cout<<ans<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// 10 10
// 12 -23 -123 2345 2345 44 345 -93945 -5353 1
// 1 5
// 1 8
// 1 10
// 2 2
// 6 6
// 4 8
// 2 9
// 4 10
// 3 6
// 5 9

// 4556
// 999911007
// 999905655
// 999999984
// 44
// 999911141
// 999905642
// 999905789
// 4611
// 999903443