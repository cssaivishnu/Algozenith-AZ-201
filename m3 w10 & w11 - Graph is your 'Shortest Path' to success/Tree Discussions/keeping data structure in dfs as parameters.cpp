#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

// val[i] is the value at node i
// ans[i] is the min(abs(val[i] - val[j])) where j is ancestor of i
// ans[1] is 0 since it has no ancestors
// we use a multiset for the full tree

int n;

int query(multiset<int> &mt, int val){
    auto it = mt.lower_bound(val);
    int ans = 1e9+1;
    if(it != mt.end()){
        ans = min(ans, abs(*it-val));
    }
    if(it != mt.begin()){
        it--;
        ans = min(ans, abs(*it-val));
    }
    return ans;
}

void dfs(int node, int p, vi &val, vvi &g, multiset<int> &mt, vi &ans){
    ans[node] = query(mt, val[node]);
    mt.insert(val[node]);
    for(auto neigh:g[node]){
        if(neigh == p)  continue;
        dfs(neigh, node, val, g, mt, ans);
    }
    mt.erase(mt.find(val[node]));
}

void solve()
{
    cin>>n;
    vvi g(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi val(n+1);
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }
    vi ans(n+1);
    multiset<int> mt;
    mt.insert(val[1]);
    dfs(1, 0, val, g, mt, ans);
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}