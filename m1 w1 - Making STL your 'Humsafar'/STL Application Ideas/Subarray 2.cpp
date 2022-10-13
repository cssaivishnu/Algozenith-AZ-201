#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n, i, k;
    cin>>n>>k;
    vector<lli> v(n);
    deque<lli> dq;
    for(i=0; i<n; i++)
        cin>>v[i];
    for(i=0; i<n; i++)
    {
        while(!dq.empty() && dq.back() > v[i])
            dq.pop_back();
        dq.push_back(v[i]);
        if(i>=k-1)
            cout<<dq.front()<<" ";
        if(dq.front() == v[i-k+1])
            dq.pop_front();
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