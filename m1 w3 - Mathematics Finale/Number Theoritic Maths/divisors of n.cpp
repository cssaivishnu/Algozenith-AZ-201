#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n, i;
    cin>>n;             // n >= 2
    if(n == 1){
        cout<<"1"<<endl;
        return;
    }
    if(n == 2){
        cout<<"1 2"<<endl;
        return;
    }
    vector<int> v;
    v.push_back(1);
    v.push_back(n);
    for(i=2; i*i<=n; i++){
        if(n%i == 0){
            if(n == i*i){
                v.push_back(i);
            }
            else{
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(),v.end());
    lli len = v.size();
    for(i=0; i<len; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}