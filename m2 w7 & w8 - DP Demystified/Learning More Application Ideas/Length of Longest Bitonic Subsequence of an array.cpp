#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

vector<int> lis(vector<int> arr){
	vector<int> temp,ans;
	for(auto v:arr){
		if(temp.empty() || v>temp.back()){
			temp.push_back(v);
		}else{
			auto it = lower_bound(temp.begin(), temp.end(),v);
			*it = v;
		}
		ans.push_back(temp.size());
	}
	return ans;
}

void solve(){
	vector<int> arr={1,5,3,2,3,6,4,7,2,11,1};
	auto LIS = lis(arr);
	reverse(arr.begin(), arr.end());
	auto LDS = lis(arr);
	reverse(LDS.begin(), LDS.end());
	reverse(arr.begin(), arr.end());
	// cout<<arr<<endl;
	// cout<<LIS<<endl;
	// cout<<LDS<<endl;
	int ans = 0;
	for(int i=0;i<arr.size();i++){
		ans = max(ans,LIS[i]+LDS[i]-1);
	}
	cout<<ans<<endl;
}
#undef int

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int _t; cin>>_t; while(_t--)
    solve();
}