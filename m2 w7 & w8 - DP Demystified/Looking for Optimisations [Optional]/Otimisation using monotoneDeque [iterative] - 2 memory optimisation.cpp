#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, m, k, dp[2][1010], a[1010], b[1010];

deque<int> dq;

void insert(int x){
	while(!dq.empty() && dq.back()>x){
		dq.pop_back();
	}
	dq.push_back(x);
}

void remove(int x){
	if(dq.front() == x){
		dq.pop_back();
	}
}

int getMin(){
	return dq.front();
}

void freeAll(){
	dq.clear();
}

void solve()
{
	cin>>n>>k>>m;
	for(int i=1; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	for(int i=0; i<=m; i++){
		dp[(i&1)][0] = 0;
		freeAll();
		for(int j=1; j<n; j++){
			dp[(i&1)][j] = dp[(i&1)][j-1] + a[j];
			if(i > 0){
				insert(dp[((i+1)&1)][j-1]+b[j-1]);
				if(j-k-1 >= 0){
					remove(dp[((i+1)&1)][j-k-1]+b[j-k-1]);
				}
				dp[(i&1)][j] = min(dp[(i&1)][j], dq.front()+b[j]);
			}
		}
	}
	cout<<dp[m&1][n-1]<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}