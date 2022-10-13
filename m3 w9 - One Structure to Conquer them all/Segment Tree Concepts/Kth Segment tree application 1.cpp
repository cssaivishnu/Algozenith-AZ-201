#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
int mod=1e9+7;

// taller[i] -> number of persons taller than ith person in the line
// heights are not unique (leaf nodes can have > 1 values)
// ans[i] -> height of person at ith position in the final line

int n, q, t[400400], taller[100100], ans[100100];

void build(int index, int l, int r){
    if(l == r){
        t[index] = 0;
        return;
    }
    int mid=(l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    t[index] = 0;
}

void update(int index, int l, int r, int pos, int val){
    if(l > pos || r < pos){
        return;
    }
    if(l == r){
        t[index] += val;
        return;
    }
    int mid=(l+r)/2;
    update(2*index, l, mid, pos, val);
    update(2*index+1, mid+1, r, pos, val);
    t[index] = t[2*index] + t[2*index+1];
}

int getKthquery(int index, int l, int r, int k){
// cout<<l<<" "<<r<<" "<<k<<endl;
    if(l == r){
        return l;
    }
    int mid=(l+r)/2;
    if(k <= t[2*index+1]){
        return getKthquery(2*index+1, mid+1, r, k);
    }else{
        return getKthquery(2*index, l, mid, k-t[2*index+1]);
    }
}

void solve()
{
    int c;
    cin>>n;
    build(1, 0, 100000);
    for(int i=0; i<n; i++){
        cin>>c;
        update(1, 0, 100000, c, 1);
// cout<<t[1]<<" ";
    }
    for(int i=0; i<n; i++){
        cin>>taller[i];
    }
    for(int i=n-1; i>=0; i--){
        int pos=getKthquery(1, 0, 100000, taller[i]+1);
        ans[i] = pos;
        update(1, 0, 100000, pos, -1);
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}