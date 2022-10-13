#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

struct mean
{
    lli sum=0, n=0;
    void insert(lli x)
    {
        sum += x;
        n += 1;
    }
    void remove(lli x)
    {
        sum -= x;
        n -= 1;
    }
    double getMean()
    {
        return ((double)(sum))/n;
    }
};

void solve()
{
    mean m;
    m.insert(3);
    cout<<"Mean = "<<m.getMean()<<endl;
    m.insert(6);
    cout<<"Mean = "<<m.getMean()<<endl;
    m.insert(1);
    cout<<"Mean = "<<m.getMean()<<endl;
    m.remove(6);
    cout<<"Mean = "<<m.getMean()<<endl;
    m.insert(2);
    cout<<"Mean = "<<m.getMean()<<endl;
    m.remove(3);
    cout<<"Mean = "<<m.getMean()<<endl;
    m.insert(9);
    cout<<"Mean = "<<m.getMean()<<endl;
    m.insert(8);
    cout<<"Mean = "<<m.getMean()<<endl;
    m.remove(9);
    cout<<"Mean = "<<m.getMean()<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// Mean = 3
// Mean = 4.5
// Mean = 3.33333
// Mean = 2
// Mean = 2
// Mean = 1.5
// Mean = 4
// Mean = 5
// Mean = 3.66667