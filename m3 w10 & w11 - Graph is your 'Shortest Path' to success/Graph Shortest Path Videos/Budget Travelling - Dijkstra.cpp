#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vvp vector<vector<pii>>
int mod=1e9+7;

int n, m, c, sc, dst;

void dijkstra(int sc, int dst, vvp &g, vvi &dist, vvi &vis, vi &p){
    dist[sc][0] = 0;
    priority_queue<pair<int,pii>> pq;
    pq.push({0,{sc,0}});
    while(!pq.empty()){
        pair<int,pii> node=pq.top(); pq.pop();
        int curd=-node.first;
        int city=node.second.first;
        int fuel=node.second.second;
        if(vis[city][fuel] == 1){
            continue;
        }
        vis[city][fuel] = 1;
        for(auto xx:g[city]){
            int neigh=xx.first;
            int wt=xx.second;
            if(fuel >= wt){
                if(dist[neigh][fuel-wt] > curd){
                    dist[neigh][fuel-wt] = curd;
                    pq.push({-dist[neigh][fuel-wt],{neigh,fuel-wt}});
                }
            }
        }
        if(fuel != c){
            if(dist[city][fuel+1] > dist[city][fuel] + p[city]){
                dist[city][fuel+1] = dist[city][fuel] + p[city];
                pq.push({-dist[city][fuel+1],{city,fuel+1}});
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
	vvp g(n+1);
    for(int i=0; i<m; i++){
        int u, v, d;
        cin>>u>>v>>d;
        g[u].push_back({v,d});
        g[v].push_back({u,d});
    }
    vi p(n+1);
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }
    cin>>sc>>dst>>c;
    vvi dist(n+1,vi(c+1,1e18));
    vvi vis(n+1,vi(c+1,0));
    dijkstra(sc, dst, g, dist, vis, p);
    cout<<dist[dst][0]<<endl;
}

#undef int

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}