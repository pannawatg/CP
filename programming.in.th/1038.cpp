/*
* Author : NathInwza007
* Created : 2025-05-25 08:57:39 UTC+7
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
    
    int n;
    cin >> n;
    ld a[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> a[i][j];
            a[i][j] /= 100.0;
        }
    }   
    int N = (1 << n);
    vt<ld> dp(N, 0);
    dp[0] = 1.00;
    for(int mask = 0;mask<N;mask++){
        int t = 0;
        for(int i = 0;i<n;i++){
            if(mask & (1 << i)) ++t;
        }   
        for(int i = 0;i<n;i++){
            dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] * a[t][i]);
        }
    }
    cout << fixed << setprecision(12) << dp[N - 1] * 100.0;
    return 0;
}