#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

// subarray size >= 0

int n, q, a[10010];

struct node{
    int msum, lsum, rsum, totsum;
    node(int msum_=-1e18, int lsum_=-1e18, int rsum_=-1e18, int totsum_=0){
        msum = msum_;
        lsum = lsum_;
        rsum = rsum_;
        totsum = totsum_;
    }
};
node t[40040];

node merge(node &a, node &b){
    int msum = max({a.msum, b.msum, a.rsum+b.lsum});
    int lsum = max(a.lsum, a.totsum+b.lsum);
    int rsum = max(b.rsum, b.totsum+a.rsum);
    int totsum = a.totsum + b.totsum;
    return node(msum, lsum, rsum, totsum);
}

void build(int index, int l, int r){
    if(l == r){
        if(a[l] >= 0){
            t[index] = node(a[l],a[l],a[l],a[l]);
        }else{
            t[index] = node(0,0,0,a[l]);
        }
        return;
    }
    int mid=(l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    t[index] = merge(t[2*index], t[2*index+1]);
}

void update(int index, int l, int r, int pos, int val){
    if(pos > r || pos < l){
        return;
    }
    if(l == r){
        if(val >= 0){
            t[index] = node(val,val,val,val);
        }else{
            t[index] = node(0,0,0,val);
        }
        a[l] = val;
        return;
    }
    int mid=(l+r)/2;
    update(2*index, l, mid, pos, val);
    update(2*index+1, mid+1, r, pos, val);
    t[index] = merge(t[2*index], t[2*index+1]);
}

node query(int index, int l, int r, int lq, int rq){
    if(l > rq || r < lq){
        return node(-1e18, -1e18, -1e18, 0);
    }
    if(lq <= l && r <= rq){
        return t[index];
    }
    int mid=(l+r)/2;
    node a = query(2*index, l, mid, lq, rq);
    node b = query(2*index+1, mid+1, r, lq, rq);
    return merge(a, b);
}

void solve()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(1,0,n-1);
    // cout<<t[1].msum<<endl;
    cin>>q;
    while(q--){
        int ch;
        cin>>ch;
        if(ch == 1){                        // update point
            int pos, val;
            cin>>pos>>val;
            update(1, 0, n-1, pos, val);
        }else{                              // print query
            int l, r;
            cin>>l>>r;
            node ans=query(1, 0, n-1, l, r);
// cout<<ans.msum<<" "<<ans.lsum<<" "<<ans.rsum<<" "<<ans.totsum<<endl;
            cout<<ans.msum<<endl;
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