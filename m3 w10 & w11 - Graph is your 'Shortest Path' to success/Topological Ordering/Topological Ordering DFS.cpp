#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vvi vector<vector<int>>
#define vi vector<int>
int mod=1e9+7;

int n, m;

void dfs(int node, vi &vis, vi &topo, vvi &g){
	vis[node] = 1;
	for(auto neigh:g[node]){
		if(vis[neigh] == 0){
			dfs(neigh, vis, topo, g);
		}
	}
	topo.push_back(node);
}

void solve()
{
	cin>>n>>m;
	vvi g(n+1);
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	vi vis(n+1,0), topo;
	for(int i=1; i<=n; i++){
		if(vis[i] == 0){
			dfs(i, vis, topo, g);
		}
	}
	reverse(topo.begin(), topo.end());
	for(auto node:topo){
		cout<<node<<" ";
	}cout<<endl;
	reverse(topo.begin(), topo.end());
	int final=0;
	int dp[n+1];
	for(auto node:topo){
		int ans;
		ans = 1;
		for(auto neigh:g[node]){
			ans = max(ans, 1 + dp[neigh]);
		}
		dp[node] = ans;
	}
	for(int i=1; i<=n; i++){
		cout<<dp[i]<<" ";
	}cout<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}