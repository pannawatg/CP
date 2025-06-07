#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    int s = 0, ans = 0;
    mp[0] = 1;
    for(int i = 0;i<n;i++){
        int e;
        cin >> e;
        s += e;
        ans += mp[s - x];
        mp[s]++;
    }
    cout << ans << '\n';
}