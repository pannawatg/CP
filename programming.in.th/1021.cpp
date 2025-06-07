#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    priority_queue<int> pq;
    while(q--){
        char c;
        cin >> c;
        if(c == 'P'){
            int x;
            cin >> x;
            pq.push(x);
        }else{
            if(pq.size()) cout << pq.top() << '\n', pq.pop();
            else cout << -1 << '\n';
        }
    }   
    return 0;
}