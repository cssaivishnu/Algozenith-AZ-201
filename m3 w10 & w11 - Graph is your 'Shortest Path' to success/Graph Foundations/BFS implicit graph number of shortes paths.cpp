#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
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
pair<int,int> dist[1010][1010], par[1010][1010];

// horse moves
// int dx[] = {2,2,1,-1,-2,-2,-1,1};
// int dy[] = {1,-1,-2,-2,-1,1,2,2};

// up down left right diagonal
// int dx[] = {1,1,1,0,-1,-1,-1,0};
// int dy[] = {1,0,-1,-1,-1,0,1,1};

// up down left right
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int inside(int x, int y){
	if(x<0||x>=n||y<0||y>=n||arr[x][y]=='#'){
		return 0;
	}
	return 1;
}

void bfs(pair<int,int> st){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dist[i][j] = {1e9,0};
		}
	}
	dist[st.first][st.second] = {0,1};
	par[st.first][st.second] = {-1,-1};
	queue<pair<int,int>> q;
	q.push(st);
	while(!q.empty()){
		pair<int,int> cur = q.front();
		q.pop();
		int curd = dist[cur.first][cur.second].first;
		for(int k=0; k<4; k++){
			if(!inside(cur.first+dx[k],cur.second+dy[k])){
				continue;
			}
			pair<int,int> neigh = {cur.first+dx[k],cur.second+dy[k]};
			if(dist[neigh.first][neigh.second].first > curd+1){
				dist[neigh.first][neigh.second] = {curd+1,dist[cur.first][cur.second].second};
				par[neigh.first][neigh.second] = cur;
				q.push(neigh);
			}else if(dist[neigh.first][neigh.second].first == curd+1){
				dist[neigh.first][neigh.second].second += dist[cur.first][cur.second].second;
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
	pair<int,int> st, en;
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
	cout<<dist[en.first][en.second].first<<" "<<dist[en.first][en.second].second<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}