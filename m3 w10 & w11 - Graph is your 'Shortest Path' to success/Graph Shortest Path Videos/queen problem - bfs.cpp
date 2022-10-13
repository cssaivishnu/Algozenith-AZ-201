#include <bits/stdc++.h>
#define S second
#define F first
using namespace std;

using state = pair<int,int>;

int dx[] = {0,1,1,1,0,-1,-1,-1}; 
int dy[] = {1,1,0,-1,-1,-1,0,1};
int n, m;

int dist[1010][1010];

bool check(int x,int y){
	if(x<0||x>=n||y<0||y>=m||arr[x][y]=='#'||dist[x][y]!=1e9)return 0;
	return 1;
}

void bfs(state st){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dist[i][j] = 1e9;
		}
	}
	dist[st.F][st.S] = 0;
	queue<state> q;
	q.push(st);
	while(!q.empty()){
		state cur = q.front(); q.pop();
		int dcur = dist[cur.F][cur.S];
		// 
		for(int k=0;k<8;k++){
			int movelen = 1;
			while(1){
				state v = { cur.F+dx[k]*movelen, cur.S+dy[k]*movelen};
				if(check(v.F,v.S)){
					// relax the v neighbour
					dist[v.F][v.S] = dcur+1;
					q.push(v);
				}else{
					break;
				}
				movelen++;
			}
		}
	}
}