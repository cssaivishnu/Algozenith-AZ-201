#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vvi vector<vector<int>>
#define vi vector<int>
int mod=1e9+7;

int n, m;

// queue for any order
// priority_queue for lexographical order

void kahn(vvi &g, vi &inedge, vi  &topo){
	priority_queue<int> q;
	// queue<int> q;
	for(int i=1; i<=n; i++){
		if(inedge[i] == 0){
			q.push(-i);
		}
	}
	while(!q.empty()){
		// int node=q.front();
		int node=-q.top();
		q.pop();
		topo.push_back(node);
		for(auto neigh:g[node]){
			inedge[neigh]--;
			if(inedge[neigh] == 0){
				// q.push(neigh);
				q.push(-neigh);
			}
		}
	}
}

void solve()
{
	cin>>n>>m;
	vvi g(n+1);
	vi inedge(n+1,0);
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		g[x].push_back(y);
		inedge[y]++;
	}
	vi topo;
	kahn(g, inedge, topo);
	if((int)topo.size() == n){
		for(auto node:topo){
			cout<<node<<" ";
		}cout<<endl;
	}else{
		cout<<"There is a cycle"<<endl;
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