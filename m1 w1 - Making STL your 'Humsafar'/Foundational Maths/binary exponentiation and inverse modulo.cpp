#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

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

void solve()
{
    int a, b, mod=1e9+7;
    cin>>a>>b;                                          // 2 100
    cout<<binary_exponentiation(a,b,1e9+7)<<endl;       // 976371285
    cout<<mod_inverse(a,1e9+7)<<endl;                   // 500000004
    cout<<endl;

    int c = (4*mod_inverse(12,1e9+7));
    c = c%mod;
    cout<<c<<endl;                                      // 333333336
    int d = (6*mod_inverse(18,1e9+7));
    d = d%mod;
    cout<<d<<endl;                                      // 333333336
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}