#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<pii>
#define vvp vector<vector<pii>>
int mod=1e9+7;

int n;

void dfs(int node, int p, int d, vi &par, vi &depth, vi &subtree, vvi &g){
	depth[node] = d;
	par[node] = p;
	subtree[node] = 1;
	for(auto neigh:g[node]){
		if(neigh == p)	continue;
		dfs(neigh, node, d+1, par, depth, subtree, g);
		subtree[node] += subtree[neigh];
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
	vi depth(n+1), subtree(n+1), par(n+1);
	dfs(1, 0, 0, par, depth, subtree, g);
	int node = 1;
	while(true){
		int togo = node;
		for(auto neigh:g[node]){
			if(neigh == par[node])	continue;
			if(subtree[neigh] > n/2){
				togo = neigh;
				break;
            }
		}
		if(togo == node){
			break;
		}
		node = togo;
	}
    for(auto neigh:g[node]){
        if(neigh == par[node])	continue;
        if(subtree[neigh] == n/2){
            if(n%2 == 0){
                node = min(node, neigh);
                break;
            }
        }
    }
	cout<<node<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}