#include <bits/stdc++.h>
#define BOUNDS 1000

using namespace std;

bool isSquare(int x) {
  int base = (int)(sqrt(x));
  return base*base == x;
}

int main(){
  int maxX = 0;
  int maxD = 0;
  for (int d = 2; d < BOUNDS; d++) {
    if (isSquare(d))
      continue;
    for (int x = 1; ; x++) {
      int val = (int)((pow(x, 2) - 1) / d);
      // cout << d << "\t" << x << "\t" << val << endl;

      if (val != 0 && isSquare(val)) {
        if (x > maxX) {
          maxX = x;
          maxD = d;
        }
        // cout << d << "\t" << x << "\n";
        break;
      }
    }
  }
  cout << "Max D: " << maxD << "\tFor max X: " << maxX << endl; 

}
