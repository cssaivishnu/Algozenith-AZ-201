#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n, i, k;
    cin>>n>>k;
    vector<int> v(n);
    for(i=0; i<n; i++)
        cin>>v[i];
    multiset<lli> ms;
    for(i=0; i<k-1; i++)
        ms.insert(v[i]);
    for(i=k-1; i<n; i++)
    {
        ms.insert(v[i]);
        auto it = ms.begin();
        cout<<*it<<" ";
        ms.erase(ms.find(v[i-k+1]));
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}

// 1
// 10 4
// 5 3 2 7 1 8 6 8 2 3

// 2 1 1 1 1 2 2