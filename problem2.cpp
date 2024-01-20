#include <bits/stdc++.h>

using namespace std;

int main(){
  int a = 1;
  int b = 2;
  int c = 0;
  int sum = 2;
  while (true){
    c = a + b;
    if (c > 4000000)
      break;
    a = b;
    b = c;
    if (c % 2 == 0){
      sum += c;
    }
  }
  cout << "Sum: " << sum << endl;
}
