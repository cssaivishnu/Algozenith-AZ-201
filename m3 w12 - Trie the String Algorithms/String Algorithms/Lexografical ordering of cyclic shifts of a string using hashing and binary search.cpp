#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>

int quickhash(string &s, int p=29, int mod=1e9+7){
    int ans = (s[0]-'a'+1);
    int n=s.length();
    for(int i=1; i<n; i++){
        ans = (ans*p + (s[i]-'a'+1))%mod;
    }
    ans = (ans+mod)%mod;
    return ans;
}

struct hasher{
    string s;
    vector<int> fhash, ppowerk;
    int n, p, mod;
    void init(string s_, int p_, int mod_){
        s = s_;
        p = p_;
        mod = mod_;
        n = s.length();
        fhash.resize(n);
        ppowerk.resize(n);
        fhash[0] = (s[0]-'a'+1);
        ppowerk[0] = 1;
        for(int i=1; i<n; i++){
            fhash[i] = (fhash[i-1]*p + (s[i]-'a'+1))%mod;
            fhash[i] = (fhash[i]+mod)%mod;
            ppowerk[i] = ((ppowerk[i-1]*p)%mod+mod)%mod;
        }
    }
    int getfhash(int l, int r){     // s[l...r]
        if(l == 0){
            return fhash[r];
        }
        return ((fhash[r] - fhash[l-1]*ppowerk[r-l+1])%mod+mod)%mod;
    }
};

string cmps;
int cmpn;
hasher cmphash;

bool cmp(int l, int r){
    int lo = 1, hi = cmpn-1;
    int ans = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(cmphash.getfhash(l,l+mid-1) == cmphash.getfhash(r,r+mid-1)){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return cmps[l+ans] < cmps[r+ans];
}

void solve()
{
    string s;
    cin>>s;
    int n = s.length();
    s = s+s;
    hasher shash;
    shash.init(s, 29, 999999937);
    vi final;
    for(int i=0; i<n; i++){
        final.push_back(i);
    }
    cmps = s;
    cmpn = n;
    cmphash = shash;
    sort(final.begin(),final.end(),cmp);
    for(auto x:final){
        cout<<x<<' '<<s.substr(x,n)<<endl;
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