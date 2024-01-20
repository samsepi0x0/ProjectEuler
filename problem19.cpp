#include <bits/stdc++.h>

using namespace std;

int day(int year, int K, int J) {
  int months[] = {13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int Q = 1;

  int sundays = 0;
  
  for(int i = 0; i < 12; i++){
    int m = months[i];
    if (m == 3){ // march of year
      if (year == 1900 || year == 2000) {
        J += 1;
        K = 0;
      } else { // new year starts in march
        K += 1;
      }
    }

    int h_p = (Q + floor( ( (13*(m+1))/5 )) + K + floor(K/4) + floor(J/4) - (2*J) );
    int h = -1;
    if (h_p < 0) {
      h = ((h_p % 7) + 7) % 7;
    } else {
      h = (h_p % 7);
    }
    if (h == 1)
      sundays += 1;
  }
  return sundays;
}

int main() {
  int year = 1900;
  int Q = 1;

  int sundays = 0;

  // year = 1900 - not asked in the question
  // sundays += day(year, 99, 18);
  
  // year 1901 to 1999
  year += 1;
  for(int i = 1; i <= 99; i++){
    sundays += day(year, i-1, 19);
    year += 1;
  }

  // year 2000
  sundays += day(2000, 99, 19);

  cout << "Sundays: " << sundays << endl;
  return 0;
}
