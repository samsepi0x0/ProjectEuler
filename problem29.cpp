#include <bits/stdc++.h>
using namespace std;

class BigInt {
  string digits;
 public:
  BigInt(unsigned long long n = 0);
  BigInt(string &);
  BigInt(BigInt &);
  friend bool Null(const BigInt &);
  friend int Length(const BigInt &);
  friend string getDigits(const BigInt &);

  friend BigInt &operator+=(BigInt &, const BigInt &);
  friend BigInt operator+(const BigInt &, const BigInt &);
  friend BigInt &operator*=(BigInt &, const BigInt &);
  friend BigInt operator*(const BigInt &, const BigInt &);
  friend ostream &operator<<(ostream &,const BigInt &);
  friend istream &operator>>(istream &, BigInt &);
};
  BigInt::BigInt(string & s){
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
  }
  BigInt::BigInt(unsigned long long nr){
    do{
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
  }
  BigInt::BigInt(BigInt & a){
    digits = a.digits;
  }
  bool Null(const BigInt& a){
    if(a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
  }
  int Length(const BigInt & a){
    return a.digits.size();
  }
  string getDigits(const BigInt & a){
    return a.digits;
  }
  BigInt &operator+=(BigInt &a,const BigInt& b){
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if(m > n)
        a.digits.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if(t)
        a.digits.push_back(t);
    return a;
  }
  BigInt operator+(const BigInt &a, const BigInt &b){
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
  }
  BigInt &operator*=(BigInt &a, const BigInt &b){
    if(Null(a) || Null(b)){
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            v[i + j] += (a.digits[i] ) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i] ;
    }
    for (int i = n - 1; i >= 1 && !v[i];i--)
            a.digits.pop_back();
    return a;
  }
  BigInt operator*(const BigInt&a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
  }
  
  ostream &operator<<(ostream &out,const BigInt &a){
    for (int i = a.digits.size() - 1; i >= 0;i--)
        cout << (short)a.digits[i];
    return cout;
  }

int main() {
  int N = 100;
  set<string> nums;

  for(int a = 2; a <= N; a++) {
    for(int b = 2; b <= N; b++) {
      BigInt A(a);
      for(int i = 1; i < b; i++){
        A *= a;
      }
      nums.insert(getDigits(A));
      //cout << a << "\t" << b << "\t" << A << "\n";
    }
  }
  cout << "Distinct terms: " << nums.size() << endl; 
  return 0;
}
