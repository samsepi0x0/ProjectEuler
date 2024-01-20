#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

bool isPrime(int N) {
  if (N <= 1)
    return false;
  if (N % 2 == 0)
    return false;
  for(int i = 3; i < N/2; i++){
    if (N % i == 0)
      return false;
  }
  return true;
}

int solve_quad(int a, int b) {
  int N = 0;

  while(true) {
    int x = (N*N) + (a*N) + b;
    auto val = find(primes.begin(), primes.end(), x);
    if (val != primes.end()) {
      N += 1;
    } else {
      if (isPrime(x)) {
        primes.push_back(x);
        N += 1;
      } else {
        break;
      }
    }
  }
  return N;
}

int main(){
  int max_primes = 0;
  long long product = 0;

  for(int a = -999; a <= 999; a++) {
    for(int b = -1000; b <= 1000; b++) {
      int primes_in_range = solve_quad(a, b);
  
      if (primes_in_range >= max_primes){
        max_primes = primes_in_range;
        product = a*b;
      }

    }
  }
  cout << "Product: " << product << endl;
}
