/*
* Author : Nathlol2
* Created : 2025-06-04 17:43:34 UTC+7
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

const int mxN = 100001;
vt<vt<pll>> adj(mxN);
vt<ll> dist(mxN, INF);
vt<int> p(mxN, -1);

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v, w;i<m;i++){
        cin >> u >> v >> w;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    dist[1] = 0;
    priority_queue<pll, vt<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]){
            continue;   
        }
        for(auto [v, w] : adj[u]){
            if(d + w < dist[v]){
                p[v] = u;
                dist[v] = d + w;
                pq.push({d + w, v});
            }
        }
    }
    if(dist[n] == INF){
        cout << -1;
        return 0;
    }
    vt<int> ans;
    int id = n;
    for(;p[id] != -1;id = p[id]){
        ans.pb(id);
    }
    ans.pb(1);
    reverse(all(ans));
    for(auto x : ans){
        cout << x << ' ';
    }
    return 0;
}