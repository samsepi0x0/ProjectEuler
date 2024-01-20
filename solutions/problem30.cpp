#include <bits/stdc++.h>
using namespace std;

int main(){
  int P = 5;
  int max_limit = 1000000;
  int counter = 2;
  int sum = 0;

  while (counter < max_limit) {
    int temp = counter;
    int temp_sum = 0;
    while(temp != 0) {
      int r = temp%10;
      temp_sum += (static_cast<int>(pow(r, P)));
      temp /= 10;
    }
    if (temp_sum == counter){
      // cout << counter << "\t";
      sum += counter;
    }
    counter++;
  }
  cout << "Sum: " << sum << endl;
}
