#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define mini (-1e9)

string temp;
int a[100100], n, k;
map<char,int> mp;
int dp[100100][3][101];

int fu(int mymove, int compmove){
    return (compmove == (mymove+1)%3);
}

int rec(int level, int last, int kleft){
    if(kleft < 0){
        return mini;
    }
    if(level == n){
        return 0;
    }
    if(dp[level][last][kleft] != -1){
        return dp[level][last][kleft];
    }
    int ans = -1e9;
    for(int i=0; i<3; i++){
        ans = max(ans,fu(i,a[level])+rec(level+1,i,kleft-((i==last)?0:1)));
    }
    return dp[level][last][kleft] = ans;
}

void solve()
{
    cin>>temp>>k;
    n = temp.length();
    for(int i=0; i<n; i++){
        a[i] = mp[temp[i]];
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<3; j++){
            for(int l=0; l<=k; l++){
                dp[i][j][l] = -1;
            }
        }
    }
    for(int level=n; level>=0; level--){
        for(int last=0; last<3; last++){
            for(int kleft=0; kleft<=k; kleft++){
                if(level == n){
                    dp[level][last][kleft] = 0;
                }
                int ans = 0;
                for(int x=0; x<3; x++){
                    if(kleft-((x==last)?0:1) >= 0){
                        ans = max(ans,fu(x,a[level])+rec(level+1,x,kleft-((x==last)?0:1)));
                    }
                }
                dp[level][last][kleft] = ans;
            }
        }
    }
    int ans = max({dp[0][0][k],dp[0][1][k],dp[0][2][k]});
    cout<<ans<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    mp['P'] = 0;
    mp['H'] = 1;
    mp['S'] = 2;
    // int _t; cin>>_t; while(_t--)
    solve();
}