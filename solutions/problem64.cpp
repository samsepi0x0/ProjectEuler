#include <bits/stdc++.h>

using namespace std;

vector<int> period(int n) {
  int root = floor(sqrt(n));
  if (root * root == n)
    return {};
  int a = root;
  int num = 0;
  int den = 1;

  vector<int> period;
  while (a != (2*root)) {
    num = den*a - num;
    den = (n - num*num)/den;
    a = (root+num)/den;
    period.push_back(a);
  }
  return period;
}

int main() {
  int count = 0;
  for(int i = 2; i < 10000; i++) {
    vector<int> pc = period(i);
    if (pc.size() % 2 != 0)
      count++;
  }
  cout << "Odd Count periods: " << count << endl;
}
