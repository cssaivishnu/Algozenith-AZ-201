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
    node *child[26];
    // unordered_map<char,node*> child; can be used if we are not sure of what string characters gonna be
    int prefix;
    vs wend;
    node(){
        prefix = 0;
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
    }
};

struct trie{
    node *root;
    trie(){
        root = new node();
    }
    void insert(string s){
        node *cur = root;
        for(int i=0; i<s.length(); i++){
            cur->prefix++;
            int x = s[i]-'a';
            if(cur->child[x] == NULL){
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->wend.push_back(s);
    }
    void remove(string s){
        node *cur = root;
        for(int i=0; i<s.length(); i++){
            cur->prefix--;
            int x = s[i]-'a';
            cur = cur->child[x];
        }
        cur->wend.pop_back();
    }
};

void search(node* cur, vs &ans, string &s, int kleft, int pos){
    if(kleft < 0)   return;
    if(pos == s.length()){
        for(auto x:cur->wend){
            ans.push_back(x);
        }
    }
    for(int i=0; i<26; i++){
        if(cur->child[i] != NULL){
            if(i == (s[pos]-'a')){
                search(cur->child[i], ans, s, kleft, pos+1);
            }else{
                search(cur->child[i], ans, s, kleft-1, pos+1);
            }
        }
    }
}

void solve()
{
    trie tr;
    int n, m;
    string s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        tr.insert(s);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>s;
        tr.remove(s);
    }
    int k;
    cin>>k>>s;
    node *cur=tr.root;
    vs ans;
    search(cur, ans, s, k, 0);
    for(auto x:ans){
        cout<<x<<endl;
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