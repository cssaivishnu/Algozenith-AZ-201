#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

// point update range query

int q, n, a[100100];

struct node{
    int mini, cnt;
    node(int m=1e9, int c=0){
        mini = m;
        cnt = c;
    }
};
node t[400400];

node merge(node &a, node &b){                   // merge logic
    if(a.mini == b.mini){
        return node(a.mini, a.cnt+b.cnt);
    }else if(a.mini < b.mini){
        return a;
    }else return b;
}

void build(int index, int l, int r){
    if(l == r){
        // left node validation
        t[index] = node(a[l],1);
        return;
    }
    int mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    // merge logic
    t[index] = merge(t[2*index],t[2*index+1]);
}

void update(int index, int l, int r, int pos, int val){
    if(pos > r || pos < l){
        return;
    }
    if(l == r){
        // leaf node validation
        t[index] = node(val, 1);
        a[l] = val;
        return;
    }
    int mid=(l+r)/2;
    update(2*index, l, mid, pos, val);
    update(2*index+1, mid+1, r, pos, val);
    // merge logic
    t[index] = merge(t[2*index],t[2*index+1]);
}

node query(int index, int l, int r, int lq, int rq){
    if(l > rq || r < lq){
        // leaf node validation
        return node();
    }
    if(lq <= l && r <= rq){
        return t[index];
    }
    int mid=(l+r)/2;
    node a=query(2*index,l,mid,lq,rq);
    node b=query(2*index+1,mid+1,r,lq,rq);
    // merge logic
    return merge(a,b);
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
        if(ch == 1){                        // update point
            int x, p;
            cin>>p>>x;
            update(1, 0, n-1, p, x);
        }else{                              // query range
            int l, r;
            cin>>l>>r;
            node ans=query(1, 0, n-1, l, r);
            cout<<ans.mini<<" "<<ans.cnt<<endl;
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