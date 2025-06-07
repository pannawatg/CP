/*
* Author : NathInwza007
* Created : 2025-05-27 20:19:31 UTC+7
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
int todlek[205];
void solve(){
    memset(todlek, 0, sizeof todlek);
    string a, b;
    cin >> a >> b;
    reverse(all(a)); reverse(all(b));
    int n = sz(a), m = sz(b);
    int idx = 204, i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0){
        todlek[idx] = (a[i] - '0') + (b[j] - '0');
        --i; --j; --idx;
    }  
    if(i >= 0){
        for(int k = i;k>=0;k--){
            todlek[idx] = (a[k] - '0');
            --idx;
        }
    }
    if(j >= 0){
        for(int k = j;k>=0;k--){
            todlek[idx] = (b[k] - '0');
            --idx;
        }
    }
    for(int i = 204;i>0;i--){
        if(todlek[i] >= 10){
            todlek[i] -= 10;
            ++todlek[i - 1];
        }
    }
    vt<int> ans, realans;
    for(int i = 0;i<=204;i++){
        ans.pb(todlek[i]);
    }
    reverse(all(ans));
    bool st = false;
    for(auto x : ans){
        if(x != 0){
            st = 1;
        }
        if(st){
            realans.pb(x);
        }
    }
    while(realans.back() == 0){
        realans.pop_back();
    }
    for(auto x : realans){
        cout << x;
    }
    cout << '\n';
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