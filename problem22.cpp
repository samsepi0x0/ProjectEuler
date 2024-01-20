#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ifstream file("0022_names.txt");
  string line;
  getline(file, line);
  file.close();

  vector<string> tokens;
  stringstream check(line);

  string immediate;
  while(getline(check, immediate, ',')){
    tokens.push_back(immediate);
  }
  
  sort(tokens.begin(), tokens.end());

  ll sum = 0;
  for(int i = 0; i < tokens.size(); i++) {
    string temp = tokens[i];
    int s = 0;
    for(int j = 1; j < temp.length() - 1; j++) {
      int t = ((int)(temp[j])) - 64;
      s += t;
    }
    ll r = s*(i+1);
    sum += r;
  }

  cout << "Sum: " << sum << endl;
  return 0;
}
