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

void dfs(node* cur, int L, vi &allnum, int l, int val){
    if(l == L){
        for(int i=0; i<cur->cnt; i++){
            allnum.push_back(val);
        }
    }
    if(cur->cnt == 0){
        return;
    }
    if(cur->child[0] != NULL){
        dfs(cur->child[0], L, allnum, l+1, val<<1);
    }
    if(cur->child[1] != NULL){
        dfs(cur->child[1], L, allnum, l+1, val<<1|1);
    }
}

void solve()
{
    int n, m, x, L;
    cin>>n>>m>>L;
    trie tr(L);
    for(int i=0; i<n; i++){
        cin>>x;
        tr.insert(x);
    }
    for(int i=0; i<m; i++){
        cin>>x;
        tr.remove(x);
    }
    vi allnum;
    node* cur=tr.root;
    dfs(cur, L, allnum, 0, 0);
    for(auto x:allnum){
        cout<<x<<' ';
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