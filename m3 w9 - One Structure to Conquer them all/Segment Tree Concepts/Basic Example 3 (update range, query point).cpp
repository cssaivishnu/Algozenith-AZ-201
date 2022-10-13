#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

// range update, point query

int n, q, a[100100], t[400400];

void build(int index, int l, int r){
    if(l == r){
        t[index] = a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    t[index] = 0;
}

void update(int index, int l, int r, int lq, int rq, int val){
    if(l > rq || r < lq){
        return;
    }
    if(lq <= l && r <= rq){
        t[index] += val;
        return;
    }
    int mid=(l+r)/2;
    update(2*index, l, mid, lq, rq, val);
    update(2*index+1, mid+1, r, lq, rq, val);
}

int query(int index, int l, int r, int pos){
    if(pos < l || pos > r){
        return 0;
    }
    if(l == r){
        return t[index];
    }
    int ans = t[index];
    int mid = (l+r)/2;
    ans += query(2*index, l, mid, pos);
    ans += query(2*index+1, mid+1, r, pos);
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(1, 0, n-1);
    cin>>q;
    while(q--){
        int ch;
        cin>>ch;
        if(ch == 1){                // update range
            int l, r, v;
            cin>>l>>r>>v;
            update(1, 0, n-1, l, r, v);
        }else{                      // query point
            int p;
            cin>>p;
            cout<<query(1, 0, n-1, p)<<endl;
        }
    }
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}