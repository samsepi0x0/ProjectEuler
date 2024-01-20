#include <bits/stdc++.h>

using namespace std;

int factorCount(int N){
  int count = 1;
  for(int i = 1; i <= N/2; i++){
    if (N%i == 0) {
      count += 1;
    }
  }
  return count;
}

int main(){ // not a great solution, bruteforce approach
  int N = 2;

  while (true){
    int trig_no = (N*(N+1)) / 2;
    int count = factorCount(trig_no);
    cout << N << "\t" << trig_no << "\t" << count << endl;
    if(count > 500)
      break;  
    N+= 1;
  }
  cout << "Number: " << N << endl;
}
