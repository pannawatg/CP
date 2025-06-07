#include <bits/stdc++.h>
using namespace std;
const int mxN = 3005;
vector<vector<int>> adj(mxN);
bool vis[mxN];
bool close[mxN];
int c = 0;
void dfs(int u){
    vis[u] = 1;
    ++c;
    for(auto v : adj[u]){
        if(!vis[v] && !close[v]){
            dfs(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> q(n);
    for(int i = 0;i<n;i++){
        cin >> q[i];
    }
    memset(close, 0, sizeof close);
    c = 0;
    dfs(1);
    if(c == n){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    for(int i = 0;i<n - 1;i++){
        close[q[i]] = 1;
        c = 0;
        memset(vis, 0 ,sizeof vis);
        dfs(q[n - 1]);
        if(c == n - i - 1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}