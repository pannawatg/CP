/*
* Author : Nathlol2
* Created : 2025-06-04 18:49:20 UTC+7
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

const int mxN = 1e6 + 1;
int seg[4 * mxN], a[mxN];
void build(int l, int r, int nd){
    if(l == r){
        seg[nd] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, nd * 2);
    build(mid + 1, r, nd * 2 + 1);
    seg[nd] = seg[nd * 2] + seg[nd * 2 + 1];
}
void upd(int l, int r, int nd, int idx, int v){
    if(l == r){
        seg[nd] = v;
        return;
    }
    int mid = (l + r) / 2;
    if(idx <= mid){
        upd(l, mid, nd * 2, idx, v);
    }else{
        upd(mid + 1, r, nd * 2 + 1, idx, v);
    }
    seg[nd] = seg[nd * 2] + seg[nd * 2 + 1];
}
int query(int l, int r, int L, int R, int nd){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return seg[nd];
    int mid = (l + r) / 2;
    return query(l, mid, L, R, nd * 2) + query(mid + 1, r, L, R, nd * 2 + 1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;   
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    build(1, n, 1);
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        while(t--){
            int idx, v;
            cin >> idx >> v;
            upd(1, n, 1, idx + 1, v);
        }
        int l, r;
        cin >> l >> r;
        cout << query(1, n, l + 1, r + 1, 1) << '\n';
    }
    return 0;
}