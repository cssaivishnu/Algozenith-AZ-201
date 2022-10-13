#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

struct bag
{
    int sum=0;
    map<lli,lli> mp;
    void insert(lli x)
    {
        sum += x;
        mp[x]++;
    }
    void remove(int x)
    {
        sum -= x;
        mp[x]--;
        if(mp[x] == 0)
            mp.erase(x);
    }
    lli getsum()
    {
        return sum;
    }
    lli getmax()
    {
        return (mp.rbegin())->first;
    }
    lli getdistinct()
    {
        return (lli)(mp.size());
    }
};

void solve()
{
    bag b;
    b.insert(2);
    b.insert(8);
    b.remove(2);
    b.insert(4);
    b.insert(9);
    b.remove(4);
    b.insert(5);
    b.remove(8);
    b.insert(18);
    b.insert(3);
    b.insert(3);
    b.remove(9);
    b.insert(28);
    cout<<b.getsum()<<" "<<b.getmax()<<" "<<b.getdistinct()<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// 57 28 4