#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int count=0, ans=0;         // keep some information
    int tail=0, head=-1;        // declare 2 pointers
    while(tail<n){
        while(head+1<n && ((a[head+1]==1 && count<=k) || (a[head+1]==0 && count<k))){
            head++;                             // check for condition
            if(a[head]==0)
                count++;                        // update info
        }
        cout<<tail<<" "<<head<<" "<<count<<endl;
        ans = max(ans,head-tail+1);                 // update info (answer)
        if(tail<=head){                         // move tail 1 step ahead
            if(a[tail]==0)
                count--;
            tail++;
        }
        else{                   // initialise
            tail++;
            head = tail-1;
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