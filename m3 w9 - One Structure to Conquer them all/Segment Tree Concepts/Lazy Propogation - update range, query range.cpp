#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

struct node{
    int sum, maxi, lazy;
    node(){
        sum = 0;
        maxi = 0;
        lazy = 0;
    }
};
node t[400400];

void push(int index, int l, int r){
    if(t[index].lazy != 0){
        t[index].sum = t[index].lazy * (r-l+1);
        t[index].maxi = t[index].lazy;
        if(l != r){
            t[2*index].lazy = t[index].lazy;
            t[2*index+1].lazy = t[index].lazy;
        }
        t[index].lazy = 0;
    }
}

node merge(node &a, node &b){
    node ans;
    ans.sum = a.sum + b.sum;
    ans.maxi = max(a.maxi, b.maxi);
    ans.lazy = 0;
    return ans;
}

void build(int index, int l, int r){
    if(l == r){
        t[index] = node();
        return;
    }
    int mid=(l+r)/2;
    build(index<<1, l, mid);
    build(index<<1|1, mid+1, r);
    t[index] = node();
}

void update(int index, int l, int r, int lq, int rq, int v){
    push(index, l, r);
    if(l > rq || lq > r){
        return;
    }
    if(lq <= l && r <= rq){
        t[index].lazy = v;
        push(index, l, r);
        return;
    }
    int mid=(l+r)>>1;
    update(2*index, l, mid, lq, rq, v);
    update(2*index+1, mid+1, r, lq, rq, v);
    t[index] = merge(t[2*index], t[2*index+1]);
}

node query(int index, int l, int r, int lq, int rq){
// cout<<l<<" "<<r<<endl;
    push(index, l, r);
    if(l > rq || lq > r){
        return node();
    }
    if(lq <= l && r <= rq){
        return t[index];
    }
    int mid=(l+r)>>1;
    node a=query(2*index, l, mid, lq, rq);
    node b=query(2*index+1, mid+1, r, lq, rq);
    return merge(a, b);
}

void solve()
{
    build(1, 0, 10);
    int q;
    cin>>q;
    while(q--){
        int ch;
        cin>>ch;
        if(ch == 1){            // sum of elements in range [l,r]
            int l, r;
            cin>>l>>r;
            node ans=query(1, 0, 10, l, r);
            cout<<"sum = "<<ans.sum<<endl;
        }else if(ch == 2){      // maximum of elements in range [l,r]
            int l, r;
            cin>>l>>r;
            node ans=query(1, 0, 10, l, r);
            cout<<"maximum = "<<ans.maxi<<endl;
        }else{                  // update range [l,r] all elements to v
            int l, r, v;
            cin>>l>>r>>v;
            update(1, 0, 10, l, r, v);
// for(int i=0; i<20; i++){
//     cout<<i<<" "<<t[i].maxi<<" "<<t[i].sum<<endl;
// }cout<<endl;
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