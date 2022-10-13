#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    vector<int> arr={2,3,5,7};
    for(int mask=0; mask<(1<<4); mask++){
        for(int submask=mask; ; submask = (submask-1)&mask){
            cout<<"{ ";
            for(int i=0; i<4; i++){
                if((submask>>i)&1){
                    cout<<arr[i]<<" ";
                }
            }
            cout<<"} ";
            if(!submask){
                break;
            }
        }
        cout<<endl;
    }
}

// { } 
// { 2 } { } 
// { 3 } { } 
// { 2 3 } { 3 } { 2 } { } 
// { 5 } { } 
// { 2 5 } { 5 } { 2 } { } 
// { 3 5 } { 5 } { 3 } { } 
// { 2 3 5 } { 3 5 } { 2 5 } { 5 } { 2 3 } { 3 } { 2 } { } 
// { 7 } { } 
// { 2 7 } { 7 } { 2 } { } 
// { 3 7 } { 7 } { 3 } { } 
// { 2 3 7 } { 3 7 } { 2 7 } { 7 } { 2 3 } { 3 } { 2 } { } 
// { 5 7 } { 7 } { 5 } { } 
// { 2 5 7 } { 5 7 } { 2 7 } { 7 } { 2 5 } { 5 } { 2 } { } 
// { 3 5 7 } { 5 7 } { 3 7 } { 7 } { 3 5 } { 5 } { 3 } { } 
// { 2 3 5 7 } { 3 5 7 } { 2 5 7 } { 5 7 } { 2 3 7 } { 3 7 } { 2 7 } { 7 } { 2 3 5 } { 3 5 } { 2 5 } { 5 } { 2 3 } { 3 } { 2 } { }

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}