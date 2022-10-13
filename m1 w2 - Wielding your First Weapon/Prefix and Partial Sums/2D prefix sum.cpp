#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long
#define modu 1000000007

void solve()
{
    lli n, m, q, i, j, x1, x2, y1, y2, ans;
    cin>>n>>m>>q;
	lli a[n+2][m+2];
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            a[i][j] += ((a[i-1][j]+a[i][j-1])%modu - a[i-1][j-1])%modu;
            a[i][j] %= modu;
            a[i][j] = ((a[i][j]%modu)+modu)%modu;
        }
    }
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        ans = a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1];
        ans = ans%modu;
		ans = ((ans%modu)+modu)%modu;
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


// 5 5 5
// -1 2 3 -4 2
// 0 0 0 0 4
// 1 2 4 3 5
// -1 -5 -2 3 4
// 0 -3 -5 3 -6
// 1 1 2 2
// 1 2 3 4
// 2 3 3 3
// 4 4 4 4
// 2 3 2 4

// 1
// 10
// 4
// 3
// 0