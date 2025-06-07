#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    int ans = 0;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        pos[x] = i;
    }
    int now = -1;
    for(int i = 1;i<=n;i++){
        if(pos[i] > now){
            now = pos[i];
        }else{
            ++ans;
            now = pos[i];
        }
    }
    cout << ans + 1;
}