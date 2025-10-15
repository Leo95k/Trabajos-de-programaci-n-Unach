#include <iostream>
using namespace std;

int main() {
    const float numero_fijo = 11;
    const float numero_intentos = 5;
    float numero;

    for (int intento = 1; intento <= numero_intentos; intento++) {
        cout << "Numeros de intento" << intento << ": Ingresa un numero al azar ";
        cin >> numero;

        if (numero == numero_fijo) {
            cout << "¡Correcto! Lo lograste en " << intento << " intento(s)." << endl;
            break;
        } else {
            cout << (numero > numero_fijo ? "Demasiado alto" : "Demasiado bajo") << endl;
        }

        if (intento == numero_intentos) {
            cout << "Lo siento, no tienes intentos mas. El numero era " << numero_fijo << "." << endl;
        }
    }

    return 0;
}

