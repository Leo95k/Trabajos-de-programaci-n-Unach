#include <iostream>
using namespace std;

int main() {
    float precio, impuesto, descuento, precio_final;
    float categoria;

    cout << "Ingrese el precio ";
    cin >> precio;

    cout << "Ingrese una categoria (electronica, ropa, alimentos)";
    cin >> categoria;

    descuento = (precio > 1000) ? precio * 0.10 : 0;

    impuesto = (categoria == 1) ? precio * 0.20 :
               (categoria == 2) ? precio * 0.10 :
               (categoria == 3) ? precio * 0.05 : 0 ;


    precio_final = precio - descuento + impuesto;

    cout << "Precio $" << precio << endl;
    cout << "Descuento $" << descuento << endl;
    cout << "Cantidad de impuesto $" << impuesto << endl;
    cout << "Precio final $" << precio_final << endl;

    return 0;
}


