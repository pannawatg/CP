#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    cout << s.size() << ' ';
    int prev = s.size();
    for(int i = 1;i<s.size();i++){
        int l = 0;
        if(s[i] == s[i - 1]){
            l = prev - 1;
            l = max(l, 0);
        }else{
            for(int j = 0;j + i<s.size();j++){
                if(s[j] == s[i + j]){
                    ++l;
                }else{
                    break;
                }
            }
        }
        prev = l;
        cout << l << ' ';
    }   
    return 0;
}