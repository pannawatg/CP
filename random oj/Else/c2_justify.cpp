/*
* Author : NathInwza007
* Created : 2025-06-02 19:04:08 UTC+7
* What da hell is this question bruh
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l;
    cin >> n >> l;
    vt<string> a(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[0];
        return 0;
    }
    vt<vt<string>> g(1);
    int s = 0, idx = 0;
    for(int i = 0;i<n;i++){
        s += sz(a[i]);
        if(s > l){
            ++idx;
            g.pb(vt<string>());
            s = sz(a[i]);
        }
        ++s;
        g[idx].pb(a[i]);
    }
    if(g.back().empty()){
        g.pop_back();
    }
    for(int i = 0;i<sz(g) - 1;i++){
        int sl = 0;
        for(int j = 0;j<sz(g[i]);j++){
            sl += sz(g[i][j]);
        }
        if(sz(g[i]) == 0) continue;
        cout << g[i][0];
        if(sz(g[i]) == 1){
            for(int i = 0;i<l - sl;i++) cout << ' ';
            cout << '\n';
            continue;
        }
        int sp = (l - sl) / (sz(g[i]) - 1);
        int extra = (l - sl) - (sp * (sz(g[i]) - 1));
        for(int j = 1;j<sz(g[i]);j++){
            if(extra != 0) cout << ' ', --extra;
            for(int i = 0;i<sp;i++) cout << ' ';
            cout << g[i][j];
        }
        cout << '\n';
    }
    for(auto x : g[sz(g) - 1]){
        cout << x << ' ';
    }
    return 0;
}