#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
vector<int> parent;

bool is_cycle = 0;
vector<int> any_cycle;

vector<int> cntcycle;
vector<int> prefixorder;

void dfs(int node,int par){ // O(N+M)
	parent[node] = par;
	col[node]=2;
	for(auto v:g[node]){
		// add for undirected
		// if(v==parent[node])continue;
		if(col[v]==1){ 
			// node - v is a forward edge
			dfs(v,node);
		}else if(col[v]==2){
			// node - v is a back edge
			// We found a cycle !!
			if(is_cycle==0){
				int temp = node;
				while(temp!=v){
					any_cycle.push_back(temp);
					temp=parent[temp];
				}
				any_cycle.push_back(temp);
				reverse(any_cycle.begin(), any_cycle.end());
			}
			cntcycle[node]++;
			cntcycle[parent[v]]--;
			is_cycle = 1;
		}else if(col[v]==3){
			// node - v is a cross edge
			// unimportant
		}
	}
	col[node]=3;
	prefixorder.push_back(node);
}

int main(){
	int n,m;
	cin>>n>>m;

	g.resize(n+1);
	col.assign(n+1,1);
	parent.assign(n+1,0);
	cntcycle.assign(n+1,0);

	map<pair<int,int>,int> edgecnt;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		if(x==y){
			//self-loop
		}
		if(x>y)swap(x,y);
		edgecnt[make_pair(x,y)]++;
		if(edgecnt[make_pair(x,y)]>1){
			//multiple edge cycle
		}else{
			g[x].push_back(y);
			g[y].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		if(col[i]==1){
			dfs(i,0);
		}
	}
	for(auto v:prefixorder){
		cntcycle[parent[v]]+=cntcycle[v];
	}
	int cntnode = 0;
	for(int i=1;i<=n;i++){
		if(cntcycle[i]>0)cntnode++;
	}
	cout<<cntnode<<endl;
}