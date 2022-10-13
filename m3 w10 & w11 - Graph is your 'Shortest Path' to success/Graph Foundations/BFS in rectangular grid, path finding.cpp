#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define ii pair<int,int>
int mod=1e9+7;

/*
6 5
..#.#
.S#..
.##..
...#.
#....
#.E..
*/

int n, m;
vector<string> arr;
vector<vector<int>> dist;
vector<vector<ii>> par;

// horse moves
int dx[] = {2,2,1,-1,-2,-2,-1,1};
int dy[] = {1,-1,-2,-2,-1,1,2,2};

// up down left right diagonal
// int dx[] = {1,1,1,0,-1,-1,-1,0};
// int dy[] = {1,0,-1,-1,-1,0,1,1};

// up down left right
// int dx[] = {0,-1,0,1};
// int dy[] = {1,0,-1,0};

int inside(int x, int y){
	if(x<0||x>=n||y<0||y>=n||arr[x][y]=='#'){
		return 0;
	}
	return 1;
}

void bfs(ii st){
	dist.resize(n, vector<int>(m));
	par.resize(n, vector<ii>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dist[i][j] = 1e9;
		}
	}
	dist[st.first][st.second] = 0;
	par[st.first][st.second] = {-1,-1};
	queue<ii> q;
	q.push(st);
	while(!q.empty()){
		ii cur = q.front();
		q.pop();
		int curd = dist[cur.first][cur.second];
		for(int k=0; k<8; k++){
			ii neigh = {cur.first+dx[k],cur.second+dy[k]};
			if(!inside(cur.first+dx[k],cur.second+dy[k])){
				continue;
			}
			if(dist[neigh.first][neigh.second] > curd+1){
				dist[neigh.first][neigh.second] = curd+1;
				par[neigh.first][neigh.second] = cur;
				q.push(neigh);
			}
		}
	}
}

void solve()
{
	cin>>n>>m;
	arr.resize(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	ii st, en;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == 'S'){
				st = {i,j};
			}
			if(arr[i][j] == 'E'){
				en = {i,j};
			}
		}
	}
	bfs(st);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(dist[i][j] == 1e9){
				cout<<"-\t";
			}else{
				cout<<dist[i][j]<<"\t";
			}
		}cout<<endl;
	}cout<<endl;
	ii temp=en;
	vector<ii> path;
	while(temp != st){
		path.push_back(temp);
		temp = par[temp.first][temp.second];
	}
	path.push_back(temp);
	reverse(path.begin(), path.end());
	for(auto node:path){
		cout<<node.first<<" "<<node.second<<endl;
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