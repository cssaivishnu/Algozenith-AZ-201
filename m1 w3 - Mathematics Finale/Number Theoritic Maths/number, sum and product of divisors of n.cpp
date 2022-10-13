#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n, q, i, j, xx, xxtemp;
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
        cin>>xx;
        xxtemp = xx;
        vector<lli> v;
        while(xx > 1){
            v.push_back(smallestPrime[xx]);
            xx /= smallestPrime[xx];
        }
        xx = xxtemp;
        lli nod=v.size(), sod, pod;
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
        sod = 1;
        nod = 1;
        lli len = p.size();
        for(i=0; i<len; i++){
            sod *= ((lli)pow(p[i].first,p[i].second+1)-1)/(p[i].first-1);
            nod *= (1+p[i].second);
        }
        cout<<"Number of Divisors of "<<xx<<" (including 1 and "<<xx<<") = "<<nod<<endl;
        cout<<"Sum of all Divisors (including 1 and "<<xx<<") = "<<sod<<endl;
        if(nod%2 == 1){
            lli g = sqrt(xx);
            cout<<"Product of all Divisors (including 1 and "<<xx<<") = "<<pow(g,nod)<<endl<<endl;
            // pod = pow(g,nod);
        }
        else{
            lli g = nod/2;
            cout<<"Product of all Divisors (including 1 and "<<xx<<") = "<<pow(xx,g)<<endl<<endl;
            // pod = pow(xx,g);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}