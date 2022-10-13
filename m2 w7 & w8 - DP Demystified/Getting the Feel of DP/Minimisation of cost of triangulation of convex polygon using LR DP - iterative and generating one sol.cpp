#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, x[101], y[101];
pair<int,int> dp[101][101];

int sq(int l){
    return l*l;
}

int dist(int l, int r){
    return sq(x[l]-x[r]) + sq(y[l]-y[r]);
}

vector<pair<int,int>> sol;

void generate(int l, int r){
    if(r-l < 3){
        return;
    }
    int x = dp[l][r].second;
    if(x == l+1){
        sol.push_back({l+1,r});
        generate(l+1,r);
    }else if(x == r-1){
        sol.push_back({l,r-1});
        generate(l,r-1);
    }else{
        sol.push_back({l,x});
        sol.push_back({x,r});
        generate(l,x);
        generate(x,r);
    }
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = {-1,-1};
        }
    }
    for(int len=1; len<=n; len++){
        for(int l=0; l<n-len+1; l++){
            int r = l + len - 1;
            if(r-l < 3){
                dp[l][r] = {0,-1};
                continue;
            }
            pair<int,int> ans;
            ans = {dist(l+1,r)+dp[l+1][r].first,l+1};
            ans = min(ans,{dist(l,r-1)+dp[l][r-1].first,r-1});
            for(int x=l+2; x<=r-2; x++){
                ans = min(ans,{(dist(l,x)+dist(x,r)+dp[l][x].first+dp[x][r].first),x});
            }
            dp[l][r] = ans;
        }
    }
    cout<<dp[0][n-1].first<<endl;
    generate(0,n-1);
    for(auto v : sol){
        cout<<v.first<<" "<<v.second<<endl;
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