#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

int n;
map<int,int> mp;
vector<int> cur_perm;

vector<vector<int>> allSol;

void rec(int level){
    for(int i=0; i<level; i++){
        cout<<cur_perm[i]<<" ";
    }cout<<endl;
    if(level == n){
        allSol.push_back(cur_perm);
        return;
    }
    for(auto v:mp){
        if(v.second != 0){
            mp[v.first]--;
            cur_perm.push_back(v.first);
            rec(level+1);
            cur_perm.pop_back();
            mp[v.first]++;
        }
    }
}

void solve()
{
    int i;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    rec(0);
    cout<<endl;
    for(int i=0; i<allSol.size(); i++){
        for(int j=0; j<n; j++){
            cout<<allSol[i][j]<<" ";
        }cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}