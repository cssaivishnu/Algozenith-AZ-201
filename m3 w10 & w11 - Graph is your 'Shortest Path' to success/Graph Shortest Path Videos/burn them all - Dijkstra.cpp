#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vvp vector<vector<pii>>
#define vi vector<int>
#define vp vector<pii>
int mod=1e9+7;

int n, m, a;

void dijkstra(vi &dist, vi &vis, vvp &g){
    dist[a] = 0;
    priority_queue<pii> pq;
    pq.push({0,a});
    while(!pq.empty()){
        pii xx=pq.top(); pq.pop();
        int curd=-xx.first;
        int node=xx.second;
        if(vis[node] == 1){
            continue;
        }
        vis[node] = 1;
        for(auto yy:g[node]){
            int wt=yy.second;
            int neigh=yy.first;
            if(dist[neigh] > curd+wt){
                dist[neigh] = curd+wt;
                pq.push({-dist[neigh],neigh});
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
    cin>>a;
    vi dist(n+1,1e18), vis(n+1,0);
    dijkstra(dist, vis, g);
    int ans=0;
    for(int i=1; i<=n; i++){
        for(auto xx:g[i]){
            int j = xx.first;
            int x = xx.second;
            if(abs(dist[i]-dist[j]) == x){
                ans = max(ans, 10*max(dist[i], dist[j]));
            }else{
                ans = max(ans, 5*(dist[i]+dist[j]+x));
            }
        }
    }
    cout<<ans<<endl;
}

#undef int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}