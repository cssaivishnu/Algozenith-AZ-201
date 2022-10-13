#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define v(x) vector<x>
#define pii pair<int,int>
int mod=1e9+7;

int n, m, sc;

class prioritize{
	public: bool operator ()(pii &a, pii &b){
		return a.second > b.second;
	}
};

void dijkstra(int sc, v(int) &dist, v(int) &vis, v(v(pii)) &g){
	dist[sc] = 0;
	priority_queue<pii, vector<pii>, prioritize> pq;
	pq.push({sc,0});
	while(!pq.empty()){
		pii node=pq.top();
		pq.pop();
		if(vis[node.first] == 1){
			continue;
		}
		vis[node.first] = 1;
		for(auto xx:g[node.first]){
			int neigh = xx.first;
			int wt = xx.second;
			if(dist[neigh] > dist[node.first] + wt){
				dist[neigh] = dist[node.first] + wt;
				pq.push({neigh,dist[neigh]});
			}
		}
	}
}

void solve()
{
	cin>>n>>m;
	v(v(pii)) g(n+1);
	for(int i=0; i<m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	cin>>sc;
	v(int) dist(n+1,1e18), vis(n+1,0);
	dijkstra(sc, dist, vis, g);
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}