#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lli long long

typedef pair<long long, long long> pii;

struct range_maintainance{
    set<pii> st;
    void fill_range(lli l, lli r){
        auto it = st.upper_bound({l-1,1e9});
        if(it != st.begin()){
            it--;
            if(it->second >= l-1){
                l = it->first;
                r = max(r,it->second);
                st.erase(it);
            }
        }
        it = st.upper_bound({r+1,1e9});
        if(it != st.begin()){
            it--;
            if(it->second >= r+1){
                r = it->second;
                l = min(l,it->first);
                st.erase(it);
            }
        }
        while(true){
            it = st.lower_bound({l,0});
            if(it == st.end())
                break;
            if(it->first <= r)
                st.erase(it);
            else
                break;
        }
        st.insert({l,r});
    }
    void clear_range(lli l, lli r){
        auto it = st.upper_bound({l,1e9});
        if(it != st.begin()){
            it--;
            if(it->second >= r){
                lli lo1 = it->first;
                lli hi1 = l-1;
                lli lo2 = r+1;
                lli hi2 = it->second;
                st.erase(it);
                if(hi1 >= lo1)
                    st.insert({lo1,hi1});
                if(hi2 >= lo2)
                    st.insert({lo2,hi2});
                return;
            }
            if(it->second >= l){
                st.erase(it);
                st.insert({it->first,l-1});
            }
        }
        it = st.upper_bound({r,1e9});
        if(it != st.end()){
            it--;
            if(it->second > r){
                st.erase(it);
                st.insert({r+1,it->second});
            }
        }
        while(true){
            it = st.lower_bound({l,0});
            if(it == st.end())
                break;
            if(it->first > r)
                break;
            else
                st.erase(it);
        }
    }
    bool check_point(lli x){
        auto it = st.upper_bound({x,1e9});
        if(it != st.begin()){
            it--;
            if(it->second < x)
                return false;
            else
                return true;
        }
        return false;
    }
    bool check_range_any(lli x, lli y){
        auto it = st.upper_bound({x,1e9});
        if(it != st.end()){
            if(it->first <= y){
                return true;
            }
        }
        return check_point(x);
    }
    bool check_range_all(lli x, lli y){
        auto it = st.upper_bound({x,1e9});
        if(it != st.begin()){
            it--;
            if(it->second >= y){
                return true;
            }
        }
        return false;
    }
    void print_status(){
        cout<<"[";
        for(auto x : st){
            cout<<"("<<x.first<<","<<x.second<<")";
        }
        cout<<"]"<<endl;
    }
};

void solve()
{
    lli q, t, l, r, x, y;
    cin>>q;
    range_maintainance obj;
    while(q--){
        cin>>t;
        if(t == 1){         // fill_range
            cin>>l>>r;
            obj.fill_range(l,r);
        }
        if(t == 2){         // clear_range
            cin>>l>>r;
            obj.clear_range(l,r);
        }
        obj.print_status();
        if(t == 3){         // check_point
            cin>>x;
            cout<<"check_point("<<x<<") = "<<obj.check_point(x)<<endl;
        }
        if(t == 4){         // check_range_any
            cin>>x>>y;
            cout<<"check_range_any("<<x<<","<<y<<") = "<<obj.check_range_any(x,y)<<endl;
        }
        if(t == 5){         // check_range_all
            cin>>x>>y;
            cout<<"check_range_all("<<x<<","<<y<<") = "<<obj.check_range_all(x,y)<<endl;
        }
    }
}

signed main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);

    // int _t; cin>>_t; while(_t--)
    solve();
}


// 23
// 1 2 8
// 2 4 6
// 3 3
// 3 5
// 3 6
// 3 7
// 4 3 5
// 4 4 6
// 5 3 7
// 5 3 8
// 5 3 9
// 1 4 6
// 5 3 7
// 4 1 9
// 5 1 9
// 5 1 8
// 5 2 9
// 5 2 8
// 1 9 15
// 2 5 9
// 3 4
// 3 7
// 3 11
// 3 1

// [(2,8)]
// [(2,3)(7,8)]
// [(2,3)(7,8)]
// check_point(3) = 1
// [(2,3)(7,8)]
// check_point(5) = 0
// [(2,3)(7,8)]
// check_point(6) = 0
// [(2,3)(7,8)]
// check_point(7) = 1
// [(2,3)(7,8)]
// check_range_any(3,5) = 1
// [(2,3)(7,8)]
// check_range_any(4,6) = 0
// [(2,3)(7,8)]
// check_range_all(3,7) = 0
// [(2,3)(7,8)]
// check_range_all(3,8) = 0
// [(2,3)(7,8)]
// check_range_all(3,9) = 0
// [(2,8)]
// [(2,8)]
// check_range_all(3,7) = 1
// [(2,8)]
// check_range_any(1,9) = 1
// [(2,8)]
// check_range_all(1,9) = 0
// [(2,8)]
// check_range_all(1,8) = 0
// [(2,8)]
// check_range_all(2,9) = 0
// [(2,8)]
// check_range_all(2,8) = 1
// [(2,15)]
// [(2,4)(10,15)]
// [(2,4)(10,15)]
// check_point(4) = 1
// [(2,4)(10,15)]
// check_point(7) = 0
// [(2,4)(10,15)]
// check_point(11) = 1