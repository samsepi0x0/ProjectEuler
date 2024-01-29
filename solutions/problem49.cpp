#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
  if(n%2 == 0)
    return false;
  for(int i = 3; i * i <= n; i++)
    if(n%i == 0)
      return false;
  return true;
}

bool checkSeq(int n) {
  vector<int> arr{0, 0, 0, 0};
  int t = n;
  int N0 = n;
  for(int i = 3; i >= 0; i--) {
    arr[i] = n % 10;
    n /= 10;
  }
  int count = 0;
  int N1 = 0, N2 = 0;
  do {
    int num = 0;
    for(int i = 0; i < 4; i++)
      num = num*10 + arr[i];

    if((num - t == 3330) && (isPrime(num))){
      if (N1 == 0)
        N1 = num;
      else 
        N2 = num;
      count++;
      t = num;
    }
  } while (next_permutation(arr.begin(), arr.end()));
  if (count == 2)
    cout << N0 << N1 << N2 << endl;
  return count == 2;
}

int main() {
  for(int i = 1487; i < 10000; i+=2) {
    if (isPrime(i)) {
      if (checkSeq(i)) {
        cout << endl;
      }
    }
  }
  return 0;
}
