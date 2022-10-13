#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lli long long

void solve()
{
    stack<lli> s;
    lli i, len;
    string st;
    cin>>st;
    map<char,lli> mp;
    mp['('] = 0;
    mp['['] = 1;
    mp['{'] = 2;
    mp[')'] = 3;
    mp[']'] = 4;
    mp['}'] = 5;
    lli flag = 1;
    len = st.size();
    for(i=0; i<len; i++)
    {
        if(mp[st[i]] < 3)
            s.push(mp[st[i]]);
        else
        {
            auto top = s.top();
            if(top != (mp[st[i]]-3))
            {
                flag = 0;
                break;
            }
            s.pop();
        }
    }
    if(!s.empty())
        flag = 0;
    if(flag == 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
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
// ({[]})
// ([]{}([{[]}]))
// {}()(}){}

// OUTPUT
// YES
// YES
// NO