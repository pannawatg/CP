#include <bits/stdc++.h>
using namespace std;
void io(string s){
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    io("hps");
    int n;
    cin >> n;
    vector<vector<int>> pf(n + 1, vector<int>(3));
    for(int i = 1;i<=n;i++){
        char c;
        cin >> c;
        pf[i] = pf[i - 1];
        if(c == 'H'){
            ++pf[i][0];
        }else if(c == 'P'){
            ++pf[i][1];
        }else{
            ++pf[i][2];
        }
    }
    int ans = 0;
    for(int i = 1;i<=n + 1;i++){
        for(int f = 0;f<3;f++){
            for(int g = 0;g<3;g++){
                ans = max(ans, (pf[i - 1][f]) + (pf[n][g] - pf[i - 1][g]));
            }
        }
    }
    cout << ans;
}