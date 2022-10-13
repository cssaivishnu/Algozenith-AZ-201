#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    int n, l, r;
    cin>>n;
    vector<pair<int,int>> events;
    for(int i=0; i<n; i++){
        cin>>l>>r;
        events.push_back({l,+1});
        events.push_back({r,-1});
    }
    sort(events.begin(),events.end());
    int cnt=0;
    int ans=0;
    for(int i=0; i<(int)events.size()-1; i++){
        cnt += events[i].second;
        if(cnt > 0){
            ans += events[i+1].first - events[i].first;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}