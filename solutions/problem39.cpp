/*
 * a + b + c = p
 * c = p - a - b
 *
 * c^2 = a^2 + b^2
 *
 * substituting c in above equation: 
 * => p^2 + 2ab = 2p(a + b)
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
  int max = 0;
  int max_p = 0;
  int N = 1000;
  for(int p = 4; p <= N; p++){
    vector<set<int>> values;
    for(int a = 1; a <= p; a++) {
      for(int b = a; b <= p-a; b++) {
        if ((p*p + 2*a*b) == (2*p*(a+b))){
          set<int> s;
          s.insert(a);
          s.insert(b);
          s.insert(p-a-b);
          values.push_back(s);
        }
      }
    }
    int N = values.size();
    if (N >= max){
      max = N;
      max_p = p;
    }
  }
  cout << "Pairs: " << max << " for P: " << max_p << endl;
}
