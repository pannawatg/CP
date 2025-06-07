/*
* Author : NathInwza007
* Created : 2025-05-25 07:38:51 UTC+7
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define sc second
#define inf (int)2e9
#define INF (ll)1e18
#define MOD (ll)1000000007
//998244353

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vt vector
#define pb push_back
#define eb emplace_back
#define all(arrname) (arrname).begin(), (arrname).end()
#define rall(arrname) (arrname).rbegin(), (arrname).rend()
#define sz(arrname) (int)(arrname).size()

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vt<int> dp(n + 1), pf(n + 1);
    dp[0] = pf[0] = 1;
    for(int i = 1;i<=n;i++){
        if(i - k <= 0){
            dp[i] = pf[i - 1];
        }else{
            dp[i] = (pf[i - 1] - pf[i - k - 1] + 2009) % 2009;
        }
        pf[i] = (pf[i - 1] + dp[i]) % 2009;
    }   
    cout << dp[n];
    return 0;
}