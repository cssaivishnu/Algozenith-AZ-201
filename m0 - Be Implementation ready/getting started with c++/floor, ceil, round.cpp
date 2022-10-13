#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve()
{
	int a, b;
	cin>>a>>b;
	cout<<a/b<<endl;
	cout<<(a+b-1)/b<<endl;
	cout<<(2*a+b)/(2*b)<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	// int _t; cin>>_t; while(_t--)
	solve();
} 