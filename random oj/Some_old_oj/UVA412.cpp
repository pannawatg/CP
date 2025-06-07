/*
* Author : NathInwza007
* Created : 2025-05-27 20:04:31 UTC+7
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
int gcd(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd(y, x % y);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(1){
        int n;
        cin >> n;
        if(!n) break;
        vt<int> a(n);
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        bool f = false;
        ld y = 0, c = 0;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                if(gcd(a[i], a[j]) == 1){
                    ++y;
                    f = 1;
                }
                ++c;
            }
        }
        if(!f){
            cout << "No estimate for this data set.\n";
        }else{
            cout << fixed << setprecision(6) << sqrt(c * 6.0 / y) << '\n';
        }
    }
    return 0;
}