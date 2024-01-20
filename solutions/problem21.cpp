#include <bits/stdc++.h>

using namespace std;

int factors(int n) {
  int c = 0;
  for(int i = 1; i <= n/2; i++){
    if (n % i == 0){
      // cout << i << "\t";
      c += i;
    }
  }
  return c;
}

int main() {
  map<int, int> m;
  int N = 10000;
  
  for(int i = 1; i <= N; i++) {
    m[i] = factors(i);
  }
  
  int sum = 0;

  for(int i = 2; i < N; i++) {
    int x = m[i];
    if (m.find(x) != m.end()) {
      if (m[x] == i && x != i){
        sum += i;
      }
    }
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
