#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(int t)
{
	int n, m, o, i, j, k;
    cin>>n>>m>>o;
    for(i=0; i<n; i++)
    {
        for(k=0; k<((o+1)*m+1); k++)
            cout<<"*";
        cout<<endl;
        for(j=1; j<=o; j++)
        {
            for(k=0; k<((o+1)*m+1); k++)
            {
                if(k%m == 0)
                    cout<<"*";
                else if(((k/m)%2 == 0  &&  i%2 == 0) || ((k/m)%2 == 1  &&  i%2 == 1))
                {
					if(k%m == j)
                        cout<<"\\";
                    else
                        cout<<".";
                }
                else if(((k/m)%2 == 1  &&  i%2 == 0) || ((k/m)%2 == 0  &&  i%2 == 1))
                {
					if(((k%m)+j) == o+1)
                        cout<<"/";
                    else
                        cout<<".";
                }
            }
            cout<<endl;
        }
    }
    for(k=0; k<((o+1)*m+1); k++)
        cout<<"*";
    cout<<endl<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int _t; cin>>_t; while(_t--)
	solve(_t);
}