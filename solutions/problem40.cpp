#include <bits/stdc++.h>

using namespace std;

int nthChampernowne(int n) {
  // single digit
  if (n < 10)
    return n;
  
  int constant = 9;
  int multiplier = 10;
  int digit = 2;
  int t = 9;
  while(t <= n) {
    t = t + (constant*multiplier*digit);
    if (t >= n)
      break;
    multiplier *= 10;
    digit++;
  }
  cout << n << "\t" << multiplier << "\t" << digit << "\t";
  
  int m2 = 1;
  for(int i = 1; i < digit; i++){
    n -= 9*m2*i;
    m2 *= 10;
  }

  int p = n % digit;
  
  int val = multiplier + (n / digit);
  string value = to_string(val);
  int v = value[p-1] - 48;

  cout << value << "\t" << v << endl;
  return v;
}

int main() {
  int indexes[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
  int prod = 1;

  for(int i = 1; i < 7; i++) {
    int val = indexes[i];
    
    int digit = nthChampernowne(val);
    prod *= digit;
  }

  cout << "Product: " << prod << endl;

  return 0;
}
