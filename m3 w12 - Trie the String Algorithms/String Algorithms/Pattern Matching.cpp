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
    string s, p;
    cin>>s>>p;
    vi kmp;
    string scomb = p + '#' + s;
    getkmp(scomb, kmp);
    int plen = p.length();
    int slen = s.length();
    int scomblen = scomb.length();
    int count=0;
    for(int i=plen+2; i<=scomblen; i++){
        if(kmp[i] == plen){
            cout<<i-2*plen-1<<'-'<<i-plen-2<<endl;
            count++;
        }
    }
    cout<<"Number of patterns = "<<count<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}