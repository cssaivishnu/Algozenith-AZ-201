#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n, m;

void printPath(int sc, int dst, vvi &par){
    if(sc != dst)   printPath(sc, par[sc][dst], par);
    cout<<dst<<" ";
}

void solve()
{
    cin>>n>>m;
    vvi dist(n+1, vi(n+1, 1e18));
    vvi par(n+1, vi(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            par[i][j] = i;                  // comment this for loop to get cycles at (i,i)
        }
    }
    for(int i=1; i<=n; i++){
        dist[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = c;
        dist[b][a] = c;     // comment if directed graph
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
    }
    int a, b;
    cin>>a>>b;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<dist[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    if(dist[a][b] != 1e18){
        printPath(a, b, par);
        cout<<endl;
    }

// diameter of a graph = longest ( shortest path i->j)
// just take max(dist[i][j]) (note that dist[i][j] != 1e18 for any i,j if graph is connected)
// or
// find dikstra (bfs for unweighted) at each vertex, and take max. of (max. of the dist[] at every iteration)
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}