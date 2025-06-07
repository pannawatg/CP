#include <bits/stdc++.h>
using namespace std;
void io(string filename) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    io("moobuzz");
    int n;
    cin >> n;
    int l = 1, r = 2e9, ans = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        int s = mid / 3 + mid / 5 - mid / 15;
        if(mid - s >= n){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}