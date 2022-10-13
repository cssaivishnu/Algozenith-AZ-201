#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long
#define minusinf -1000000000

struct mode
{
    map<lli,lli> mp;                // mp[key] = freq
    set<pair<lli,lli>> freqmap;     // <freq, key>
    void insert(lli x)
    {
        if(mp.find(x) != mp.end())
            freqmap.erase(make_pair(mp[x],x));
        mp[x]++;
        freqmap.insert(make_pair(mp[x],x));
    }
    void remove(lli x)
    {
        freqmap.erase(make_pair(mp[x],x));
        mp[x]--;
        if(mp[x] == 0)
            mp.erase(x);
        else
            freqmap.insert(make_pair(mp[x],x));
    }
    double getMode()
    {
        auto it = freqmap.end(); it--;
        lli fmax = it->first;
        it = freqmap.lower_bound(make_pair(fmax,minusinf));
        return it->second;
    }
};

void solve()
{
    mode m;
    m.insert(3);
    cout<<"Mode = "<<m.getMode()<<endl;
    m.insert(6);
    cout<<"Mode = "<<m.getMode()<<endl;
    m.insert(3);
    cout<<"Mode = "<<m.getMode()<<endl;
    m.remove(6);
    cout<<"Mode = "<<m.getMode()<<endl;
    m.insert(2);
    cout<<"Mode = "<<m.getMode()<<endl;
    m.remove(3);
    cout<<"Mode = "<<m.getMode()<<endl;
    m.insert(2);
    cout<<"Mode = "<<m.getMode()<<endl;
    m.insert(8);
    cout<<"Mode = "<<m.getMode()<<endl;
    m.insert(8);
    cout<<"Mode = "<<m.getMode()<<endl;
    m.remove(2);
    cout<<"Mode = "<<m.getMode()<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// Mode = 3
// Mode = 3
// Mode = 3
// Mode = 3
// Mode = 3
// Mode = 2
// Mode = 2
// Mode = 2
// Mode = 2
// Mode = 8