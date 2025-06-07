#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m, ans = 1;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        ans *= i;
        if(i % 2 == 0){
            ++ans;
        }else{
            --ans;
        }
        ans %= m;
        cout << ans << ' ';
    }
}