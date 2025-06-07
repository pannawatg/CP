/*
* Author : NathInwza007
* Created : 2025-05-30 19:26:56 UTC+7
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vt<string> a(n + 1);
    a[1] = "sin(1)";
    for(int i = 2;i<=n;i++){
        a[i] = "sin(1";
        for(int j = 2;j<=i;j++){
            if(j == i){
                if(j % 2 == 0){
                    a[i] += "-sin(";
                }else{
                    a[i] += "+sin(";
                }
                a[i] += to_string(j);
                for(int k = 0;k<i;k++){
                    a[i] += ")";
                }
                continue;
            }
            if(j % 2 == 0){
                a[i] += "-sin(";
                a[i] += to_string(j);
            }else{
                a[i] += "+sin(";
                a[i] += to_string(j);
            }
        }
    }   
    for(int i = 0;i<n - 1;i++){
        cout << "(";
    }
    for(int i = 0;i<n - 1;i++){
        cout << a[i + 1] << "+" << to_string(n - i) << ")";
    }
    cout << a[n] << "+1";
    return 0;
}