#include <bits/stdc++.h>

using namespace std;

bool mult3_5(int n){
  return ((n%3 == 0) || (n%5 == 0));
}

int main(){
  int N = 1000;
  int sum = 0;
  for(int i = 1; i < N; i++){
    if (mult3_5(i)) {
      sum += i;
    }
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
