/*
* Author : NathInwza007
* Created : 2025-05-28 21:26:48 UTC+7
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
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool valid(int x, int y, int n, int m){
	if(x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return true;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	string a[n];
	for(int i = 0;i<n;i++)
		cin >> a[i];
	queue<pair<int, int>> q;
	q.push({0, 0});
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		if(a[x][y] == '.')
			a[x][y] = 'W';
		else
			continue;
		for(int i = 0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!valid(nx, ny, n, m))
				continue;
			if(a[nx][ny] == '.'){
				q.push({nx, ny});
			}
		}
	}
	vector<vector<bool>> v(n, vector<bool>(m, false));
	int ans = -1;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(a[i][j] == 'X' && !v[i][j]){
				queue<pair<int, int>> qq;
				qq.push({i, j});
				int c = 0;
				while(!qq.empty()){
					auto [x, y] = qq.front();
					qq.pop();
					if(!v[x][y])
						v[x][y] = true;
					else
						continue;
					for(int i = 0;i<4;i++){
						int nx = x + dx[i];
						int ny = y + dy[i];
						if(!valid(nx, ny, n, m))
							continue;
						if(a[nx][ny] == 'W')
							c++;
						if(a[nx][ny] == 'X' && !v[nx][ny])
							qq.push({nx, ny});
					}
				}
				ans = max(c, ans);
			}
		}
	}
	cout << ans << '\n';
}
