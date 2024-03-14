#include <bits/stdc++.h>

using namespace std;

int main() {
  int count = 0;  
  long mod = 1000000007;

  for(int n = 1; n <= 100 ; n++) {
    int r_max = ceil(n/2);
  
    for(int r = 1; r <= n; r++) {
    
      int n_r = n - r;
      
      int f_n = max(r, n_r);
      int f_r = min(r, n_r);
      
      unsigned long long  num = 1, den = 1;

      for(int i = n; i > f_n; i--)
        num *= i % mod;
      for(int i = 1; i <= f_r; i++)
        den = (den * i) % mod;
      unsigned long long ans = num / den;
      cout << n << "\t" << r << "\t" << num << "\t \\ \t" << den << "\t" << ans << endl;
      if (ans >= 1000000) {
        count++;
      } 
    }
  }
  cout << "Count: " << count << endl;

  return 0;
}
