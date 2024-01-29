/*
 * Tn = (n*(n+1)) / 2
 * Substitute and make equation n^2 + n - 2a = 0;
 * If the discriminant (D = b^2 - 4ac) is a perfect square, the value (-b + D)/2 will give the value of the triangular sequence index.
 * Else the number is not a valid triangular number.
 */

#include <bits/stdc++.h>
using namespace std;

bool triangular(int n) {
  int t = 1 + 8*n;
  int N = sqrt(t);
  return (N*N) == t;
}

int main() {
  ifstream file("0042_words.txt");
  string line;

  getline(file, line);
  file.close();

  vector<string> tokens;
  
  stringstream check(line);
  string immediate;

  while(getline(check, immediate, ','))
    tokens.push_back(immediate);

  int triangular_count = 0;
  for(auto x: tokens) {
    x = x.substr(1, x.length()-2);
    int sum = 0;

    for(int i = 0; i < x.length(); i++) {
      int a = int(x[i]) - 64;
      sum += a;
    }
    if (triangular(sum)) {
      triangular_count ++;
    }
  }
  
  cout << "Triangular Count: " << triangular_count << endl;

  return 0;
}
