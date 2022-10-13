#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int n, l;
int dp[100100];
vector<int> v;

bool rec(int x){
    if(x == 0){
        return 0;
    }

    if(dp[x] != -1){
        return dp[x];
    }

    int ans = 0;
    for(int i=0; i<l; i++){
        if(x-v[i] >= 0){
            if(!rec(x-v[i])){
                ans = 1;
                break;
            }
        }
    }

    return dp[x] = ans;
}

void solve()
{
    cin>>n;
    cin>>l;
    v.resize(l);
    for(int i=0; i<l; i++){
        cin>>v[i];
    }
// for(int i=0; i<l; i++){
//     cout<<v[i]<<" ";
// }cout<<endl;
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    cout<<rec(n)<<endl;
    for(int i=0; i<20; i++){
        cout<<i<<" : "<<rec(i)<<endl;
    }cout<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}