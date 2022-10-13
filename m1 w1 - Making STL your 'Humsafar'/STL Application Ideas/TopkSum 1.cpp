#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

struct topkSum{
    priority_queue<lli> pq;
    lli sum=0, k;
    void init(lli K){
        k = K;
    }
    void insert(lli x){
        pq.push(-x);
        sum += x;
        if((lli)(pq.size()) > k){
            sum -= (-pq.top());
            pq.pop();
        }
    }
    lli getTopkSum(){
        return sum;
    }
};

void solve()
{
    topkSum t;
    lli i, n, k, x;
    cin>>n>>k;
    t.init(k);
    for(i=0; i<n; i++){
        cin>>x;
        t.insert(x);
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


// 10 3
// 1 5 3 2 4 6 3 2 5 7

// TopkSum = 1
// TopkSum = 6
// TopkSum = 9
// TopkSum = 10
// TopkSum = 12
// TopkSum = 15
// TopkSum = 15
// TopkSum = 15
// TopkSum = 16
// TopkSum = 18