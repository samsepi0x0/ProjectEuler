#include <iostream>
#include "bigint.h"
#include <string>
using namespace std;

int main() {
  int a = 1;
  int b = 1;
  int N = 100;
  long long max_sum = 0;
  for(a; a < N; a++) {
    for(b; b < N; b++) {
      bigint A(a);
      bigint B(b);
      bigint C = big_pow(A, B);
      string s = C.str;
      long long sum = 0;
      for(int i = 0; i < s.length(); i++){
        sum += s[i]-48;
      }
      if (sum > max_sum)
        max_sum = sum;
    }
    b = 1;
  }
  cout << "Max_sum: " << max_sum << endl;
  return 0;
}
