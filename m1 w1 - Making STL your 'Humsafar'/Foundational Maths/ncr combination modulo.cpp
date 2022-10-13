#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

int f[200000];

int binary_exponentiation(int a, int b, int mod){
    int ans = 1;
    while(b){
        if(b%2 == 1){
            ans = (1LL*(ans%mod)*(a%mod)) % mod;
        }
        a = (1LL*(a%mod)*(a%mod)) % mod;
        b /= 2;
    }
    return ans;
}

int mod_inverse(int a, int mod){
    return binary_exponentiation(a,mod-2,mod);
}

int ncr(int n, int r){
    int a, b, c, ans, mod=1e9+7;
    a = f[n];
    b = f[n-r];
    c = f[r];
    b = mod_inverse(b,1e9+7);
    c = mod_inverse(c,1e9+7);
    ans = (1LL*a*b)%mod;
    ans = (1LL*ans*c)%mod;
    return ans;
}

void facto(){
    int i, mod=1e9+7;
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    f[3] = 6;
    for(i=4; i<200000; i++){
        f[i] = (1LL*i*f[i-i])%mod;
    }
}

void solve()
{
    facto();
    int a, b;
    cin>>a>>b;                                          // 1625 625
    cout<<ncr(a,b)<<endl;                               // 428200003
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}