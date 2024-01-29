#include <bits/stdc++.h>

using namespace std;

bool isPandigital(string s) {
  if (s.length() != 10)
    return false;
  sort(s.begin(), s.end());
  return s == "0123456789";
}

bool check(string temp) {
  vector<int> d;
  d.push_back(-1);
  for(int i = 0; i < temp.length(); i++)
    d.push_back(temp[i] - 48);

  if (d[4] % 2 != 0)
    return false;
  
  if ((d[3] + d[4] + d[5]) % 3 != 0)
    return false;

  if ((d[5]*100 + d[6]*10 + d[7]) % 7 != 0)
    return false;

  if ((d[6]*100 + d[7]*10 + d[8]) % 11 != 0)
    return false;

  if ((d[7]*100 + d[8]*10 + d[9]) % 13 != 0)
    return false;

  if ((d[8]*100 + d[9]*10 + d[10]) % 17 != 0)
    return false;

  cout << temp << endl;
  return true;
}

int main() {
  vector<int> arr;
  for(int i = 0; i < 10; i++)
    arr.push_back(i);
  long long sum = 0;
  do {
    if (arr[5] != 5)
      continue;
    
    string temp;
    for(auto x: arr)
      temp += to_string(x);
    if (!isPandigital(temp))
      continue;
    if (check(temp)) {
      long long value = 0;
      for (auto x: arr) {
        value = value * 10 + x;
      }
      sum += value;
    }
  } while(next_permutation(arr.begin(), arr.end()));
  cout << "Sum: " << sum << endl;
  return 0;
}
