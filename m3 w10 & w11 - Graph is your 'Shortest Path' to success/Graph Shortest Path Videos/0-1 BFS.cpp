#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define v(x) vector<x>
int mod=1e9+7;

int n, m;

void bfs01(v(int) &dist, v(v(pii)) &g, int src){
	dist[src] = 0;
	deque<int> dq;
	dq.push_back(src);
	while(!dq.empty()){
		int node = dq.front();
		int curd = dist[node];
		dq.pop_front();
		for(auto xx:g[node]){
			int neigh = xx.first;
			int weigh = xx.second;
			if(dist[neigh] > curd + weigh){
				dist[neigh] = curd + weigh;
				if(weigh == 0){
					dq.push_front(neigh);
				}else{
					dq.push_back(neigh);
				}
			}
		}
	}
}

void solve()
{
	int src, dest;
	cin>>n>>m>>src>>dest;
	v(v(pii)) g(n+1);
	for(int i=0; i<m; i++){
		int x, y, c;
		cin>>x>>y>>c;
		g[x].push_back({y,c});
		g[y].push_back({x,c});
	}
	v(int) dist(n+1,1e9);
	bfs01(dist, g, src);
	cout<<dist[dest]<<endl;
	for(int i=1; i<=n; i++){
		cout<<dist[i]<<" ";
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