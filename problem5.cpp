#include <bits/stdc++.h>

using namespace std;

int main() {
  int N = 20;
  int primes[] = {2,3,5,7,11,13,17,19};
  
  vector<int> nums;
  for(int i = 1; i <= N; i++) {
    nums.push_back(i);
  }

  int lcm = 1;

  while(N != 0) {
    for(auto x : primes){
      bool used = false;
      for(int i = 0; i < N; i++) {
        if (nums[i] != 1){
          if (nums[i] % x == 0) {
            used = true;
            nums[i] = nums[i] / x;
          }
        }
      }
      if(used) {
        lcm *= x;
        break;
      }
    }
    int c = 0;
    for(int i = 0; i < N; i++) {
      if(nums[i] == 1)
        c += 1;
    }
    if(c == N)
      break;
  }
  cout << "Number: " << lcm << endl;

  return 0;
}
