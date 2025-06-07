#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> pf(n + 1, vector<int>(3));
    for(int i = 1;i<=n;i++){
        int x;
        cin >> x;
        pf[i] = pf[i - 1];
        ++pf[i][x - 1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        for(int i = 0;i<3;i++){
            cout << pf[r][i] - pf[l - 1][i] << " \n"[i == 2];
        }
    }
}