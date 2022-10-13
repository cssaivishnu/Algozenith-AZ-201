#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vpiii vector<pair<int,pii>>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

struct unionfind{
	int n, setsize;
	vi par, rank;
	unionfind(){}
	unionfind(int a){
		n = a;
		setsize = a;
		par.resize(n+1);
		rank.resize(n+1);
		for(int i=1; i<=n; i++){
			par[i] = i;
			rank[i] = 1;
		}
	}
	int find(int x){
		if(par[x] == x){
			return x;
		}
		return par[x] = find(par[x]);
	}
	int merge(int x, int y){
		int xroot=find(x), yroot=find(y);
		if(xroot == yroot)	return 0;
		if(rank[xroot] >= rank[yroot]){
			par[yroot] = xroot;
			rank[xroot] += rank[yroot];
		}else{
			par[xroot] = yroot;
			rank[yroot] += rank[xroot];
		}
		setsize--;
		return 1;
	}
	void reset(){
		setsize = n;
		for(int i=1; i<=n; i++){
			par[i] = i;
			rank[i] = 1;
		}
	}
};

int n, m;

void solve()
{
	cin>>n>>m;
	vpiii edges;
	for(int i=0; i<m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		edges.push_back({c,{a,b}});
	}
	sort(edges.begin(),edges.end());
	unionfind obj(n);
	int mst=0;
	for(int i=0; i<m; i++){
		int a, b, c;
		c = edges[i].first;
		a = edges[i].second.first;
		b = edges[i].second.second;
		mst += obj.merge(a,b)*c;
	}
	cout<<mst<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}