#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long
#define modu 1000000007

void solve()
{
    lli n, m, q, i, j, x1, x2, y1, y2, c;
    cin>>n>>m>>q;
	lli a[n+2][m+2];
    for(i=0; i<=n+1; i++){
        for(j=0; j<=m+1; j++){
            a[i][j] = 0;
        }
    }
    while(q--){
        cin>>x1>>y1>>x2>>y2>>c;
        if(c==0)	continue;
        a[x1][y1] += c;
        a[x1][y2+1] -= c;
        a[x2+1][y1] -= c;
        a[x2+1][y2+1] += c;
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            // a[i][j] %= modu;
            // a[i][j] = ((a[i][j]%modu)+modu)%modu;
        }
    }
    lli maxi = a[1][1], count=0;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            maxi = max(maxi,a[i][j]);
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(a[i][j] == maxi){
                count++;
            }
        }
	}
    // for(i=1; i<=n; i++){
    //     for(j=1; j<=m; j++){
	// 		cout<<a[i][j]<<" ";
    //     }
	// 	cout<<endl;
    // }
    cout<<maxi<<" "<<count;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}

// 5 5 5
// 1 1 2 2 -8
// 1 2 3 4 9
// 2 3 3 3 -2
// 4 4 4 4 -4
// 2 3 2 4 0

// 9 5