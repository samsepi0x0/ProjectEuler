#include <bits/stdc++.h>  
  
using namespace std;  
  
class BigInt{  
public:  
    string num;  
  
    BigInt(unsigned long long n = 0);  
    friend bool Null(const BigInt &);  
    BigInt &operator=(const BigInt &);  
    friend BigInt &operator*=(BigInt &, const BigInt &);  
    friend ostream &operator<<(ostream &,const BigInt &);  
    friend BigInt multiply(int n);  
};  
  
BigInt::BigInt(unsigned long long nr){  
    do{  
        num.push_back(nr % 10);  
        nr /= 10;  
    } while (nr);  
}  
  
  
bool Null(const BigInt& a){  
    if(a.num.size() == 1 && a.num[0] == 0)  
        return true;  
    return false;  
}  
  
BigInt &BigInt::operator=(const BigInt &a){  
    num = a.num;  
    return *this;  
}  
  
BigInt &operator*=(BigInt &a, const BigInt &b)  
{  
    if(Null(a) || Null(b)){  
        a = BigInt();  
        return a;  
    }  
    int n = a.num.size(), m = b.num.size();  
    vector<int> v(n + m, 0);  
    for (int i = 0; i < n;i++)  
        for (int j = 0; j < m;j++){  
            v[i + j] += (a.num[i] ) * (b.num[j]);  
        }  
    n += m;  
    a.num.resize(v.size());  
    for (int s, i = 0, t = 0; i < n; i++)  
    {  
        s = t + v[i];  
        v[i] = s % 10;  
        t = s / 10;  
        a.num[i] = v[i] ;  
    }  
    for (int i = n - 1; i >= 1 && !v[i];i--)  
            a.num.pop_back();  
    return a;  
}  
  
BigInt multiply(int n){  
    BigInt f(1);  
    for (int i = 1; i <= n;i++)  
        f *= 2;  
    return f;  
}  
  
ostream &operator<<(ostream &out,const BigInt &a){  
    int sum = 0;
    for (int i = a.num.size() - 1; i >= 0;i--){
        sum += (short)a.num[i];  
    }
    cout << sum;
    return cout;  
}  

int main() {
  int N = 1000;
  BigInt res = multiply(N);
  cout << "2^" << N << ": " << res << endl; 
}

