#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> pf(n + 1);
    for(int i = 1;i<=n;i++){
        cin >> pf[i];
        pf[i] ^= pf[i - 1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << (pf[r] ^ pf[l - 1]) << '\n';
    }
}