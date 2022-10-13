#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    vector<int> arr={2,3,5};
    for(int mask=0; mask<(1<<3); mask++){
        cout<<"{ ";
        for(int i=0; i<3; i++){
            if(mask & (1<<i)){
                cout<<arr[i]<<" ";
            }
        }
        cout<<"}"<<endl;
    }
}

// (i<<j) -> i * (2 power j)
// (1011<<5) = 101100000

// (i<<j) -> i / (2 power j)        (integer division)
// (1001011>>3) = 1001

// check ith position of m: (m>>i)&1
// flip ith bit of m: m^(1<<i)
// set ith bit of m to 0: m&(~(1<<i)) or m^(m&(1<<i))
// set ith bit of m to 1: m|(1<<i)
// first setbit of x (lsb): x&(~(x-1))

// { }
// { 2 }
// { 3 }
// { 2 3 }
// { 5 }
// { 2 5 }
// { 3 5 }
// { 2 3 5 }

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}