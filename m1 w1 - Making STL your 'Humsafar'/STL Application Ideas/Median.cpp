#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

struct median
{
    multiset<lli> lo, hi;
    void rebalance()
    {
        lli lsize, hsize;
        lsize = lo.size();
        hsize = hi.size();
        if(lsize - hsize == 0)
            return;
        if(lsize - hsize == 1)
            return;
        if(lsize - hsize == -1)
        {
            lli val;
            auto it = hi.begin();
            val = *it;
            lo.insert(val);
            hi.erase(it);
        }
        if(lsize - hsize == 2)
        {
            lli val;
            auto it = lo.end(); it--;
            val = *it;
            hi.insert(val);
            lo.erase(it);
        }
    }
    void insert(lli x)
    {
        auto it = hi.begin();
        if(x >= *it)
            hi.insert(x);
        else
            lo.insert(x);
        rebalance();
    }
    void remove(lli x)
    {
        lli val;
        auto it = lo.end(); it--;
        val = *it;
        if(x <= val)
            lo.erase(lo.find(x));
        else
            hi.erase(hi.find(x));
        rebalance();
    }
    double getMedian()
    {
        if((lli)(lo.size()) == (lli)(hi.size()))
        {
            if((lli)(lo.size()) == 0)   return 0;
            lli v1, v2;
            auto it1 = lo.end(); it1--;
            auto it2 = hi.begin();
            v1 = *it1; v2 = *it2;
            double ans = (v1+v2)*1.0/2;
            return ans;
        }
        else
        {
            auto it = lo.end(); it--;
            double ans = 1.0*(*it);
            return ans;
        }
    }
};

void solve()
{
    median m;
    m.insert(3);
    cout<<"Median = "<<m.getMedian()<<endl;
    m.insert(6);
    cout<<"Median = "<<m.getMedian()<<endl;
    m.insert(1);
    cout<<"Median = "<<m.getMedian()<<endl;
    m.remove(6);
    cout<<"Median = "<<m.getMedian()<<endl;
    m.insert(2);
    cout<<"Median = "<<m.getMedian()<<endl;
    m.remove(3);
    cout<<"Median = "<<m.getMedian()<<endl;
    m.insert(9);
    cout<<"Median = "<<m.getMedian()<<endl;
    m.insert(8);
    cout<<"Median = "<<m.getMedian()<<endl;
    m.remove(9);
    cout<<"Median = "<<m.getMedian()<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// Median = 3
// Median = 4.5
// Median = 3
// Median = 2
// Median = 2
// Median = 1.5
// Median = 2
// Median = 5
// Median = 2