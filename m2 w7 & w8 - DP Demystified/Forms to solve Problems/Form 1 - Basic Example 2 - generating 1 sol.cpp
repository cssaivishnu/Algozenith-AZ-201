#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

int n, q;
int x[101];
bool dp[100][100100];
bool saved[100][100100];

bool rec(int level, int sneeded){
    // pruning
    if(sneeded < 0){
        return 0;
    }

    // base case code
    if(level == n){
        if(sneeded == 0){
            return 1;
        }
        return 0;
    }

    // cache check
    if(saved[level][sneeded]){
        return dp[level][sneeded];
    }

    // transitions
    bool ans = (rec(level+1,sneeded)) || (rec(level+1,sneeded-x[level]));
    saved[level][sneeded] = 1;

    // save and return
    return dp[level][sneeded] = ans;
}

vector<int> vec;
void generate(int level, int sneeded){
    if(level == n){
        return;
    }
    if(rec(level+1,sneeded)){
        generate(level+1,sneeded);
    }else{
        vec.push_back(x[level]);
        generate(level+1,sneeded-x[level]);
    }
}

void solve()
{
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    memset(dp,0,sizeof(dp));
    memset(saved,0,sizeof(saved));
    while(q--){
        int y;
        cin>>y;
        cout<<rec(0,y)<<endl;
        if(rec(0,y)){
            generate(0,y);
            for(auto a: vec){
                cout<<a<<" ";
            }cout<<endl<<endl;
        }
        vec.clear();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}