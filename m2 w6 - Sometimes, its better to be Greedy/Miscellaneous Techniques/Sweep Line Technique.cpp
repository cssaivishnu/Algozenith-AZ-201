#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    int n, l, r, x;
    cin>>n;
    vector<pair<int,pair<int,int>>> events;
    for(int i=0; i<n; i++){
        cin>>l>>r>>x;
        events.push_back({l,{0,x}});
        events.push_back({r,{2,x}});
    }
    int q;
    cin>>q;
    for(int m=0; m<q; m++){
        int y;
        cin>>y;
        events.push_back({y,{1,m}});
    }
    int ans[q];
    sort(events.begin(),events.end());
    multiset<int> mt;
    for(int i=0; i<(int)events.size(); i++){
        if(events[i].second.first == 0){
            mt.insert(events[i].second.second);
        }else if(events[i].second.first == 2){
            mt.erase(mt.find(events[i].second.second));
        }else{
            if(mt.empty()){
                ans[events[i].second.second] = -1;
            }else{
                ans[events[i].second.second] = *mt.rbegin();
            }
        }
    }
    for(int i=0; i<q; i++){
        cout<<ans[i]<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}