#include <bits/stdc++.h>
using namespace std;

int main() {
  int x = 10;

  for(;; x++) {
    string v = to_string(x);
    sort(v.begin(), v.end());
    bool flag = true;
    for(int i = 2; i <= 6; i++) {
      int t = x * i;
      string s = to_string(t);
      sort(s.begin(), s.end());
      if (v != s){
        flag = false;
        break;
      }
    }
    if (flag){
      cout << "Number: " << x << endl;
      break;
    }
  }

  return 0;
}
