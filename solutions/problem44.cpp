#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  set<ll> pentagonal;
  for(int n = 1; n <= 5000; n++) {
    ll p = (n*(3*n-1))/2;
    pentagonal.insert(p);
  }
  
  ll d_min = INT_MAX;

  for(auto j: pentagonal) {
    for(auto k: pentagonal) {
      if(j == k)
        continue;
      ll sum = j + k;
      auto x = pentagonal.find(sum);
      if (x == pentagonal.end())
        continue;
      ll diff = k - j;
      x = pentagonal.find(diff);
      if (x == pentagonal.end())
        continue;
      // cout << j << "\t" << k << endl;
      ll d = abs(k - j);
      if (d < d_min)
        d_min = d;
    }
  }
  cout << "D: " << d_min << endl;
  return 0;
}
