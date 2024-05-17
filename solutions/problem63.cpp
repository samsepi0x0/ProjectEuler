#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
  int count = 0;
  for(int i = 1; i < 10; i++) {
    for(int j = 1; j < 22 ; j++) {
      ull temp = pow(i, j);
      int len = to_string(temp).length();
      if (len == j) {
        count++;
      }
    }
  }
  cout << "Total Numbers: " << count + 1 << endl;
}
