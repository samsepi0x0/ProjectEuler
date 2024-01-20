#include <bits/stdc++.h>

using namespace std;

int main(){
  int N = 100;

  int sum_of_nums = (N*(N+1)) / 2;
  int sum_of_sq_nums = (N*(N+1)*(2*N+1)) / 6;
  int diff = (sum_of_nums*sum_of_nums) - sum_of_sq_nums;
  cout << "Difference: " << diff << endl;
}
