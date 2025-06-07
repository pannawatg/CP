/*
* Author : NathInwza007
* Created : 2025-06-02 18:29:08 UTC+7
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

bool valid(int x, int y, int n, int m){
    if(x < 0 || y < 0 || x >= n || y >= m){
        return false;
    }
    return true;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int a[n][m];
    queue<pii> q;
    vt<pii> z;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> a[i][j];
            if(!a[i][j]){
                z.eb(i, j);
            }
        }
    }
    for(auto [x, y] : z){
        for(int i = 0;i<8;i++){
            int nx = x + d8x[i];
            int ny = y + d8y[i];
            if(valid(nx, ny, n, m)){
                a[nx][ny] = 0;
            }
        }
    }
    vt<vt<int>> dist(n, vt<int>(m, inf));
    for(int i = 0;i<n;i++){
        if(a[i][0]){
            q.push({i, 0});
            dist[i][0] = 1;
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int nx = x + d4x[i];
            int ny = y + d4y[i];
            if(valid(nx, ny, n, m) && dist[nx][ny] == inf && a[nx][ny]){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<m;j++){
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int ans = inf;
    for(int i = 0;i<n;i++){
        ans = min(ans, dist[i][m - 1]);
    }
    if(ans == inf){
        cout << -1 << '\n';
    }else{
        cout << ans << '\n';
    }
    return 0;
}