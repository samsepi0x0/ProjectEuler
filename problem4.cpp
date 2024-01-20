#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int N){
  int x = N;
  int r = 0;

  while (x != 0){
    int t = x % 10;
    r = r*10 + t;
    x /= 10;
  }
  return r == N;
}

int main() {
  int a = 999;
  int b = 999;
  int max_palin = 0;
  while(a != 0) {
    if (isPalindrome(a*b)) {
      max_palin = max(max_palin, a*b);
    }
      b -= 1;
      if (b == 0) {
        a -= 1;
        b = 999;
    }
  }
  cout << "Palindrome: " << max_palin << endl;
  return 0;
}
