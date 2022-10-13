#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n;
    cin>>n;
    lli a[n];
    map<lli,vector<lli>> mp;
    for(lli i=0; i<n; i++){
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    vector<pair<lli,pair<lli,vector<lli>>>> p;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        vector<lli> v=it->second;
        lli val = it->first;
        lli freq=v.size();
        p.push_back({freq,{val,v}});
    }
    sort(p.rbegin(),p.rend());
    lli fmax = p[0].first;
    vector<pair<lli,lli>> vec;
    for(auto it=p.begin(); it!=p.end(); it++){
        lli freq=it->first;
        lli val = (*it).second.first;
        vector<lli> v = (*it).second.second;
        for(lli i=0; i<freq; i++){
            vec.push_back({val,v[i]});
        }
    }
    vector<pair<lli,lli>> svec;
    for(lli i=fmax; i<n; i++){
        svec.push_back(vec[i]);
    }
    for(lli i=0; i<fmax; i++){
        svec.push_back(vec[i]);
    }
    lli ans[n];
    for(lli i=0; i<n; i++){
        ans[vec[i].second] = svec[i].first;
    }

    lli answer = min(n,2*(n-fmax));
    cout<<answer<<" "<<fmax<<endl;
for(lli i=0; i<n; i++){
    cout<<ans[i]<<" ";
}cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}