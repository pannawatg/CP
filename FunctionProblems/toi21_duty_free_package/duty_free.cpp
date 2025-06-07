#include <bits/stdc++.h>
using namespace std;
int minimum_bag_rearrangement_time(std::vector<int> a) {
  int ans = 0;
  int n = a.size();
  set<int> s;
  for(int i = 1;i<=n;i++){
    s.insert(-i);
  }
  vector<int> c;
  for(auto x : a){
    auto it = s.lower_bound(-x);
    if(it == s.end()){
      ++ans;
      for(auto i : c){
        s.insert(i);
      }
    }else{
      c.push_back(*it);
      s.erase(it);
    }
  }
  return ans;
}
