#include <bits/stdc++.h>

using namespace std;

int divide(int x) {
  //set<int> remainder;
  vector<int> remainder;
  int N = 1;

  while(true) {
    int q = N / x;
    N = N % x;
    if (N == 0)
      return 0;
    auto val = find(remainder.begin(), remainder.end(), N);
    if (val == remainder.end()) {
      remainder.push_back(N);
    } else {
      int v = val - remainder.begin();
      return remainder.size() - v;
    }
    N *= 10;
  }
  return -1;
}

int main() {
  int N = 1000;
  int max_i = 0;
  int max_recurring = 0;
  for(int i = 1; i < N; i++){
    int x = divide(i);
    if (x > max_recurring){
      max_i = i;
      max_recurring = x;
    }
  }
  cout << "Max Element: " << max_i << "\t" << "with recurring digits: " << max_recurring << endl; 
  return 0;
}
