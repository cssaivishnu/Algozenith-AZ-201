#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

bool cmp(pair<lli,lli> &x, pair<lli,lli> &y)
{
    return ((x.first+x.second) > (y.first+y.second));
}

void solve()
{
    lli i, n;
    cin>>n;
    lli a[n],b[n];
    vector<pair<lli,lli>> c(n);
    for(i=0; i<n; i++)
        cin>>a[i];
    for(i=0; i<n; i++)
        cin>>b[i];
    for(i=0; i<n; i++)
        c[i] = {a[i],b[i]};
    sort(c.begin(),c.end(),cmp);
    lli ascore=0, bscore=0;
    for(i=0; i<n; i++)
    {
        if(i%2 == 0)
            ascore += c[i].first;
        else
            bscore += c[i].second;
    }
    cout<<ascore-bscore<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// 5
// 1 5 2 8 3
// 9 1 6 2 3

// 3