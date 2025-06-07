#include <bits/stdc++.h>
using namespace std;
void io(string filename){
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}
const int INF = 1e9;
int dp[1001][1001];
int a[1001];
vector<vector<int>> adj(1001);
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    io("time");
    int n, m, c;
    cin >> n >> m >> c;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int t = 0;t<1001;t++){
        fill(dp[t], dp[t] + 1001, -INF);
    }
    int ans = 0;
    dp[0][1] = 0;
    for(int t = 0;t<1000;t++){
        for(int i = 1;i<=n;i++){
            if(dp[t][i] == -INF) continue;
            for(auto v : adj[i]){
                dp[t + 1][v] = max(dp[t + 1][v], dp[t][i] + a[v]);
            }
        }
        ans = max(ans, dp[t][1] - c * t * t);
    }
    cout << ans << '\n';
    return 0;
}