#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	int a[n],b[m];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i= 0;i<m;i++){
		cin >> b[i];
	}
	int dp[n + 1][m +1];
	memset(dp, 0, sizeof dp);
	vector<vector<pair<int,int> > > p(n + 1, vector<pair<int, int> >(m + 1, {-1, -1}));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
				p[i][j] = make_pair(i - 1, j - 1);
			}else{
				if(dp[i - 1][j] >= dp[i][j - 1]){
					dp[i][j] = dp[i - 1][j];
					p[i][j] = make_pair(i - 1, j);
				}else{
					dp[i][j] = dp[i][j - 1];
					p[i][j] = make_pair(i, j - 1);
				}
			}
		}
	}
	vector<int> ans;
	int x = n, y = m;
	for(;x != 0 && y != 0;){
		int nx = p[x][y].first;
		int ny = p[x][y].second;
		if(x - 1 == nx && y - 1 == ny){
			ans.push_back(a[x - 1]);
		}
		x = nx;
		y = ny;
	}
	reverse(ans.begin(), ans.end());
	cout << dp[n][m] << '\n';
	for(size_t i = 0;i<ans.size();i++){
		cout << ans[i] << ' ';
	}
}
