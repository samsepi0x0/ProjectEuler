#include <bits/stdc++.h>
#include "primes.h"
#define ll long long

using namespace std;

int main() {
  int N = 1000000;
  vector<int> primes;
  for(int i = 2; i < N; i++) {
    if (isPrime(i))
      primes.push_back(i);
  }
  ll max_sum = 0;
  int max_run = -1;

  for(int i = 0; i < primes.size(); i++) {
    ll sum = 0;
    for(int j = i; j < primes.size(); j++) {
      sum += primes[j];
      if (sum >= N)
        break;
      if (isPrime(sum) && (sum > max_sum) && (j - i >= max_run)){
        max_run = j - i + 1;
        max_sum = sum;
      }
    }
  }
  cout << "Prime: " << max_sum << endl;
  cout << "Consecutive Count: " << max_run << endl;
  return 0;
}
