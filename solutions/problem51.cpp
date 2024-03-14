#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
  if (x % 2 == 0)
    return false;
  for(int i = 3; i * i <= x; i++)
    if (x % i == 0)
      return false;
  return true;
}

bool msb(int t) {
  while (t < 10) {
    t /= 10;
  }
  return t;
}

int main() {
  int N = 500000;
  
  for(int i = 13; ; i++) {

    if(isPrime(i)){
      string prime = to_string(i);
      for(int j = 0; j < prime.length(); j++) {
        char c = prime[j];
        int count = 1;        
        for(char ch = c; ch <= '9'; ch++) {
          string temp = prime;
          replace(temp.begin(), temp.end(), c, ch);
          int t = stoi(temp);
          if (temp[0] == '0')
            continue;
          if (isPrime(t) && t != i) {
            count++;
          }
        }
        if (count == 8) {
          cout << "Prime: " << i << endl;
          return 0;
        }
      }
    }
  }

  return -1;
}
