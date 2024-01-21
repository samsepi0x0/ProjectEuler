#include <bits/stdc++.h>

using namespace std;

int main() {
  int N = 10;
  int D = N + 1;
  int count = 0;
  double prod = 1;
  for(N = 10; N <= 99; N++)
    for(D = N + 1; D <= 99; D++) {
      double frac = double(N) / double(D);
      if (frac < 1.0) {
        int N_unit = N % 10;
        int N_ten = N / 10;
        int D_unit = D % 10;
        int D_ten = D / 10;
        if (D_unit == 0 || N_unit == 0 || D_unit == D_ten || N_unit == N_ten)
          continue;
        if (D_ten == N_unit){
          double simplified_frac = double(N_ten) / double(D_unit);
          if (simplified_frac == frac) {
            count++;
            //cout << N_ten << N_unit << "/" << D_ten << D_unit << "\t" << simplified_frac << "\t" << frac << endl;
            prod *= simplified_frac;
          }
        }
      }
    }
  cout << "Product: " << prod << endl;
  return 0;
}
