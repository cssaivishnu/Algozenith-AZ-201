#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vi vector<int>
int mod=1e9+7;

// 5
// .#..#
// ...#.
// .#..#
// #..#.
// #....
// 2 1
// 4 3

int n, sx, sy, dx, dy;
int Dx[] = {0,1,0,-1};
int Dy[] = {1,0,-1,0};

void bfs01(vvi &grid, vvvi &dist){
	deque<pair<int,pii>> dq;
	for(int i=0; i<4; i++){
		dq.push_back({i,{sx,sy}});
		dist[sx][sy][i] = 0;
	}
	// int temp=3;
	// while(temp--){
	while(!dq.empty()){
		pair<int,pii> xx=dq.front(); dq.pop_front();
		int x=xx.second.first;
		int y=xx.second.second;
		int dir=xx.first;
		int curd=dist[x][y][dir];
		int nx=x+Dx[dir], ny=y+Dy[dir];
		if(grid[nx][ny] == 0){
			if(dist[nx][ny][dir] > curd){
				dist[nx][ny][dir] = curd;
				dq.push_front({dir,{nx,ny}});
			}
		}else{
			for(int k=0; k<4; k++){
				nx=x+Dx[k]; ny=y+Dy[k];
				if(k == dir)	continue;
				if(grid[nx][ny] == 0){
					if(dist[x][y][k] > curd + 1){
						dist[x][y][k] = curd + 1;
						dq.push_back({k,{x,y}});
					}
				}
			}
		}
	}
}

void solve()
{
	cin>>n;
	vvi grid(n+2, vi(n+2,1));
	for(int i=1; i<=n; i++){
		string str;
		cin>>str;
		for(int j=1; j<=n; j++){
			if(str[j-1] == '.'){
				grid[i][j] = 0;
			}
		}
	}
	cin>>sx>>sy>>dx>>dy;
	vvvi dist(n+2, vvi(n+2, vi(4,1e18)));
	bfs01(grid, dist);
// for(int i=0; i<n+2; i++){
// 	for(int j=0; j<n+2; j++){
// 		cout<<grid[i][j];
// 	}cout<<endl;
// }cout<<endl;
// for(int k=0; k<4; k++){
// 	for(int i=0; i<n+2; i++){
// 		for(int j=0; j<n+2; j++){
// 			if(dist[i][j][k] == 1e18)	cout<<"-\t";
// 			else	cout<<dist[i][j][k]<<"\t";
// 		}cout<<endl;
// 	}cout<<endl;
// }cout<<endl;
	int ans = 1e18;
	for(int k=0; k<4; k++){
		if(grid[dx+Dx[k]][dy+Dy[k]] == 1){
			ans = min(ans, dist[dx][dy][k]);
		}
	}
	cout<<ans+1<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}