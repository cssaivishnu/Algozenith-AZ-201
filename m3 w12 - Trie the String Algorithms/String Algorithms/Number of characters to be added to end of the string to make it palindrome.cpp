#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

void getkmp(string &s, vi &kmp){
    int n=s.length();
    int i=0, j=-1;
    kmp.assign(n+1,-1);
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j = kmp[j];
        }
        i++;j++;
        kmp[i] = j;
    }
    // for(int i=1; i<=n; i++){
    //     cout<<kmp[i]<<' ';
    // }cout<<endl;
}

void solve()
{
    string s, revs;
    cin>>revs;
    s = revs;
    reverse(revs.begin(),revs.end());
    string scomb = revs + '#' + s;
    vi kmp;
    getkmp(scomb, kmp);
    int slen = s.length();
    int scomblen = scomb.length();
    int ans=slen-kmp[scomblen];
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