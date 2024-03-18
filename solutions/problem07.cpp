#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
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
  vector<int> primes;
  int N = 200000;
  for(int i = 2; i < N; i++){
    if (isPrime(i))
      primes.push_back(i);
  }

  cout << "10001st Prime: " << primes[10000] << endl;

  return 0;
}
