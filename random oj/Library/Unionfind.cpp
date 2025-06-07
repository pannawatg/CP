#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5;
int p[mxN];
int _find(int x){
    if(x == p[x]){
        return x;
    }
    return p[x] = _find(p[x]);
}
void _union(int x, int y){
    int X = _find(x), Y = _find(y);
    p[X] = Y;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0;i<mxN;i++){
        p[i] = i;
    }
    int n, q;
    cin >> n >> q;
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            _union(u, v);
        }else{
            cout << (_find(u) == _find(v)) << '\n';
        }
    }
    return 0;
}