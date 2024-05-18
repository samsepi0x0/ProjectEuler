#include <bits/stdc++.h>
#include "bigint.h"

using namespace std;

int main() {
  bigint n(2);
  bigint prevN(1);

  int fract = 1;
  for(int k = 2; k < 101; k++) {
    bigint temp(prevN);
    if (k % 3 == 0)
      fract = 2 * (int)(k/3);
    else 
      fract = 1;
    prevN = n;
    n = fract * prevN + temp;
  }
  string x = n.str;
  int sum = 0;
  for(char c: x) {
    sum += (c - 48);
  }
  cout << "Sum of Numerator Digits: " << sum << endl; 
  return 0;
}
