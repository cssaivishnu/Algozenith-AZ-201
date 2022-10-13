#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    int n, i, cnt;
    cin>>n;             // n > 2
    vector<pair<int,int>> p;
    for(i=2; i*i<=n; i++){
        if(n%i == 0){
            cnt = 0;
            while(n%i == 0){
                cnt++;
                n /= i;
            }
            p.push_back({i,cnt});
        }
    }
    if(n != 1){
        p.push_back({n,1});
    }
    for(i=0; i<(int)(p.size()); i++){
        cout<<p[i].first<<" -> "<<p[i].second<<endl;;
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}