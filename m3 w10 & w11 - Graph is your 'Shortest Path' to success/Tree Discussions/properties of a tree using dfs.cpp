#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n;

void dfs(int node, int p, int depth, vi &d, vi &il, vi &sts, vi &nc, vi &par, vvi &g){
	par[node] = p;
	d[node] = depth;
	sts[node] = 1;
	nc[node] = 0;
	for(auto neigh:g[node]){
		if(neigh == p)	continue;
		dfs(neigh, node, depth+1, d, il, sts, nc, par, g);
		sts[node] += sts[neigh];
		nc[node]++;
	}
	il[node] = 0;
	if(nc[node] == 0){
		il[node] = 1;
	}
}

void solve()
{
	cin>>n;
	vvi g(n+1);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vi depth(n+1);
	vi isleaf(n+1);
	vi subtreesize(n+1);
	vi numchild(n+1);
	vi par(n+1);
	dfs(1, 0, 0, depth, isleaf, subtreesize, numchild, par, g);
	for(int i=1; i<=n; i++){
		cout<<par[i]<<" ";
	}cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<depth[i]<<" ";
	}cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<subtreesize[i]<<" ";
	}cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<numchild[i]<<" ";
	}cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<isleaf[i]<<" ";
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