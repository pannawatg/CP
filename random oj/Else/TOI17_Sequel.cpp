/*
* Author : NathInwza007
* Created : 2025-05-28 21:44:10 UTC+7
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
int pf[100001][320], a[100001];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    int sq = (int)(sqrt(n));
    for(int t = 1;t<=sq;t++){
        for(int i = 1;i<=n;i++){
            if(i - t >= 0){
                pf[i][t] = a[i] + pf[i - t][t];
            }else{
                pf[i][t] = a[i];
            }
            //cout << pf[i][t] << ' ';
        }
        //cout << '\n';
    }
    while(q--){
        int l, k, r;
        cin >> l >> k >> r;
        if(k > sq){
            int ans = 0;
            for(int i = l;i<=r;i+=k){
                ans += a[i];
            }
            cout << ans << ' ';
        }else{
            r = l + ((r - l) / k) * k;
            if(l - k < 0){
                l = 0;
            }else{
                l -= k;
            }
            //cout << "L AND R: " << l << ' ' << r << '\n';
            cout << pf[r][k] - pf[l][k] << ' ';
        }
    }
    return 0;
}