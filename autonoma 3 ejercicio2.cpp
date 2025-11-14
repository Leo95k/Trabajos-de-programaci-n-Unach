#include <iostream>
using namespace std;

float cantidad_monedas(int cantidad , int denominacion) {
    float numMonedas = cantidad / denominacion ;
    cantidad %= denominacion ;
    return numMonedas ;
}

float convertirAdenominaciones( int cantidad_centavos) {
    float denominaciones = {100, 50, 25, 5, 1 } ; // centavos
    int resultados ;
    for (int denom : denominaciones) {
        resultados.push_back(cantidad_monedas(cantidad_centavos , deno)) ;
    }
    return resultados ;
}

int main() {
    double cantidad_dolares ;
    int monedas ;
    cout << "Ingrese la cantidad en dolares $ " << endl ; 
    cin >> cantidad_dolares ;
    int cantidad_centavos = (cantidad_dolares * 100 + 0.50) ;

    int monedas = convertirAdenominaciones(cantidad_centavos) ;

    return 0 ;
}
