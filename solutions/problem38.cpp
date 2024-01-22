#include <bits/stdc++.h>

using namespace std;

bool isPandigital(string T) {
  int N = T.length();
  if(N != 9)
    return false;
  sort(T.begin(), T.end());
  return T == "123456789";
}

int main() {
  long long max = 0;
  for(int i = 1; i <= 100000; i++) {
    string temp;
    for(int n = 1; n <= 9; n++) {
      temp = temp + to_string(i*n);
      if (isPandigital(temp)) {
        long long t = stoi(temp);
        if (t > max)
          max = t;
      }
    }
  }
  cout << "Pandigit: " << max << endl;
  return 0;
}
