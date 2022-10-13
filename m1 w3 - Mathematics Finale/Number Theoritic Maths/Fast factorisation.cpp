#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n, q, i, j, x;
    cin>>n>>q;
    lli smallestPrime[n+1];
    for(i=2; i<=n; i++){
        smallestPrime[i] = i;
    }
    for(i=2; i<=n; i++){
        if(smallestPrime[i] == i){                      // O(n*loglogn)
            for(j=2*i; j<=n; j+=i){
                if(smallestPrime[j] == j){
                    smallestPrime[j] = i;
                }
            }
        }
    }
    while(q--){                                         // O(q*logn)
        cin>>x;
        vector<int> v;
        cout<<x<<": ";
        while(x > 1){
            v.push_back(smallestPrime[x]);
            x /= smallestPrime[x];
        }
        cout<<v[0];
        for(i=1; i<(int)v.size(); i++){
            cout<<"*"<<v[i];
        }
        cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}