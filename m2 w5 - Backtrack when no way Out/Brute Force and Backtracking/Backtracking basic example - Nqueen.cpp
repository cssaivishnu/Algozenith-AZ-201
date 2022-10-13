#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

int n;

vector<int> queen;
int ans=0;

bool check(int row, int col){
    for(int prow=0; prow<row; prow++){
        int pcol = queen[prow];
        if(pcol == col){
            return 0;
        }
        if(abs(pcol-col) == abs(prow-row)){
            return 0;
        }
    }
    return 1;
}

void rec(int level){
    for(int i=0; i<level; i++){
        cout<<queen[i]<<" ";
    }
    cout<<endl;
    if(level == n){
        cout<<"Solution above"<<endl<<endl;
        ans++;
    }
    for(int col=0; col<n; col++){
        if(check(level,col)){
            queen.push_back(col);
            rec(level+1);
            queen.pop_back();
        }
    }
}

void solve()
{
    cin>>n;
    rec(0);
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}