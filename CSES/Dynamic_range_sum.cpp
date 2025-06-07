#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 200001;
int a[mxN];
int seg[4 * mxN];
void build(int nd, int l, int r){
    if(l == r){
        seg[nd] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(nd * 2, l, mid);
    build(nd * 2 + 1, mid + 1, r);
    seg[nd] = seg[nd * 2] + seg[nd * 2 + 1];
}
int query(int nd, int l, int r, int L, int R){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return seg[nd];
    int mid = (l + r) >> 1;
    return query(nd * 2, l, mid, L, R) + query(nd * 2 + 1, mid + 1, r, L, R);
}
void update(int nd, int l, int r, int pos, int nw){
    if(l == r){
        seg[nd] = nw;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid){
        update(nd * 2, l, mid, pos, nw);
    }else{
        update(nd * 2 + 1, mid + 1, r, pos, nw);
    }
    seg[nd] = seg[nd * 2] + seg[nd * 2 + 1];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            update(1, 1, n, l, r);
        }else{
            cout << query(1, 1, n, l ,r) << '\n';
        }
    }
}