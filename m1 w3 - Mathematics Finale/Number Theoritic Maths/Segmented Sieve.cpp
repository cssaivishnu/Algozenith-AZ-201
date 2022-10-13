#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli a, b, i, cnt, curMul;
    cin>>a>>b;             // b-a <= 10^6, 1<=a,b<=10^12
    lli rootb=sqrt(b);
    lli is_prime[rootb+1];
    for(i=2; i<=rootb; i++){
        is_prime[i] = 1;
    }
    for(i=2; i<=rootb; i++){                        // O(sqrt(b))
        if(is_prime[i]){
            for(lli j=1LL*i*i; j<=rootb; j+=i){
                is_prime[j] = 0;
            }
        }
    }
    lli prime[b-a+1];
    for(i=0; i<=b-a; i++){
        prime[i] = 1;
    }
    for(i=2; i<=rootb; i++){                        // O((b-a)*loglogb)
        if(is_prime[i] == 1){
            lli curMul = ((a+i-1)/i)*i;
            while(curMul <= b){
                if(curMul != i){
                    prime[curMul-a] = 0;
                }
                curMul += i;
            }
        }
    }
    for(i=0; i<=b-a; i++){
        cout<<i+a<<" "<<prime[i]<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}