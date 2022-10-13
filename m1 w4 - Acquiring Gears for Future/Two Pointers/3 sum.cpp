#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    lli n, target, i, j, k;
    cin>>n>>target;
    lli a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    lli ans=0;
    for(j=0; j<n; j++){
        i = 0;
        k = n-1;
        while(i<j && j<k){
            if((a[i]+a[j]+a[k]) == target){
                lli itemp, ktemp;
                itemp = i;
                ktemp = k;
                while(itemp<j && a[itemp]==a[i]){
                    itemp++;
                }
                while(ktemp>j && a[ktemp]==a[k]){
                    ktemp--;
                }
                ans += (itemp-i)*(k-ktemp);
                i = itemp;
                k = ktemp;
            }
            else if((a[i]+a[j]+a[k]) < target){
                i++;
            }
            else{
                k--;
            }
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}