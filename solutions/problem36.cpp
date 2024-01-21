#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(int N) {
  // check if N is palindrome;
  string x = to_string(N);
  string x_copy = x;
  reverse(x.begin(), x.end());
  if (x != x_copy)
    return false;
  string bin = "";
  while (N != 0) {
    int r = N % 2;
    bin = bin + to_string(r);
    N /= 2;
  }
  string bin_copy = bin;
  reverse(bin.begin(), bin.end());
  return bin == bin_copy;
}

int main() {
  int N = 1000000;
  long long sum = 0;
  for(int i = 1; i <= N; i++) {
    if (checkPalindrome(i)){
      //cout << i << "\t";
      sum += i;
    }
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
