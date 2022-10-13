#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lli long long

void solve()
{
    lli i, q, n, l, r, j;
    string s;
    cin>>s;
    n = s.size();
    lli depth[n+1];
    depth[0] = 0;
    for(i=0; i<n; i++)
        if(s[i] == '(')
            depth[i+1] = depth[i]+1;
        else
            depth[i+1] = depth[i]-1;
    lli flag=1;
    for(i=0; i<=n; i++)
        if(depth[i] < 0)
            flag = 0;
    if(depth[n] != 0)
        flag = 0;
    if(flag == 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    cin>>q;
    for(j=0; j<q; j++)
    {
        cin>>l>>r;
        flag = 1;
        if(depth[l] != depth[r+1])
            flag = 0;
        if(flag == 1)
        {
            for(i=l; i<=r+1; i++)
            {
                if(depth[i] < depth[l])
                {
                    flag = 0;
                    break;
                }
            }
        }
        cout<<"l="<<l<<", r="<<r<<", answer=";
        if(flag == 0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}


// INPUT
// 1
// ()()(())
// 3
// 1 5
// 2 7
// 3 4

// OUTPUT
// YES
// l=1, r=5, answer=NO
// l=2, r=7, answer=YES
// l=3, r=4, answer=NO