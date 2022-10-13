#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
	string s="", ss="";
	int i;
	for(i=0; i<10; i++)
		s = s + (char)('a'+i);			// O(|s|)!!!!!!!!!
	for(i=0; i<10; i++)
		ss += (char)('a'+i);				// O(1)
	cout<<s<<endl<<ss<<endl;
	cout<<s.substr(3,2)<<endl<<ss.substr(3,2)<<endl;
	int x = 234;
	s = to_string(234);
	cout<<s<<endl;
	s = "1234";
	x = stoi(s);
	cout<<x<<endl;
}			//hence, always use a o= b, for a = a o b, where o is any operator

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
}