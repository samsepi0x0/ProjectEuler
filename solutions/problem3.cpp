#include <bits/stdc++.h>

using namespace std;

int main() {
  long int N = 600851475143;
  //long int N = 13195;
  int factor = 1;
  // generate prime numbers
  int max_limit = 105003;
  bool sieve[max_limit];
  for(int i = 0; i < max_limit; i++){
    sieve[i] = true;
  }
  vector<int> prime;

  for(int i = 2; i < max_limit; i++) {
    if (sieve[i]){
      prime.push_back(i);
      for(int j = i+1; j < max_limit; j++) {
        if (sieve[j])
          sieve[j] = j % i;
      }
    }
  }
  cout << "Problem 7: " << prime[10000] << endl;
  while(N != 1) {
    for(auto i: prime) {
      if(N % i == 0) {
        N = static_cast<long int>(N / i);
        factor = max(factor, i);
        break;
      }
    }
  }
  cout << "Factor: " << factor << endl;
  return 0;
}
