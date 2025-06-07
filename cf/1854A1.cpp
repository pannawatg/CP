/*
* Author : Nathlol2
* Created : 2025-06-04 16:24:14 UTC+7
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
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    int idx = -1;
    for(int i = n - 1;i>=0;i--){
        if(a[i] >= 1){
            idx = i;
            break;
        }
    }
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(a[i] == 0) ++cnt;
    }
    if(cnt == n){
        cout << "0\n";
        return;
    }
    //cout i j adding a[j] to a[i]
    if(idx == -1){
        for(int i = 0;i<n;i++){
            if(a[i] < 0){
                idx = i;
                break;
            }
        }
        vt<pii> ans;
        for(int i = 0;i<8;i++){
            ans.eb(idx, idx);
        }
        for(int i = n - 1;i>idx;i--){
            ans.eb(i, idx);
            ans.eb(idx, idx);
        }
        for(int i = idx - 1;i>=0;i--){
            ans.eb(i, i + 1);
            ans.eb(i, i + 1);
        }
        cout << sz(ans) << '\n';
        for(auto [x, y] : ans){
            cout << x + 1 << " " << y + 1 << '\n';
        }
    }else{
        vt<pii> ans;
        for(int i = 0;i<8;i++){
            ans.eb(idx, idx);
        }
        for(int i = 0;i<idx;i++){
            ans.eb(i, idx);
            ans.eb(idx, idx);
        }
        for(int i = idx + 1;i<n;i++){
            ans.eb(i, i - 1);
            ans.eb(i, i - 1);
        }
        cout << sz(ans) << '\n';
        for(auto [x, y] : ans){
            cout << x + 1 << " " << y + 1 << '\n';
        }
    }
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