#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, k, a[100100], b[100100], dp[100100];

struct monotoneDeque{
	deque<int> d;
	void insert(int x){
		while(!d.empty() && d.back()>x){
			d.pop_back();
		}
		d.push_back(x);
	}
	void remove(int x){
		if(d.front() == x){
			d.pop_front();
		}
	}
	int getMin(){
		return d.front();
	}
};

void solve()
{
	monotoneDeque dq;
	cin>>n>>k;
	for(int i=1; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	dp[0] = 0;
	for(int i=1; i<n; i++){
		dq.insert(dp[i-1] + b[i-1]);
		if(i-k-1 >= 0){
			dq.remove(dp[i-k-1] + b[i-k-1]);
		}
		dp[i] = dq.getMin() + b[i];
		dp[i] = min(dp[i], dp[i-1]+a[i]);
	}
	cout<<dp[n-1]<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}