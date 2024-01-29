#include <bits/stdc++.h>

using namespace std;

bool isSquare(int n) {
  int x = sqrt(n);
  return (x*x) == n;
}

bool isPrime(int n) {
  for(int i = 3; i * i <= n; i++){
    if(n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int n = 3;

  set<int> primes;
  primes.insert(2);
  for(int i = 3; i <= 10000; i+=2)
    if (isPrime(i))
      primes.insert(i);

  for(;; n+=2) {
    if (isPrime(n))
      continue;
    bool found = false;
    for(auto i : primes) {
      int x = n - i;
      if (x <= 0)
        break;
      else if (isSquare(x/2)) {
        found = true;
        //cout << n << " = " << i << " + 2 * " << sqrt(x/2) << endl;
        break;
      }
    }
    if (!found){
      cout << "Composite: " << n << endl;
      break;
    }
  }

  return 0;
}
