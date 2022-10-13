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

int check(hasher &shash1, hasher &shash2, int n1, int n2, int len){
    map<int,int> mp;
    for(int i=0; ; i++){
        if(i+len-1 == n1)    break;
        mp[shash1.getfhash(i,i+len-1)]++;
    }
    for(int i=0; ; i++){
        if(i+len-1 == n2)   break;
        if(mp[shash2.getfhash(i,i+len-1)] > 0){
            return 1;
        }
    }
    return 0;
}

void solve()
{
    string s1, s2;
    cin>>s1>>s2;
    hasher shash1;
    shash1.init(s1, 29, 999999937);
    hasher shash2;
    shash2.init(s2, 29, 999999937);
    int n1=s1.length();
    int n2=s2.length();
    int ans=0;
    int lo=0;
    int hi=min(n1,n2);
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(shash1, shash2, n1, n2, mid)){
            ans=mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
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