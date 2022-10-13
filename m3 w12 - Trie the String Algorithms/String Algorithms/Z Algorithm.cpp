#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

void zalgo(string &s, vi &z){
    int n=s.length();
    z.resize(n);
    z[0] = -1;
    int l=0, r=0;
    for(int i=1; i<n; i++){
        if(i<=r){
            z[i] = min(r-i+1, z[i-l]);
        }
        while(i+z[i]<n && s[z[i]] == s[i+z[i]]) z[i]++;
        if(i+z[i] > r){
            l = i;
            r = i+z[i]-1;
        }
    }
}

void solve()
{
    string s;
    cin>>s;
    vi z;
    zalgo(s, z);
    for(auto x:z){
        cout<<x<<' ';
    }
    cout<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}