#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int mxN = 1e6;
pair<int, int> a[mxN];
int d, l, n;
vector<vector<int>> ans;
bool ok(int x){
    ans.clear();
    ans.resize(d);
    int p = 0;
    for(int i = 0;i<d;i++){
        int j;
        for(j = p;j<min(n, p + x);j++){
            if(a[j].f <= i + 1){
                if(a[j].f >= i - l + 1){
                    ans[i].push_back(a[j].s);
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        p = j;
    }
    if(p == n){
        return true;
    }else{
        return false;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> d >> l >> n;
    ans.resize(d);
    for(int i = 0;i<n;i++){
        cin >> a[i].f;
        a[i].s = i + 1;
    }
    sort(a, a + n);
    int l = 0, r = n + 10, x = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(ok(mid)){
            x = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    if(ok(x)){}
    cout << x << '\n';
    for(int i = 0;i<d;i++){
        for(auto e : ans[i]){
            cout << e << ' ';
        }
        cout << "0\n";
    }
    return 0;
}