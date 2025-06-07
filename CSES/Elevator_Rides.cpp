/*
* Author : NathInwza007
* Created : 2025-05-25 08:29:23 UTC+7
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
pii F(pii &a, int w, int k){
    if(a.sc + w > k){
        return {a.fi + 1, w};
    }else{
        return {a.fi, a.sc + w};
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vt<int> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    int N = (1 << n);
    vt<pii> dp(N, {inf, inf});
    dp[0] = {0, 0};
    for(int mask = 1;mask<N;mask++){
        for(int i = 0;i<n;i++){
            if(mask & (1 << i)){
                dp[mask] = min(dp[mask], F(dp[mask ^ (1 << i)], a[i], k));
            }
        }
    }
    cout << dp[N - 1].fi + 1;
    return 0;
}