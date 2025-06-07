#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
int dp[200001][2];
int pf[200001];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc, k;
    cin >> tc >> k;
    dp[0][0] = 1;
    for(int i = 1;i<=200000;i++){
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        if(i - k >= 0){
            dp[i][1] = dp[i - k][0] + dp[i - k][1];
        }
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
    for(int i = 1;i<=200000;i++){
        pf[i] += pf[i - 1] + dp[i][0] + dp[i][1];
    }
    while(tc--){
        int l, r;
        cin >> l >> r;
        cout << (pf[r] - pf[l - 1]) % MOD << '\n';
    }
}