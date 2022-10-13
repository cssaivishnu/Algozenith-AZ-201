#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
int mod=1e9+7;

string l, r;
int len, D;
vvvvi dp;

int rec(int level, int tlo, int thi, int d){
    if(dp[level][tlo][thi][d] != -1){
        return dp[level][tlo][thi][d];
    }
    if(level == len){
        if(d == 0){
            return dp[level][tlo][thi][d] = 1;
        }else{
            return dp[level][tlo][thi][d] = 0;
        }
    }
    int lo = 0;
    if(tlo == 1){
        lo = l[level]-'0';
    }
    int hi = 9;
    if(thi == 1){
        hi = r[level]-'0';
    }
    int ans = 0;
    for(int i=lo; i<=hi; i++){
        int ntlo = tlo;
        if(i!=l[level]-'0'){
            ntlo = 0;
        }
        int nthi = thi;
        if(i!=r[level]-'0'){
            nthi = 0;
        }
        ans += rec(level+1, ntlo, nthi, (d+i)%D);
        ans %= mod;
        ans += mod;
        ans %= mod;
    }
    return dp[level][tlo][thi][d] = ans;
}

void solve()
{
    // cin>>r;
    // l = "1";
    cin>>l>>r;
    int temp = r.length() - l.length();
    string s="";
    while(temp--){
        s += '0';
    }
    l = s + l;
    len = r.length();
    cin>>D;
    dp = vvvvi(len+1, vvvi(2, vvi(2, vi(D,-1))));
    int ans = rec(0, 1, 1, 0);
    cout<<ans<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}