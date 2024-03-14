#include <bits/stdc++.h>
#include "bigint.h"
using namespace std;

int main() {
  int i = 1;
  int non_lychrel_count = 0;

  for(;i <= 10000; i++) {
    
    int iterations = 0;
    bool flag = false;
    bigint a(i);
    
    while (iterations <= 50) {
      
      bigint c = a;
      a = big_reverse(a);
      
      bigint d = c + a;
      c = d;
      c = big_reverse(c);
      
      if (c == d) {
        non_lychrel_count++;
        break;
      }

      a = d;
      iterations++;
    }
  }
  cout << "Count: " << 10000 - non_lychrel_count << endl;
  return 0;
}
