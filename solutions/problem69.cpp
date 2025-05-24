#include <bits/stdc++.h>
using namespace std;

long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    long long maxn = -1;
    double maxratio = 0;

    for (long long n = 1; n <= 1000000; n++) {
        long long phi_n = phi(n);
        double ratio = (n * 1.0) / (phi_n * 1.0);

        if (ratio > maxratio) {
            maxratio = ratio;
            maxn = n;
        }
    } 
    cout << maxn << "\t" << maxratio << endl;
}