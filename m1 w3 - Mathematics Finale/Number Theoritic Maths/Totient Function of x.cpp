#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

// number of coprimes of x in [1,x]

void solve()
{
    lli n, q, i, j, xx, xxtemp;
    cin>>n>>q;
    lli smallestPrime[n+1];
    for(i=2; i<=n; i++){
        smallestPrime[i] = i;
    }
    for(i=2; i<=n; i++){
        if(smallestPrime[i] == i){
            for(j=2*i; j<=n; j+=i){
                if(smallestPrime[j] == j){
                    smallestPrime[j] = i;
                }
            }
        }
    }
    while(q--){
        cin>>xx;
        xxtemp = xx;
        vector<lli> v;
        while(xx > 1){
            v.push_back(smallestPrime[xx]);
            xx /= smallestPrime[xx];
        }
        xx = xxtemp;
        lli nod=v.size(), sod;
        vector<pair<lli,lli>> p;
        lli x, y;
        x = v[0]; y = 1;
        for(i=1; i<nod; i++){
            if(x == v[i]){
                y++;
            }
            else{
                p.push_back({x,y});
                y = 1;
                x = v[i];
            }
        }
        p.push_back({x,y});
        lli totient = xx;
        lli len = p.size();
        for(i=0; i<len; i++){
            totient -= (totient)/p[i].first;
        }
        cout<<"Totient function of "<<xx<<" = "<<totient<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}