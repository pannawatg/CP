#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char c;
    string s;
    cin >> c >> s;
    map<char, int> mp;
    string k = "qwertyuiopasdfghjkl;zxcvbnm,./";
    for(int i = 0;i<k.size();i++){
        mp[k[i]] = i;
    }
    for(auto i : s){
        if(c == 'R'){
            cout << k[mp[i] - 1];
        }else{
            cout << k[mp[i] + 1];
        }
    }
    return 0;
}