#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

bool isPrime(long x) {
    if (x == 0 || x == 1)
      return false;
    if (x % 2 == 0)
      return false;
    for (int i = 3; i * i <= x; i++) 
        if (x % i == 0)
            return false;    
    return true;
}

bool check(int x, int y) {
  string X = to_string(x); 
  string Y = to_string(y);

  return isPrime(stol(X+Y)) && isPrime(stol(Y+X));
}

int main() {
  int N = 10000;
  for(int i = 1; i < N; i++)
    if (isPrime(i))
      primes.push_back(i);
  cout << "Primes generated!" << endl;
  
  for(auto a: primes) {
    for(auto b: primes) {
      if (a < b)
        continue;
      if (check(a, b)) {
        for(auto c: primes) {
          if (c < b)
            continue;
          if (check(a,c) && check(b, c)) {
            for(auto d: primes) {
              if (d < c)
                continue;
              if (check(a, d) && check(b, d) && check(c, d)) {
                for(auto e: primes) {
                  if (e < d)
                    continue;
                  if (check(a, e) && check(b, e) && check(c, e) && check(d, e)) {
                    cout << "Prime Pairs: " << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl;
                    cout << "Sum: " << (a+b+c+d+e) << endl;
                    return 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
