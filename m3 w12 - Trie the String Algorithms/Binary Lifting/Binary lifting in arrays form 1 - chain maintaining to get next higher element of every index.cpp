#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n;
vi arr;
vvi dp;

void solve()
{
    cin>>n;
    arr = vi(n+1);
    dp = vvi(n+1, vi(20, 0));
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    arr[n] = 1e9+1;
    stack<int> s;
    s.push(0);
    for(int i=1; i<=n; i++){
        while(!s.empty() && arr[s.top()]<arr[i]){
            dp[s.top()][0] = i;
            s.pop();
        }
        s.push(i);
    }
    dp[n][0] = n;
    for(int i=0; i<=n; i++){
        cout<<i<<' '<<dp[i][0]<<endl;
    }cout<<endl;
    for(int i=1; i<20; i++){
        for(int j=0; j<=n; j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    // for(int i=0; i<=n; i++){
    //     cout<<i<<' '<<dp[i][1]<<endl;
    // }
    // for(int i=0; i<=n; i++){
    //     cout<<i<<' '<<dp[i][2]<<endl;
    // }
    int q;
    cin>>q;
    while(q--){
        int pos, num;
        cin>>pos>>num;
        int temp = pos;
        for(int i=19; i>=0; i--){
            if((num>>i)&1){
                pos = dp[pos][i];
            }
        }
        cout<<"arr["<<temp<<"]="<<arr[temp]<<" - "<<"arr["<<pos<<"]="<<arr[pos]<<endl;
    }
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// 10
// 5 7 3 2 1 4 5 2 6 7
// 4
// 0 1
// 3 3
// 4 4
// 7 2

// 0 1
// 1 10
// 2 5
// 3 5
// 4 5
// 5 6
// 6 8
// 7 8
// 8 9
// 9 10
// 10 10

// arr[0]=5 - arr[1]=7
// arr[3]=2 - arr[8]=6
// arr[4]=1 - arr[9]=7
// arr[7]=2 - arr[9]=7