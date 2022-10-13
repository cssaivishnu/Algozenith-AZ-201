#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int q;
        cin>>q;
        while(q--) {
            string x;
            cin>>x;
            if(x=="print") {
                int l,r;
                cin>>l>>r;
                cout<<s.substr(l,r-l+1)<<"\n";
            }
            else if(x=="reverse") {
                int l,r;
                cin>>l>>r;
                reverse(s.begin()+l, s.begin()+r+1);
            }
            else if(x=="replace") {
                int l,r;
                string p;
                cin>>l>>r>>p;
                for(int j=l; j<=r; ++j) {
                    s[j]=p[j-l];
                }
            }
            else { //rotate
                int k;
                cin>>k;
                s = s.substr(n-k,k) + s.substr(0,n-k);
            }
        }
    }
    return 0;
}