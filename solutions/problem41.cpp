#include <bits/stdc++.h>

using namespace std;

bool isPandigital(string s) {
  int N = s.length();
  sort(s.begin(), s.end());
  string comp = "123456789";
  comp = comp.substr(0, N);
  return s == comp;
}

bool isPrime(int n) {
  if (n % 2 == 0)
    return false;
  for(int i = 3; i * i <= n; i++)
    if (n%i == 0)
      return false;
  return true;
}


bool check(int i) {
  if (!isPandigital(to_string(i)))
    return false;
  return isPrime(i);
}

int main() {
  int N = 10000000;
  for(int i = N - 1; i >= 201; i-=2) {
    if(check(i)) {
      cout << "Largest PanDigital Prime: " << i << endl;
      break;
    }
  }
  return 0;
}
