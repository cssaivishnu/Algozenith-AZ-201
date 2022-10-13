#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n, i, q, y, sum;
    cin>>n;
    vector<lli> l(n),r(n);
    for(i=0; i<n; i++){
        cin>>l[i]>>r[i];
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    cin>>q;
    for(i=0; i<q; i++){
        cin>>y;
        sum = 0;
        auto it = upper_bound(l.begin(),l.end(),y);
        sum += (l.end() - it);
        it = lower_bound(r.begin(),r.end(),y);
        sum += (it-r.begin());
        sum = n - sum;
        cout<<sum<<" ";
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


// 3
// 2 6
// 3 5
// 4 7
// 8
// 1 2 3 4 5 6 7 8

// 0 1 2 3 3 2 1 0