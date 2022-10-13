#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n;

void dfs(int node, int p, int d, vi &par, vi &depth, int &maxdepth, int &nummax, vvi &g){
	depth[node] = d;
	if(d > maxdepth){
		maxdepth = d;
		nummax = 1;
	}else if(d == maxdepth){
		nummax++;
	}
	par[node] = p;
	for(auto neigh:g[node]){
		if(neigh == p)	continue;
		dfs(neigh, node, d+1, par, depth, maxdepth, nummax, g);
	}
}

void solve()
{
	cin>>n;
	vvi g(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vi par(n+1), depth(n+1);
	int maxdepth = 0, nummax = 0;
	dfs(1, 0, 0, par, depth, maxdepth, nummax, g);
	int pnt;
	for(int i=1; i<=n; i++){
		if(depth[i] == maxdepth){
			pnt = i;
			break;
		}
	}
	maxdepth = 0; nummax = 0;
	dfs(pnt, 0, 0, par, depth, maxdepth, nummax, g);
	if(maxdepth%2 == 0){
		int c;
		for(int i=1; i<=n; i++){
			if(depth[i] == maxdepth){
				c = i;
				break;
			}
		}
		for(int i=1; i<=maxdepth/2; i++){
			c = par[c];
		}
		cout<<"Single Center : "<<c<<endl;
		int ans = 0;
		int pre = 0;
		for(auto x:g[c]){
			int md=0, nm=0;
			dfs(x, c, 0, par, depth, md, nm, g);
			int val = 0;
			if(md == (maxdepth/2-1))	val = nm;
			ans += pre*val;
			pre += val;
		}
		cout<<"Number of diameters = "<<ans<<endl;
	}else{
		int c1, c2;
		for(int i=1; i<=n; i++){
			if(depth[i] == maxdepth){
				c1 = i;
				break;
			}
		}
		for(int i=1; i<=(maxdepth/2); i++){
			c1 = par[c1];
		}
		c2 = par[c1];
		int ans1, ans2, ans;
		int md=0, nm=0;
		dfs(c1, c2, 0, par, depth, md, nm, g);
		ans1 = nm;
		md = 0; nm = 0;
		dfs(c2, c1, 0, par, depth, md, nm, g);
		ans2 = nm;
		ans = ans1*ans2;
		cout<<"Two Centers : "<<c1<<" "<<c2<<endl;
		cout<<"Number of diameters = "<<ans<<endl;
	}
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}