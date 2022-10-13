#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    int n, i, cnt;
    cin>>n;             // n > 2
    int is_prime[n+1];
    for(i=2; i<=n; i++){
        is_prime[i] = 1;
    }
    for(i=2; i<=n; i++){
        if(is_prime[i]){
            for(lli j=1LL*i*i; j<=n; j+=i){
                is_prime[j] = 0;
            }
        }
    }
    for(i=2; i<=n; i++){
        cout<<is_prime[i]<<" ";
    }
    cout<<endl;
}

// complexity = sum of floor of (n/p) for all primes p <= n = O(n*loglogn)
// fact:        sum of floor of (n/i) for all i <= n        = O(n*logn)

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}