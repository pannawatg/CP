/*
* Author : Nath
* Created : 2025-05-24 18:45:33 UTC+7
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y, z;
    cin >> x >> y >> z;
    for(int a = 1;a<=100;a++){
        if(x % a != 0){
            continue;
        }
        int c = x / a;
        for(int b = -100;b<=100;b++){
            if(b == 0 || z % b != 0){
                continue;
            }
            int d = z / b;
            if(b * c + a * d == y){
                cout << a << ' ' << b << ' ' << c << ' ' << d;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}