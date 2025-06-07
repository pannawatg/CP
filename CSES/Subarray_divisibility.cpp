#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0, ans = 0;
    a[0] = 1;
    for(int i = 0;i<n;i++){
        int e;
        cin >> e;
        s += e;
        int m = ((s % n) + n) % n;
        ans += a[m];
        a[m]++;
    }
    cout << ans << '\n';
}