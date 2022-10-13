#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define v(x) vector<x> 
int mod=1e9+7;

int n, m;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

// 5 5
// 33022
// 30002
// 00000
// 10004
// 11044

int bfs01(int x, int y, v(v(int)) &dist, v(string) &grid, v(v(int)) &vis){
	v(v(pii)) par(n, v(pii)(m, {-1,-1}));
	deque<pii> q;
	if(grid[x][y] == '0'){
		vis[x][y] = 1;
		q.push_back({x,y});
		dist[x][y] = 0;
	}else{
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(grid[i][j] == grid[x][y]){
					vis[i][j] = 1;
					q.push_back({i,j});
					dist[i][j] = 0;
				}
			}
		}
	}
	while(!q.empty()){
		pii node=q.front();
		q.pop_front();
		int curd = dist[node.first][node.second];
		for(int k=0; k<4; k++){
			int xx=node.first+dx[k], yy=node.second+dy[k];
			if(xx<0||xx>=n||yy<0||yy>=m)	continue;
			if(grid[xx][yy] == '#')	continue;
			if(grid[xx][yy] == '0'){
				if(dist[xx][yy] > curd+1){
					dist[xx][yy] = curd+1;
					q.push_back({xx,yy});
					par[xx][yy] = node;
				}
			}else{
				if(dist[xx][yy] > curd){
					dist[xx][yy] = curd;
					q.push_front({xx,yy});
					par[xx][yy] = par[node.first][node.second];
				}
			}
		}
	}
// for(int i=0; i<n; i++){
// 	for(int j=0; j<m; j++){
// 		if(dist[i][j] == 1e9){
// 			cout<<"-\t";
// 		}else{
// 			cout<<dist[i][j]<<"\t";
// 		}
// 	}cout<<endl;
// }cout<<endl;
	map<int,int> mp;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j] != '#' && grid[i][j] != '0'){
				mp[grid[i][j]-'0']++;
				if(mp[grid[i][j]] == 1){
					
				}
			}
		}
	}
	int sum = 1;
	for(auto temp:mp){
		sum += temp.second-1;
	}
	return sum;
}

void solve()
{
	cin>>n>>m;
	v(string) grid(n);
	for(int i=0; i<n; i++){
		cin>>grid[i];
	}
	v(v(int)) vis(n, v(int)(m, 0));
	int mini = 1e9;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j] != '#' && vis[i][j] == 0){
				v(v(int)) dist(n, v(int)(m,1e9));
				int ans = bfs01(i, j, dist, grid, vis);
				mini = min(ans, mini);
			}
		}
	}
	if(mini == 1e9){
		cout<<-1<<endl;
	}else{
		cout<<mini<<endl;
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