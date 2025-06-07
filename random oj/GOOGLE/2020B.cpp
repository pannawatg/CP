#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
    for(int i = 0;i<n;i++){
        int pf = 0;
        for(int j = 0;j<k;j++){
            int x;
            cin >> x;
            pf += x;
            for(int l = 0;l + j + 1<=p;l++){
                dp[i + 1][l + j + 1] = max(dp[i + 1][l + j + 1], dp[i][l] + pf);
                dp[i + 1][l + j + 1] = max(dp[i + 1][l + j + 1], dp[i][l + j + 1]);
            }
        }
    }
    cout << dp[n][p] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}