#include <iostream>
#include <cmath>
using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

double termino_sen(double x, int n) {
    if (n == 0) return x; 
    return pow(-1, n) * pow(x, 2*n + 1) / factorial(2*n + 1);
}

double termino_cos(double x, int n) {
    if (n == 0) return 1; 
    return pow(-1, n) * pow(x, 2*n) / factorial(2*n);
}

double sen_taylor(double x, int n) {
    if (n == 0) return termino_sen(x, 0);
    return termino_sen(x, n) + sen_taylor(x, n - 1);
}

double cos_taylor(double x, int n) {
    if (n == 0) return termino_cos(x, 0);
    return termino_cos(x, n) + cos_taylor(x, n - 1);
}

int main() {
    double grados;
    cout << "Ingrese un angulo en grados : " ;
    cin >> grados;
    double radianes = grados * M_PI / 180;
    int n = 10;
    double sen = sen_taylor(radianes, n);
    double cos = cos_taylor(radianes, n);
    cout << " Sen(" << grados << ") = " << sen << endl;
    cout << " Cos(" << grados << ") = " << cos << endl;

    return 0;
}
