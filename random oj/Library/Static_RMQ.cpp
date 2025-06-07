#include <bits/stdc++.h>
using namespace std;
const int mxN = 5e5 + 5;
int seg[4 * mxN];
int a[mxN];
void build(int nd, int l, int r){
    if(l == r){
        seg[nd] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(nd * 2, l, mid);
    build(nd * 2 + 1, mid + 1, r);
    seg[nd] = min(seg[nd * 2], seg[nd * 2 + 1]);
}
int query(int nd, int l, int r, int L, int R){
    if(l > R || r < L){
        return INT_MAX;
    }
    if(l >= L && r <= R){
        return seg[nd];
    }
    int mid = (l + r) >> 1;
    return min(query(nd * 2, l, mid, L, R), query(nd * 2 + 1, mid + 1, r, L, R));
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--){
        int l, r;
        cin >> l >> r;
        ++l;
        cout << query(1, 1, n, l, r) << '\n';
    }
}