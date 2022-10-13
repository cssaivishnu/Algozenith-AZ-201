#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
int mod=1e9+7;

int n;
vi arr;                     // arr range [0,1e9]
vvi dpmax, dpmin, par;

void solve()
{
    cin>>n;
    arr = vi(n+1);
    par = vvi(n+1, vi(20,0));
    dpmax = vvi(n+1, vi(20,0));
    dpmin = vvi(n+1, vi(20,0));
    for(int i=0; i<n; i++){
        cin>>arr[i];
        dpmax[i][0] = arr[i];
        dpmin[i][0] = arr[i];
        par[i][0] = i+1;
    }
    par[n][0] = n;
    for(int i=1; i<19; i++){
        for(int j=0; j<=n; j++){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    dpmax[n][0] = -1;
    dpmin[n][0] = 1e9+1;
    for(int i=1; i<20; i++){
        for(int j=0; j<=n; j++){
            dpmax[j][i] = max(dpmax[j][i-1],dpmax[par[j][i-1]][i-1]);
            dpmin[j][i] = min(dpmin[j][i-1],dpmin[par[j][i-1]][i-1]);
        }
    }
    int q;
    cin>>q;
    int temp = 1;
    vi pof2 = vi(20);
    for(int i=0; i<20; i++){
        pof2[i] = temp;
        temp *= 2;
    }
    while(q--){
// overlap doest affect min or max, so we have optimisation to make log n to loglogn
// similarly we can do gcd also
// gcd(a,b,c,d,e,f) = gcd(gcd(a,b,c,d),gcd(c,d,e,f))
// min(a,b,c,d,e,f) = min(min(a,b,c,d),min(c,d,e,f))
// max(a,b,c,d,e,f) = max(max(a,b,c,d),max(c,d,e,f))
// we can see that c,d are repeated but overlapping doesnt matter for properties like gcd min max
        int l, r;       // l,r in range [0,n-1]
        cin>>l>>r;      // l<=r
        auto it = upper_bound(pof2.begin(),pof2.end(),r-l+1);
        it--;
        int len = it - pof2.begin();
        int mx, mn;
        mx = max(dpmax[l][len],dpmax[r+1-(1<<len)][len]);
        mn = min(dpmin[l][len],dpmin[r+1-(1<<len)][len]);
        cout<<"Max = "<<mx<<", Min = "<<mn<<endl;
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


// 10
// 5 7 3 2 1 4 5 2 6 7
// 4
// 0 1
// 3 3
// 4 4
// 7 2

// 0 1
// 1 10
// 2 5
// 3 5
// 4 5
// 5 6
// 6 8
// 7 8
// 8 9
// 9 10
// 10 10

// arr[0]=5 - arr[1]=7
// arr[3]=2 - arr[8]=6
// arr[4]=1 - arr[9]=7
// arr[7]=2 - arr[9]=7