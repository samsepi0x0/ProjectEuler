/* This program prints a spiral matrix and returns the sum of elements in diagonal.
 * Starting from the middle element in a matrix, the pattern goes right -> down -> left and up before repeating itself. *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int N = 1001;
  int arr[N][N];
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      arr[i][j] = 0;
  
  int step = 1;
  int K = N/2;
  arr[K][K] = step;

  int margin = K - 1;
  int i = K;
  int j = K+1;
  while(step <= (N*N)) {
    for(; j < (N - margin); j++){
      arr[i][j] = ++step;
      if(step == (N*N))
        break;
      // cout << "Right: " << i << "\t" << j << "\t" <<  step << endl;
   }
    if(step == (N*N))
      break;
    j--; // stay in same column, for loop messes it up
    i++; // move down a row
    for(; i < (N - margin); i++){
      arr[i][j] = ++step;
      // cout << "Down: " << i << "\t" << j << "\t" <<  step << endl;
    }
    i--; // stay in same row.
    j--; // move back one column
    for(; j >= (margin); j--){
      arr[i][j] = ++step;
      // cout << "Left: " << i << "\t" << j << "\t" <<  step << endl;
   }
    j++; // stay in same column
    i--; // move up one row
    for(; i >= margin; i--){
      arr[i][j] = ++step;
      // cout << "Up: " << i << "\t" << j << "\t" <<  step << endl;
   }
    i++; // stay in same row;
    j++; //move forward one column
    margin--;
  }
  int sum = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i == j || (i+j == (N-1)))
        sum += arr[i][j];
    }
  }
  cout << "Sum: " << sum << endl;
}
