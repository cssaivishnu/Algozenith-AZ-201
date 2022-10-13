#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    int i=0, j=-1;
    vi kmp(n+1,-1);
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j = kmp[j];
        }
        i++;j++;
        kmp[i] = j;
    }
    for(int i=1; i<=n; i++){
        cout<<kmp[i]<<' ';
    }cout<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}