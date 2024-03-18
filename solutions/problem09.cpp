#include <bits/stdc++.h>

using namespace std;

int main() {
  int a = 500;
  int b = 500 - a;
  int c = 0;
  while(true){
    if(b == 0) {
      a -= 1;
      b = 500 - 1;
      continue;
    }
    // simply a^2 + b^2 = c^2 and a+b+c = 1000 by substitution c = 1000-a-b
    // 1000(a+b) = 2*(500^2) + a*b
    int lhs = 1000*(a+b);
    int rhs = (a*b + 2*500*500);

    if (lhs == rhs) {
      c = 1000 - a - b;
      break;
    }
    b -= 1;
  }
  cout << "Product: " << a*b*c << endl;
  return 0;
}
