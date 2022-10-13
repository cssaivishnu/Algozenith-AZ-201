#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

// point update range query

int n, q, a[100100], t[400400];      // take 4*n

void build(int index, int l, int r){
    if(l == r){
        t[index] = a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    t[index] = t[2*index] + t[2*index+1];                   // merge logic
}

void update(int index, int l, int r, int pos, int val){
    if(pos < l || pos > r){
        return;
    }
    if(l == r){
        t[index] = val;
        a[l] = val;
        return;
    }
    int mid=(l+r)/2;
    update(2*index, l, mid, pos, val);
    update(2*index+1, mid+1, r, pos, val);
    t[index] = t[2*index] + t[2*index+1];                   // merge logic
}

int print_query(int index, int l, int r, int lq, int rq){
    if(l>rq || r<lq){
        return 0;
    }
    if(lq<=l && r<=rq){
        return t[index];
    }
    int mid = (l+r)/2;
    return (print_query(2*index, l, mid, lq, rq)+print_query(2*index+1, mid+1, r, lq, rq));
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(1, 0, n-1);
    cin>>q;
    for(int i=0; i<q; i++){
        int ch;
        cin>>ch;        // 1 for update, 2 for print query [l,r]
        if(ch == 1){                            // updaate point
            int x, v;
            cin>>x>>v;
            update(1,0,n-1,x,v);
        }else{                                  // query range
            int l, r;
            cin>>l>>r;
            cout<<print_query(1,0,n-1,l,r)<<endl;
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