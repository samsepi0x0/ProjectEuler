#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

int main() {
  int i = 286;
  int j = 166;
  int k = 144;

  while(true) {
    ll triangular = (ll)i*(i+1) / 2;
    ll pentagonal = (ll)j*(j*3 - 1) / 2;
    ll hexagonal = (ll)k*(k*2 - 1);

    ll m = min(min(triangular, pentagonal), hexagonal);
    if (m == triangular && m == pentagonal && m == hexagonal){
      cout << m << endl;
      return 0;
    }
    if (m == triangular)
      i++;
    if (m == pentagonal)
      j++;
    if (m == hexagonal)
      k++;
  }
  return 0;
}
