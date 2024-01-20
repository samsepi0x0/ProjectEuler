#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool isPrime(int n){
  if(n % 2 == 0)
    return false;
  for(int i = 2; i <= sqrt(n); i++){
    if(n % i == 0)
      return false;
  }
  return true;
}

int main(){
  int N = 2000000;
  ll sum = 2;
  for(int i = 3; i <= N; i++){
    if(isPrime(i)){
      sum += i;
    }
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
