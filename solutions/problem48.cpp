#include <bits/stdc++.h>
#include "bigint.h"

using namespace std;

int main() {
  int N = 1000;
  BigInt result;
  for(int i = 1; i <= N; i++) {
    BigInt temp(i);
    for(int j = 1; j < i; j++){
      temp *= i;
    }
    result += temp;
  }
  string s = get_digits(result);
  int n = s.length();
  string last_digits;
  for(int i = n - 1; i >= n-10; i--)
    last_digits = s[i] + last_digits;
  cout << "Last 10 digits: " << last_digits << endl;
  return 0;
}
