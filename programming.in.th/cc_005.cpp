#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd(y, x % y);
}
//gcd * lcm = x * y
int lcm(int x, int y){
    return (x * y) / gcd(x, y);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 1;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        ans = lcm(ans, a[i]);
    }
    cout << ans;
    return 0;
}