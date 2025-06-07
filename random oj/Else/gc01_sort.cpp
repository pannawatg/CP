/*
* Author : Nathlol2
* Created : 2025-06-05 22:06:23 UTC+7
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
    
    int n;
    cin >> n;
    vt<ll> a;
    for(int i = 0;i<n;i++){
        ll b;
        cin >> b;
        string s;
        cin >> s;
        ll v = 0, mul = 1;;
        for(int j = sz(s) - 1;j>=0;j--){
            int c;
            if(s[j] >= '0' && s[j] <= '9'){
                c = s[j] - '0';
            }else{
                c = s[j] - 'A' + 10;
            }
            v += c * mul;
            mul *= b;
        }
        ll ss = 0;
        for(int j = 1;j*j<=v;j++){
            if(v % j == 0){
                ss += j;
                ss += (v / j);
            }
        }
        a.pb(ss);
    }   
    sort(rall(a));
    for(int i = 0;i<n;i++){
        cout << a[i] << '\n';
    }
    return 0;
}