#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

/*

rec(level,sumleft) = rec(level,sumleft-a[level])+rec(level+1,sumleft)
call    ->  rec(0,n)
a[] = {1,2,3,4,.....,n}

example : 4 -> 1+1+1+1, 1+1+2, 1+3, 2+2, 4  -> 5 ways

*/

void solve()
{
    
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}