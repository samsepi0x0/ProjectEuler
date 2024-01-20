#include <bits/stdc++.h>

using namespace std;

int main() {
  int N = 1000000;
  string nums = "0123456789";
  long int i = 1;

  do {
    if (i == N)
      break;
    i++;
  } while (next_permutation(nums.begin(), nums.end()));

  cout << N << "th Permutation: " << nums << endl;
}
