#include <bits/stdc++.h>
#include "bigint.h"

using namespace std;

int main() {
  int counter = 0, N = 1000;
  bigint n = 1;
  bigint d = 1;

  for(int i = 0; i <= N; i++) {
    bigint n1 = 2*d + n;
    bigint d1 = d + n;

    if (n1.str.length() > d1.str.length())
      counter++;
    n = n1;
    d = d1;
  }
  cout << "Counter: " << counter << endl;
  return 0;
}
