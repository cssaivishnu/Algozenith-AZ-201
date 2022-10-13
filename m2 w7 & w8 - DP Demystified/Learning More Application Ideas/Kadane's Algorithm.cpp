#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define int_min (-1e9)

int n, a[1001001];

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans = int_min;
    int max_ending_here=0;
    for(int i=0; i<n; i++){
        max_ending_here += a[i];
        ans = max(ans,max_ending_here);
        int zero=0;
        max_ending_here = max(zero,max_ending_here);
    }
    cout<<ans<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}