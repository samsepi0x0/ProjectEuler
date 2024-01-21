#include <bits/stdc++.h>

using namespace std;

int N = 1000000;
set<int> primes;

bool inSet(int n){
  auto x = primes.find(n);
  return x != primes.end();
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

bool truncatable(int n) {
  // not a prime
  if (!inSet(n))
    return false;

  string p = to_string(n);
  int N = p.length();
  // cout << "\t\t\t" << p << "\t" << N << endl;  
  for(int i = 0; i < N-1; i++) {
    string temp;
    for (int j = i + 1; j < N; j++)
      temp = temp + p[j];
    // cout << temp << endl;
    int t = stoi(temp);
    if (!inSet(t))
      return false;
  }

  for(int i = N - 1; i >= 1; i--) {
    string temp;
    for (int j = i - 1; j >= 0; j--)
      temp = p[j] + temp;
    // cout << temp << endl;
    int t = stoi(temp);
    if (!inSet(t))
      return false;
  }

  return true;
}

int main() {
  for(int i = 2; i < N; i++)
    if (isPrime(i))
      primes.insert(i);
  int sum = 0;
  for(int i = 10; i <= N; i++) {
    if (truncatable(i)){
      sum += i;
    }
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
