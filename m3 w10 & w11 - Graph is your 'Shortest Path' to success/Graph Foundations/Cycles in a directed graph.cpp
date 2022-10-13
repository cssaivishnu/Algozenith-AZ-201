#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

vector<vector<int>> g;
vector<int> col, parent, any_cycle;
int n, m, is_cycle;

void dfs(int x, int p){
    parent[x] = p;
    col[x] = 2;
    for(auto y:g[x]){
        if(col[y] == 1){
            // x,y is a forward edge
            dfs(y, x);
        }else if(col[y] == 2){
            // x,y is a back edge
            if(is_cycle == 0){
                int temp = x;
                while(temp != y){
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(), any_cycle.end());
            }
            is_cycle = 1;
        }else if(col[y] == 3){
            // x,y is a cross edge
        }
    }
    col[x] = 3;
}

void solve()
{
    is_cycle = 0;
    cin>>n>>m;
    g.clear();
    parent.assign(n+1, 0);
    any_cycle.clear();
    g.resize(n+1);
    col.assign(n+1, 1);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1; i<=n; i++){
        if(col[i] == 1){
            dfs(i, 0);
        }
    }
    cout<<is_cycle<<endl;
    for(auto node:any_cycle){
        cout<<node<<" ";
    }cout<<any_cycle[0]<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}