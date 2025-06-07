/*
* Author : Nathlol2
* Created : 2025-06-03 20:04:39 UTC+7
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
 
vt<int> find_subset(int l, int r, vt<int> v){
    vt<pii> a;
    for(int i = 0;i<sz(v);i++){
        a.eb(v[i], i);
    }
    sort(all(a));
    ll s = 0;
    int b = 0;
    vt<int> ans;
    for(int i = 0;i<sz(a);i++){
        s += a[i].fi;
        if(s > r){
            s -= a[b].fi;
            ++b;
        }
        if(s >= l && s <= r){
            for(int j = b;j<=i;j++){
                ans.pb(a[j].sc);
            }
            break;
        }
    }
    return ans;
}