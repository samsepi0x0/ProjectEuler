#include <bits/stdc++.h>

using namespace std;

set<int> abundants;

int factors(int n) {
  int c = 0;
  for(int i = 1; i <= n/2; i++){
    if (n % i == 0){
      c += i;
    }
  }
  return c;
}

bool isAbundantSum(int x){
  if (x < 12)
    return false;

  if(x > 28123)
    return true;

  for(auto i: abundants){
    if (i > x){
      return false;
    }
    int other = x - i;
    auto pos = abundants.find(other);
    if (pos == abundants.end())
      continue;
    return true;
  }
  return false;
}

int main() {
  int N = 28123;
  
  // calculate abundant numbers
  for(int i = 12; i <= N; i++) {
    int t = factors(i);
    if (t > i)
      abundants.insert(i);
  }
  // check generated list
  // cout << isAbundantSum(66) << endl;

  long sum = 0;
  for(int x = 1; x <= N; x++) {
    if (!isAbundantSum(x))
      sum += x;
  }
  
  cout << "Sum: " << sum << endl;
  return 0;
}
