/*
* Author : NathInwza007
* Created : 2025-05-28 20:41:46 UTC+7
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
const int mxN = 1e6 + 5;
vt<pii> a(mxN);
int p[mxN], s[mxN]; pii mx[mxN], mn[mxN];
int _find(int x){
    if(x == p[x]){
        return x;
    }
    return p[x] = _find(p[x]);
}
void _union(int x, int y){
    int X = _find(x), Y = _find(y);
    if(X != Y){
        if(s[X] < s[Y]){
            swap(X, Y);
        }
        s[X] += s[Y];
        p[Y] = X;
        mn[X] = min(mn[X], mn[Y]);
        mx[X] = max(mx[X], mx[Y]);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> a[i].fi >> a[i].sc;
    }
    for(int i = 1;i<=n;i++){
        p[i] = i;
        mx[i] = a[i - 1];
        mn[i] = a[i - 1];
        s[i] = 1;
    }
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        _union(u, v);
    }
    vt<pair<pii, pii>> g;
    for(int i = 1;i<=n;i++){
        if(_find(i) == i){
            g.eb(mn[i], mx[i]);
        }
    }
    sort(all(g));
    // for(auto [P, PP] : g){
    //     cout << P.fi << ' ' << P.sc << ' ' << PP.fi << ' ' << PP.sc << '\n';
    // }
    int ans = 0;
    pii now = g[0].sc;
    for(int i = 1;i<sz(g);i++){
        if(g[i].fi < now) ++ans;
        now = max(now, g[i].sc);
        //cout << "NOW: " << now.fi << ' ' << now.sc << '\n';
    }
    cout << ans;
    return 0;
}