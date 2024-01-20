#include <bits/stdc++.h>

using namespace std;

string letters(int n){
  string common[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  string tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  if (n <= 19 && n != 10) // one to twenty
    return common[n]; 
  if (n < 100 && n % 10 == 0) // numbers ending in 0 and < 100
    return tens[(n/10)];
  if (n < 100) {
    int c = n % 10;
    int b = n / 10;
    return tens[b] + common[c];
  }
  if (n % 100 == 0){
    return common[n/100] + "hundred";
  }
  if (n > 100) {
    return common[n/100] + "hundredand" + letters(n%100);
  }
  return "None";
}

int main() {
  int i = 1;
  int N = 1000;
  string name = ""; 
  for(; i < N; i++) {
    name += letters(i);
  }
  cout << "Sum: " << name.length() + 11 <<endl; // one thousand is 11 characters long
  return 0;
}
