#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, p;
    cin >> n >> k >> p;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    int l = 0, r = 1e9, ans = -1;
    while(l <= r){
        int m = (l + r) >> 1;
        bool ok = true;
        int tmp = k;
        for(int i = 0;i<n;i++){
            if(a[i] > m && tmp >= 1){
                --tmp;
                i += p - 1;
            }else if(a[i] > m){
                ok = 0;
            }
        }
        if(ok && *min_element(a, a + n) <= m){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    cout << ans << '\n';
}