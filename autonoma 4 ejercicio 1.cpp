#include <iostream>
#include <string>
using namespace std;

void permutar(string &cadena , int inicio, int fin) {
    if (inicio == fin) {
        cout << cadena << endl; 
    } else {
        for (int i = inicio; i <= fin; i++) {

            swap(cadena[inicio], cadena[i]);
            permutar(cadena, inicio + 1, fin);
            swap(cadena[inicio], cadena[i]);
        }
    }
}

int main() {
    string entrada;
    cout << "Ingrese la cadena " << endl;
    cin >> entrada;

    cout << "Permutaciones posibles" << endl;
    permutar(entrada, 0, entrada.size() - 1);

    return 0;
}
