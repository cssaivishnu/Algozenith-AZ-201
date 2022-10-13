#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

vector<int> lis(vector<int> arr){
	vector<int> temp;
	vector<int> pos;
	for(auto v:arr){
		if(temp.empty() || v>temp.back()){
			pos.push_back(temp.size());
			temp.push_back(v);
		}else{
			auto it = lower_bound(temp.begin(), temp.end(),v);
			pos.push_back(it-temp.begin());
			*it = v;
		}
	}
	int lisVal = temp.size()-1;
	vector<int> ans;
	for(int i=pos.size()-1;i>=0;i--){
		if(pos[i]==lisVal){
			ans.push_back(arr[i]);
			lisVal--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void solve()
{
    
}

#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}