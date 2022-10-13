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
    int getnum(node* cur, int val, int y, int k, int l){
        int a, b, c;
        b = (y&(1<<l))?1:0;
        c = (k&(1<<l))?1:0;
        if(cur->cnt == 0){
            return 0;
        }
        if(l == 0){
            if(c == 1){
                int ans=0;
                if(cur->child[0] != NULL){
                    ans += cur->child[0]->cnt;
                }
                if(cur->child[1] != NULL){
                    ans += cur->child[1]->cnt;
                }
                return ans;
            }else{
                int ans=0;
                a = b;
                if(cur->child[a] != NULL){
                    ans += cur->child[a]->cnt;
                }
                return ans;
            }
        }
// cout<<val<<' '<<c<<' '<<b<<endl;
        int ans = 0;
        if(c == 1){
            a = b;
            if(cur->child[a] != NULL){
                ans += cur->child[a]->cnt;
            }
            a = 1^a;
            if(cur->child[a] != NULL){
                ans += getnum(cur->child[a], 2*val+a, y, k, l-1);
            }
        }else{
            a = b;
            if(cur->child[a] != NULL){
// cout<<"fuewfguewfuew";
                ans += getnum(cur->child[a], 2*val+a, y, k, l-1);
            }
        }
        return ans;
    }
};

void solve()
{
    int q, x, L;
    cin>>q>>L;
    trie tr(L);
    while(q--){
        int ch, x, y, k;
        cin>>ch;
        if(ch == 2){
            cin>>y>>k;
            node* cur=tr.root;
            int ans = tr.getnum(cur, 0, y, k, L-1);
            cout<<"NUM = "<<ans<<endl;
        }else{
            cin>>x;
            if(ch == 0){
                tr.insert(x);
            }else{
                tr.remove(x);
            }
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