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

pii doublequickhash(string &s, int p1=29, int p2=31, int mod1=999999929, int mod2=999999937){
    return make_pair(quickhash(s, p1, mod1),quickhash(s, p2, mod2));
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

struct doublehash{
    hasher hash1, hash2;
    string s;
    void init(string s_, int p1=29, int p2=31, int mod1=999999929, int mod2=999999937){
        hash1.init(s_, p1, mod1);
        hash2.init(s_, p2, mod2);
        s = s_;
    }
    pii getfhash(int l, int r){
        return make_pair(hash1.getfhash(l,r),hash2.getfhash(l,r));
    }
};

void solve()
{
    string s;
    // for(int i=0; i<1000; i++){
    //     s += ('a'+(rand()%26));
    // }
    cin>>s;
    cout<<"QuickHash = "<<'['<<doublequickhash(s).first<<','<<doublequickhash(s).second<<']'<<endl;
    doublehash shash;
    shash.init(s);
    map<pii,set<string>> mp;
    int n=s.length();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            mp[shash.getfhash(i,j)].insert(s.substr(i,j-i+1));
            cout<<'('<<shash.getfhash(i,j).first<<','<<shash.getfhash(i,j).second<<')'<<' ';
        }cout<<endl;
    }cout<<endl;
    int numfailed=0;
    for(auto x:mp){
        if(x.second.size() > 1){
            numfailed++;
            // cout<<"Hash failed"<<endl;
        }
    }
    cout<<"Number of hashes repeated = "<<numfailed<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}