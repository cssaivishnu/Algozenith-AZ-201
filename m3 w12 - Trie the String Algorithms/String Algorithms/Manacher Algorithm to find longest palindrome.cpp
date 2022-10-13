#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

void manacher(string &s, vi &m){
    int n=s.length();
    m.assign(n,0);
    int c=1, r=1;
    for(int i=2; i<n; i++){
        int mirr = 2*c - i;
        if(i < r){
            m[i] = min(m[mirr],r-i);
        }
        while(s[i+m[i]+1] == s[i-m[i]-1])   m[i]++;
        if(i+m[i] > r){
            c = i;
            r = i+m[i];
        }
    }
}

void solve()
{
    string s, cs;
    cin>>s;
    vi m;
    cs = "*#";
    for(auto x:s){
        cs += x;
        cs += "#";
    }
    cs += "@";
    manacher(cs, m);
    cout<<cs<<endl;
    for(auto x:m){
        cout<<x;
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