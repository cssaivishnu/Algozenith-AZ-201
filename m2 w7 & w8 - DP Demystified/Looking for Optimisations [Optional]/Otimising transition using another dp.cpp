#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, m, D, c[505][505], dp[505][505], dp1[505];

int rec(int level, int last);

int rec1(int level){
	if(level > n){
		return 0;
	}
	if(dp1[level] != -1){
		return dp1[level];
	}
	int ans = rec(level,0) + c[level-1][0];
	for(int i=1; i<m; i++){
		ans = min(ans, rec(level,i)+c[level-1][i]);
	}
	return dp1[level] = ans;
}

int rec(int level, int last){
	if(level == n){
		return 0;
	}
	if(dp[level][last] != -1){
		return dp[level][last];
	}
	int ans=rec(level+1,last)+c[level][last]-D;
	ans = min(ans, rec1(level+1));
	return dp[level][last] = ans;
}

void solve()
{
	cin>>n>>m>>D;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>c[i][j];
			dp[i][j] = -1;
			dp1[i] = -1;
		}
	}
	dp1[n] = -1;
	int ans = rec(1,0) + c[0][0];
	for(int i=1; i<m; i++){
		ans = min(ans, rec(1,i)+c[0][i]);
	}
	cout<<ans<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}