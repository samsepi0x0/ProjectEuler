#include<bits/stdc++.h>

using namespace std;

set<int> primes;

bool isPrime(int n){
  for(int i = 3; i * i <= n; i++)
    if (n%i == 0)
      return false;
  return true;
}

bool check_factors(int n, int c) {
  set<set<int>> factors;

  for(int i = 0; i < c; i++) {
    int val = n + i;
    int x = 0;
    set<int> f;
    while (val % 2 == 0) {
      if (x == 0)
        x = 1;

      x *= 2;
      val /= 2;
    }
    if (x > 0)
      f.insert(x);
    
    for(int i = 3; i < sqrt(val); i+=2) {
      x = 0;
      while(val%i == 0){
        if (x == 0)
          x = 1;
        x *= i;
        val /= i;
      }
      if (x > 0)
        f.insert(x);
    }
    
    if (val > 2)
      f.insert(val);

    if (f.size() != c)
      return false;

    factors.insert(f);
  }
  return factors.size() == c;
}

int main() {
  for(int i = 3; i <= 100; i+=2)
    if(isPrime(i))
      primes.insert(i);

  int start = 10;
  int consecutive = 4;
  
  for(int i = start; ; i++) {
    if (check_factors(i, consecutive)) {
      for(int j = i; j < i+consecutive; j++)
        cout << j << "\t";
      cout << endl;
      break;
    }
  }

  return 0;
}
