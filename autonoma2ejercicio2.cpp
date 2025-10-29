#include <iostream>
using namespace std;


int main () {
    int opc; 
    float monto, total_compra;

    do
    {
        cout << "Bienvenido  al menu de opciones" << endl;
        cout << "Elija una opcion " << endl;
        cout << "1.- Pagar con tarjeta de credito " << endl;
        cout << "2.- Pagar con tarjeta de debito " << endl;
        cout << "3.- Pagar en efectivo " << endl;
        cout << "4.- Salir" << endl;
        cin >> opc;

        if (opc >= 1 && opc <= 4)
        {
             
            switch (opc)
            {
            
            // En cada caso se encarga de hacer el proceso //
            case 1:
                cout << "Ingrese el monto total de la compra $ " << endl;
                cin >> monto;
                total_compra = monto + (monto *0.05) ; 
                cout << "Comision de la compra $ " << total_compra << endl;
                break;

            case 2:
                cout << "Ingrese el monto total de la compra $ " << endl;
                cin >> monto;

                total_compra = monto;
                cout << "No aplica comision $ " << total_compra << endl;
                break;

            case 3:
                cout << "Ingrese el monto total de la compra $ " << endl;
                cin >> monto;
                total_compra = monto - (monto* 0.02);
                cout << "Descuento de comision $ " << total_compra << endl;
                break;

            case 4:
                cout << "Gracias por usar el sistema de pagos " << endl;
                break; 
            }

        } 

        else {
            cout << "Opcion no valida " << endl ;
        }

    }   while (opc != 4);

    return 0;
}



