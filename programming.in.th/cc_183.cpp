#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define oset tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag, tree_order_statistics_node_update>
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    oset s;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        s.insert({i, x});
    }
    while(n--){
        int x;
        cin >> x;
        auto it = s.find_by_order(x - 1);
        cout << it->second << '\n';
        s.erase(it);
    }
    return 0;
}