#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
int mod=1e9+7;

struct node{
    node* child[2];
    int cnt;
    node(){
        cnt = 0;
        child[0] = NULL;
        child[1] = NULL;
    }
};

struct trie{
    node *root;
    int L;
    trie(int l){
        root = new node();
        L = l;
    }
    void insert(int n){
        node *cur=root;
        for(int i=L-1; i>=0; i--){
            cur->cnt++;
            int x = ((n&(1<<i))?1:0);
            if(cur->child[x] == NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt++;
    }
    void remove(int n){
        node *cur=root;
        for(int i=L-1; i>=0; i--){
            cur->cnt--;
            int x = ((n&(1<<i))?1:0);
            cur = cur->child[x];
        }
        cur->cnt--;
    }
};

void solve()
{
    int n, x, L;
    cin>>n>>L;
    trie tr(L);
    cin>>x;
    tr.insert(x);
    int maxi = -1;
    for(int i=1; i<n; i++){
        cin>>x;
        node* cur = tr.root;
        int val=0;
        for(int j=L-1; j>=0; j--){
            int y = ((x&(1<<j))?1:0);
            if(cur->child[1^y] != NULL){
                cur = cur->child[1^y];
                val = 2*val + (1^y);
            }else{
                cur = cur->child[y];
                val = 2*val + y;
            }
        }
        tr.insert(x);
        // cout<<x<<' '<<val<<' '<<(x^val)<<endl;
        maxi = max(maxi, x^val);
    }
    cout<<maxi<<endl;
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}