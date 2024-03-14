#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool isPrime(ll x){
  if (x == 1)
    return false;
  if (x % 2 == 0)
    return false;
  for(ll i = 3; i*i <= x; i++)
    if (x % i == 0)
      return false;
  return true;
}

int main() {
  vector<ll> arr;
  ll i = 1;
  int step = 2;
  ll row = 3;
  int pCount = 0;

  while (true) {
    if (i == row*row) {
      int res = (pCount / (double)(arr.size() + 1)) * 100;
      //cout << "Row: " << row << "\t" << "Primes: " << pCount << "\t" << "Array length: " << arr.size() + 1 << "\tRatio: " << res << endl;

      if (res < 10){
        cout << "Row: " << row << endl;
        break;
      } else {
        step += 2;
        row += 2;
      }
    
    }
    else {
      if (isPrime(i))
        pCount++;
      arr.push_back(i);
      i += step;
    }
  }
  return 0;
}
