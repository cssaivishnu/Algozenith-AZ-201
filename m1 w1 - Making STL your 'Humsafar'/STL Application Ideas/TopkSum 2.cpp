#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

struct topkSum{
    multiset<lli> larger, smaller;
    lli sum=0, k;
    void init(lli K){
        k = K;
    }
    void insert(lli x){
        lli y;
        sum += x;
        larger.insert(x);
        if(larger.size() > k){
            y = *(larger.begin());
            sum -= y;
            larger.erase(larger.begin());
            smaller.insert(y);
        }
    }
    void remove(lli x){
        if(larger.find(x) != larger.end()){
            larger.erase(larger.find(x));
            sum -= x;
        }
        else{
            smaller.erase(smaller.find(x));
        }
        if(!smaller.empty() && larger.size() < k){
            auto it = smaller.end(); it--;
            lli y = *it;
            smaller.erase(it);
            larger.insert(y);
            sum += y;
        }
    }
    lli getTopkSum(){
        return sum;
    }
};

void solve()
{
    topkSum t;
    lli i, n, k, x, y;
    cin>>n>>k;
    t.init(k);
    for(i=0; i<n; i++){
        cin>>y>>x;
        if(y == 1)
            t.insert(x);
        else
            t.remove(x);
        cout<<"TopkSum = "<<t.getTopkSum()<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// 20 6
// 1 1
// 1 5
// 1 3
// 1 2
// 1 5
// 1 4
// 1 3
// -1 3
// 1 3
// -1 5
// 1 3
// 1 2
// 1 3
// -1 3
// 1 5
// 1 7
// -1 5
// -1 7
// -1 3
// -1 2

// TopkSum = 1
// TopkSum = 6
// TopkSum = 9
// TopkSum = 11
// TopkSum = 16
// TopkSum = 20
// TopkSum = 22
// TopkSum = 20
// TopkSum = 22
// TopkSum = 18
// TopkSum = 20
// TopkSum = 20
// TopkSum = 21
// TopkSum = 20
// TopkSum = 23
// TopkSum = 27
// TopkSum = 25
// TopkSum = 20
// TopkSum = 19
// TopkSum = 18