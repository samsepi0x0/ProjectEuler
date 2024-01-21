#include <bits/stdc++.h>

using namespace std;

int N = 1000000;
set<int> primes;

bool circularPrime(int n) {
  // not prime, dont care
  auto x = primes.find(n);
  if (x == primes.end())
    return false;

  // prime and single digit, no rotation
  if (n < 10)
    return true;
  
  string s = to_string(n);
  for(int i = 0; i < s.length() - 1; i++) {
    // rotates n-1 times;
  
    string new_s = "";
    for(int j = 1; j < s.length(); j++) {
      new_s += s[j];
    }
    new_s += s[0];
    s = new_s;
    int r = stoi(s);
    auto x = primes.find(r);
    if (x == primes.end())
      return false;
  }
  return true;
}

bool isPrime(int n) {
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for(int i = 3; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

int main() {
  for(int i = 2; i < N; i++) {
    if (isPrime(i)) {
      primes.insert(i);
    }
  }
  int count = 0;
  for(int i = 2; i <= N; i++) {
    if (circularPrime(i)) {
      count++;
    }
  }

  cout << "Count: " << count << endl;
  return 0;
}
