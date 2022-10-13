#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lli long long

void solve()
{
    lli i, n, depth=0;
    string s;
    cin>>s;
    n = s.size();
    for(i=0; i<n; i++)
    {
        if(s[i] == '(')
            depth++;
        else
        {
            depth--;
            if(depth < 0)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    if(depth < 0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}

// INPUT
// 3
// ()()(())
// (())()(()())()
// ())(()())((

// OUTPUT
// YES
// YES
// NO