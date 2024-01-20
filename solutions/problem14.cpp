#include <bits/stdc++.h>

using namespace std;

int main(){
  int N = 1;
  int max_count = 0;
  int num = 0;
  unordered_map<int,int> m;
  while (N <= 1000000) {
    long long n = N;
    int count = 1;
    while (n != 1) {
      if (n%2 == 0)
        n /= 2;
      else
        n = (3*n) + 1;
      if (m.count(n) != 0){
        count += m[n];
        break;
      }
      count += 1;
    }
    m[N] = count;
    if (count > max_count) {
      num = N;
      max_count = count;
    }
    N += 1;
  }
  cout << "Number: " << num << endl;
}
