#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vvp vector<vector<pii>>
int mod=1e9+7;

int n, a, b, src;

void dijkstra(vi &dist, vi &vis, vvp &g){
    dist[src] = 0;
    priority_queue<pii> pq;
    pq.push({0,src});
    while(!pq.empty()){
        pii xx=pq.top(); pq.pop();
        int node=xx.second;
        int curd=-xx.first;
        if(vis[node] == 1){
            continue;
        }
        vis[node] = 1;
        for(auto yy:g[node]){
            int neigh=yy.first;
            int wt=yy.second;
            if(dist[neigh] > curd+wt){
                dist[neigh] = curd+wt;
                pq.push({-dist[neigh],neigh});
            }
        }
    }
}

void solve()
{
    cin>>n>>a>>b;
    map<int,int> mp;
    vi arr(n+1);
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        mp[arr[i]] = i;
    }
    cin>>src;
    vvp g(2*n+1);
    for(int i=1; i<n; i++){
        g[i].push_back({i+1,b});
        g[i+1].push_back({i,b});
    }
    for(int i=1; i<=n; i++){
        g[i].push_back({n+mp[arr[i]],0});
        g[n+mp[arr[i]]].push_back({i,a});
    }
// for(auto x:g){
//     for(auto y:x){
//         cout<<y.first<<" ";
//     }cout<<endl;
// }cout<<endl;
    vi dist(2*n+1, 1e18);
    vi vis(2*n+1, 0);
    dijkstra(dist, vis, g);
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }cout<<endl;
}

#undef int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}