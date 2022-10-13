#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, k, a[1010], dp[1010][2][1010];

int rec(int level,int flag, int ind){
	if(level == n){
		return 1;
	}
	if(dp[level][flag][ind] != -1){
		return dp[level][flag][ind];
	}
	int left=(flag==0?(level-1):ind);
	int right = ind + level-1 - left;
// cout<<left<<level<<right;
	int ans=0;
	if(a[left]-a[level] <= k){
// cout<<a[level]<<" "<<a[left]<<endl;
		ans += rec(level+1,0,right);
	}
	if(a[right]-a[level] <= k){
// cout<<a[level]<<" "<<a[right]<<endl;
		ans += rec(level+1,1,left);
	}
	return dp[level][flag][ind] = ans;
}

void solve()
{
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			dp[i][0][j] = -1;
			dp[i][1][j] = -1;
		}
	}
	sort(a,a+n);
	reverse(a,a+n);
	// for(int i=0; i<n; i++){
	// 	cout<<a[i]<<" ";
	// }cout<<endl<<n<<endl;
	cout<<rec(1,0,0)<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}