#include <bits/stdc++.h>
 
using namespace std;

__uint128_t gcd(__uint128_t a, __uint128_t b) {
  while (b != 0) {
    __uint128_t c = a % b;
    a = b;
    b = c;
  }
  return a;
}

__uint128_t solveFrac(vector<int>& arr, int D) {
  int n = arr.size() - 1; // period length
  if (n % 2 != 0) {
    for(int i = 1; i < n; i++)
      arr.push_back(arr[i]);
  } // 2k-1
  for(int k = 1; k < arr.size(); k++) {
    __uint128_t num = 1;
    __uint128_t den = 0;
    for(int i = k; i >= 0; i--) {
      __uint128_t n = den + num*arr[i];
      __uint128_t d = num;
      __uint128_t g = gcd(n, d);
      num = n / g;
      den = d / g;
    }
    if (((num*num) - (D*den*den)) == 1) {
      return num;
    }
  }
  return -1;
}

vector<int> expand(int n) {
  int f = floor(sqrt(n));
  if (f*f == n)
    return {f};
  vector<int> res;
  int num0 = 0;
  int den0 = 1;

  while (true) {
    int next = (int)(floor(sqrt(n) + num0) / den0);
    res.push_back(next);

    int num1 = den0;
    int den1 = num0 - (den0*next);

    int den2 = (n - (den1*den1)) / num1;
    int num2 = -1 * den1;

    if (den2 == 1){
      res.push_back(2*res[0]);
      break;
    }
    num0 = num2;
    den0 = den2;
  }
  return res;
}

int main() {
  __uint128_t X = 0;
  int D = 0;
  for(int d = 2; d <= 1000; d++) {
    int f = floor(sqrt(d));
    if (f*f == d)
      continue;
    vector<int> pc = expand(d);
    // cout << "D: " << d << "\tPC SIZE: " << pc.size();
    __uint128_t n = solveFrac(pc, d);
    if (n > X) {
      X = n;
      D = d;
    }
  }
  cout << "Max D: " << D << endl;
  return 0;
}
