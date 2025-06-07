#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a;
    vector<int> pf(n + 1);
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        int c = 1;
        while(x % 2 == 0){
            x /= 2;
            c <<= 1;
        }
        a.push_back(x);
        pf[i + 1] = pf[i] + c;
    }
    // for(int i = 1;i<=n;i++) cout << pf[i] << ' ';
    // cout << '\n';
    // for(int i = 0;i<n;i++) cout << a[i] << ' ';
    // cout << '\n';
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        auto it = lower_bound(pf.begin(), pf.end(), x) - pf.begin();
        cout << a[it - 1] << '\n';
    }
}