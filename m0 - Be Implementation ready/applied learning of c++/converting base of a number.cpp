#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
	int a, b, i, len;
    long long num, x;
    string s;
    cin>>s>>a>>b;
    len = s.size();
    num = 0;
    x = 1;
    for(i=len-1; i>=0; i--)
    {
        if(s[i]>='0' && s[i]<='9')
            num += x*(s[i]-'0');
        else
            num += x*(s[i]-'A'+10);
        x *= a;
    }
    string ans="";
    while(true)
    {
        if(num == 0)
            break;
        i = num%b;
        if(i >= 10)
            ans += (char)('A'+i-10);
        else
            ans += (char)('0'+i);
        num /= b;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int _t; cin>>_t; while(_t--)
	solve();
}