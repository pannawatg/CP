#include <bits/stdc++.h>
using namespace std;
const int mxN = 1002;
int pf[mxN][mxN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ++a; ++b; ++c; ++d;
        ++pf[a][b];
        --pf[a][d];
        --pf[c][b];
        ++pf[c][d];
    }
    int ans = 0;
    for(int i = 1;i<mxN;i++){
        for(int j = 1;j<mxN;j++){
            pf[i][j] += pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
            if(pf[i][j] == k) ++ans;
        }
    }
    cout << ans << '\n';
}