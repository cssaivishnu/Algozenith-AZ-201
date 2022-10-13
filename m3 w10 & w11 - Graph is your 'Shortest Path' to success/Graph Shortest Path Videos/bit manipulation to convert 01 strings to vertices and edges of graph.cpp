#include<bits/stdc++.h>
using namespace std;

vector<int> g[(1<<20)];
bool ban[(1<<20)];

int getVal(string s){
	int stVal=0;
	for(int i=0;i<20;i++){
		if(s[i]=='1'){
			stVal|=(1<<i);
		}
	}
	return stVal;
}

void add_edge(int a,int b){
	if(!ban[a]&&!ban[b]){
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

void solve(){

	string s;
	cin>>s;
	int stVal = getVal(s);

	string en;
	cin>>en;
	int enVal=getVal(en);
	
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		string temp;
		cin>>temp;
		ban[getVal(temp)]=1;
	}
	for(int i=0;i<(1<<20);i++){
		for(int j=0;j<20;j++){
			add_edge(i,i^(1<<j));
		}
	}
}	

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//int _t;cin>>_t;while(_t--)
	solve();
}