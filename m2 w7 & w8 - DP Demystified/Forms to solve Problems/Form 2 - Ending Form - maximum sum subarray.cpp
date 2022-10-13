#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, a[100100], dp[100100];
bool done[100100];

int rec(int level){
    // pruning and base case check
    if(level < 0){
        return 0;
    }

    // cache check
    if(done[level]){
        return dp[level];
    }

    // transitions
    int ans = max(a[level],a[level]+rec(level-1));

    // save and return
    done[level] = 1;
    return dp[level] = ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    memset(done,0,sizeof(done));
    int ans=rec(0);
    for(int i=1; i<n; i++){
        ans = max(ans,rec(i));
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}