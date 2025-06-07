#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("div7.in");
    ofstream cout("div7.out");
    int n;
    cin >> n;
    vector<int> pf(n + 1), l(7), r(7);
    for(int i = 1;i<=n;i++){
        cin >> pf[i];
        pf[i] += pf[i - 1];
        pf[i] %= 7;
    }
    for(int i = 1;i<=n;i++){
        r[pf[i]] = i;
    }
    for(int i = n;i>=1;i--){
        l[pf[i]] = i;
    }
    int ans = 0;
    for(int i = 0;i<7;i++){
        ans = max(ans, r[i] - l[i]);
    }
    cout << ans;
}