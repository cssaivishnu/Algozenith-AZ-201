#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n, q, k, i, l, r, N=1000001;
    cin>>n>>k>>q;
    vector<lli> v(1000002,0), p(1000001,0);
    for(i=0; i<n; i++){
        cin>>l>>r;
        v[l] += 1;
        v[r+1] -= 1;
    }
    p[0] = 0;
    for(i=1; i<=N; i++){
        p[i] = p[i-1] + v[i];
    }
	for(i=1; i<=N; i++){
		if(p[i] >= k)
			p[i] = 1;
		else
			p[i] = 0;
    }
	for(i=1; i<=N; i++){
		p[i] = p[i] + p[i-1];
	}
    while(q--){
        cin>>l>>r;
        cout<<p[r]-p[l-1]<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// 10 3 10
// 1 5
// 2 7
// 3 9
// 1 5
// 3 8
// 4 10
// 7 10
// 8 8
// 5 5
// 6 7
// 1 5
// 3 8
// 4 9
// 3 10
// 2 6
// 3 9
// 7 7
// 5 5
// 8 8
// 3 7

// 4
// 6
// 6
// 7
// 5
// 7
// 1
// 1
// 1
// 5