#include <iostream>
using  namespace std ;

bool primo(int num, int divisor) {
    if (num <= 1) return false; 
    if (divisor == 1) return true; 
    if (num % divisor == 0) return false; 
    return primo(num, divisor - 1); 
}
int primo_menor(int n) {
    if (n <= 2) return -1; 
    if (primo(n - 1, (n - 1) / 2)) {
        return n - 1; 
    }
    return primo_menor(n - 1);
}


int main() {
    int n ; 
    cout << "Ingrese un numero positivo " << endl ;
    cin >> n ; 
    int resultado = primo_menor(n);

    if (resultado == -1) {
        cout << "No existe un numero primo menor que " << n << endl ;
    }
    else {
        cout << "El numero primo mas grande  menor que " << n << " es " << resultado << endl;
    }

    return 0 ;
}