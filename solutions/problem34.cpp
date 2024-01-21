#include <bits/stdc++.h>

using namespace std;

vector<int> fact_computed(10, 1);

int fact(int n){
  if(n <= 2)
    return n;
  return n*fact(n-1);
}

bool curious(int n) {
  int n_copy = n;
  int fact_sum = 0;

  while (n != 0){
    int r = n % 10;
    fact_sum += fact_computed[r];
    n /= 10;
  }
  return fact_sum == n_copy;
}

int main() {
  int N = 50000;
  int sum = 0;

  for(int i = 1; i < 10; i++)
    fact_computed[i] = fact(i);
  
  for(int i = 10; i <= N; i++) {
    if (curious(i))
      sum += i;
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
