#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

void solve()
{
    bitset<10> s1;
    s1[2] = 1;
    s1[5] = 1;
    s1[8] = 1;
    for(int i=0; i<10; i++){
        cout<<s1[i]<<" ";
    }
    cout<<endl<<endl;

    string st1, st2;
    st1 = "0110100101";
    reverse(st1.begin(),st1.end());
    st2 = "1001010010";
    reverse(st2.begin(),st2.end());
    bitset<10> s2(st1),s3(st2);
    for(int i=0; i<10; i++){
        cout<<s2[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<10; i++){
        cout<<s3[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<s1<<endl<<s2<<endl;
    cout<<(s1&s2)<<" and"<<endl;
    cout<<(s1|s2)<<" or"<<endl;
    cout<<(s1^s2)<<" xor"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// 0 0 1 0 0 1 0 0 1 0 

// 0 1 1 0 1 0 0 1 0 1 
// 1 0 0 1 0 1 0 0 1 0 

// 0100100100
// 1010010110
// 0000000100 and
// 1110110110 or
// 1110110010 xor