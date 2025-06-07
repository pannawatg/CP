/*
* Author : NathInwza007
* Created : 2025-05-25 21:56:48 UTC+7
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

void solve(){
    int n, k;
    cin >> n >> k;
    vt<int> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(all(a));
    int ans = 0, s = 0;
    for(auto x : a){
        s += x;
        if(s > k){
            break;
        }
        ++ans;
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    for(int t = 1;t<=tc;t++){
        cout << "Case #" << t << ": "; solve();
    }
    return 0;
}