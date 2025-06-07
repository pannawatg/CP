/*
* Author : Nathlol2
* Created : 2025-06-02 20:47:12 UTC+7
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
#define ar array
#define pb push_back
#define eb emplace_back
#define all(arrname) (arrname).begin(), (arrname).end()
#define rall(arrname) (arrname).rbegin(), (arrname).rend()
#define sz(arrname) (int)(arrname).size()

const int d4x[4] = {-1, 0, 1, 0}, d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve(){
    int n;
    cin >> n;
    ll u = inf, l = inf, r = -1, d = -1;
    vt<ar<ll, 2>> a(n);
    multiset<ll> x, y;
    for(int i = 0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
        u = min(u, a[i][1]);
        l = min(l, a[i][0]);
        r = max(r, a[i][0]);
        d = max(d, a[i][1]);
        x.insert(a[i][0]);
        y.insert(a[i][1]);
    }
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    ll ans = INF;
    for(int i = 0;i<n;i++){
        ll nu = u, nl = l, nr = r, nd = d;
        //cout << "(" << a[i][0] << ", " << a[i][1] << ")\n";
        if(a[i][0] == *x.begin()){
            x.erase(x.begin());
            nl = max(nl, *x.begin());
            x.insert(a[i][0]);
        }
        if(a[i][0] == *x.rbegin()){
            auto it = x.end();
            --it;
            x.erase(it);
            nr = min(nr, *x.rbegin());
            x.insert(a[i][0]);
        }
        if(a[i][1] == *y.begin()){
            y.erase(y.begin());
            nu = max(nu, *y.begin());
            y.insert(a[i][1]);
        }
        if(a[i][1] == *y.rbegin()){
            auto it = y.end();
            --it;
            y.erase(it);
            nd = min(nd, *y.rbegin());
            y.insert(a[i][1]);
        }
        //cout << "bounds: " << "u=" << nu << ", l=" << nl << ", r=" << nr << ", d=" << nd << '\n';
        ll area = (nd - nu + 1) * (nr - nl + 1);
        //cout << "area: " << area << '\n';
        if(area == n - 1){
            ans = min({ans, (nd - nu + 2) * (nr - nl + 1), (nd - nu + 1) * (nr - nl + 2)});
        }else{
            ans = min(ans, area);
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}