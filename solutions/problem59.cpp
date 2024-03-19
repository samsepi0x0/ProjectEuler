#include <bits/stdc++.h>

using namespace std;

int calcScore(vector<char> plaintext) {
  int score = 0;
  for(char x: plaintext) {
    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9') || x == ';' || x == ':' || x == ',' || x == '.' || x == '\'' || x == '?' || x == '-' || x == '!' || x == '(' || x == ')')
        score++;
  }
  return score;
}

int main() {
  ifstream file("0059_cipher.txt");
  string line;
  getline(file, line);
  
  vector<int> cipher;
  istringstream iss(line);
  string token;

  while (getline(iss, token, ','))
    cipher.push_back(stoi(token));
  
  for(char a = 'a'; a <= 'z'; a++){
    for(char b = 'a'; b <= 'z'; b++){
      for(char c = 'a'; c <= 'z'; c++) {
        char key[] = {a, b, c};
        
        vector<char> plaintext;
        for(int i = 0; i < cipher.size(); i++){
          plaintext.push_back(cipher[i] ^ key[i % 3]);
        }
        
        bool isValid = true;
        for(auto x: plaintext){
          isValid = (x >= '0' && x <= '9') || (x >= 'A' && x <= 'Z') || (x >='a' && x <= 'z') || (x == ' ' || x == '.' || x == ',' || x == '?' || x == '!' || x == ';' || x == '-' || x == '\'' || x == '(' || x == ')' || x == '+' || x == '\"' || x == '[' || x == ']' || x == ':' || x == '/');
          /*isValid |= (x >= 'a' && x <= 'z');
          isValid |= (x >= 'A' && x <= 'Z');
          isValid |= (x == ' ' || x == '.' || x == ',' || x == '?' || x == '!');
          isValid |= (x == ';' || x == '-' || x == '\'');
          isValid |= (x == '(' || x == ')');*/

          if (!isValid)
            break;
        }

        if(!isValid)
          continue;
        cout << "Key: " << a << b << c << endl;
        cout << "Plaintext: ";
        int asciiSum = 0;
        for(auto x: plaintext) {
          cout << x;
          asciiSum += int(x);
        }
        cout << endl << endl;
        cout << "ASCII Sum: " << asciiSum << endl;

        return 0;
      }
    }
  }

  return 0;
}
