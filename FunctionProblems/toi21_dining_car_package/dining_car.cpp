#include <bits/stdc++.h>
#include "dining_car.h"
using namespace std;

pair<int, int> locate_dining_cars(int n){
  pair<int, int> ans = {-1, -1};
  int l = 1, r = n;
  while(l < r){
    int mid = (l + r) / 2;
    int x = compare_cars(mid, mid + 1);
    if(x == -1){
      r = mid;
    }else{
      l = mid + 1;
    }
  }
  ans.first = l;
  int x = compare_cars();
  return ans;
}