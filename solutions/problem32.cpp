#include <bits/stdc++.h>

using namespace std;

set<int> nums;

bool isPandigit(string s){
  int N = s.length();
  if (N != 9)
    return false;
  sort(s.begin(), s.end());
  return (s == "123456789");
}

bool check(int n) {
  auto x = nums.find(n);
  if (x != nums.end()){
    return false;
  }

  for(int i = 1; i <= n/2; i++) {
    if ((n % i == 0) && isPandigit(to_string(n) + to_string(i) + to_string(n/i))){
      nums.insert(n);
      return true;
    }
  }
  
  return false;
}

int main() {
  int sum = 0;
  for(int i = 0; i <= 10000; i++) {
    if (check(i)){
      sum += i;
    }
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
