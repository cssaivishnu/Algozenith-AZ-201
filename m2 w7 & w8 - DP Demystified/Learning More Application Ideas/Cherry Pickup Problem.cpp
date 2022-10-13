// cherry pickup problem
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, m, score[55][55], dp[55][55][55];

int rec(int r1, int c1, int r2){
    int c2 = r1+c1-r2;
    if(r1>=n || c1>=m || r2>=n || c2>= m){
        return -1e9;
    }
    if(r1 == n-1 && c1 == m-1){
        return score[n-1][m-1];
    }
    if(dp[r1][c1][r2] != -1){
        return dp[r1][c1][r2];
    }
    int ans;
    if(r1 == r2){
        ans = score[r1][c1];
    }else{
        ans = score[r1][c1] + score[r2][c2];
    }
    ans = ans + max({rec(r1+1,c1,r2),rec(r1,c1+1,r2),rec(r1+1,c1,r2+1),rec(r1,c1+1,r2+1)});
    return dp[r1][c1][r2] = ans;
}

void solve()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>score[i][j];
            for(int k=0; k<n; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<score[i][j]<<" ";
        }cout<<endl;
    }
    cout<<rec(0,0,0)<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}