#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0;i<n;i++){
        cin >> a[i] >> b[i];
    }   
    int ans = INT_MAX;
    for(int i = 1;i<(1 << n);i++){
        int s = 1, c = 0;
        for(int j = 0;j<n;j++){
            if(i & (1 << j)){
                s *= a[j];
                c += b[j];
            }
        }
        ans = min(ans, abs(s - c));
    }
    cout << ans;
}