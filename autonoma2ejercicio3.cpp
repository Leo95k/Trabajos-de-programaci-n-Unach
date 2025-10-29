#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int opc, num1, num2;
    float a, b;
    char continuar ;

    do
    {
        cout << "Menu de operaciones matematicas " << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multi" << endl;
        cout << "4. Div" << endl;
        cout << "5. Potencia" << endl;
        cout << "6. Raiz cuadrada" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion" << endl;
        cin >> opc;

        //En cada caso hace cada operacion matematica//

        if (opc >= 1 && opc <= 7)
        {
            switch (opc)
            {
            case 1:
                cout << "Ingrese el pirmer numero" << endl;
                cin >> num1;
                cout << "Ingrese el segundo numero" << endl;
                cin >> num2;
                cout << "El resultado de la suma es  " << num1 + num2 << endl;
                break;
            case 2:
                cout << "Ingrese el pirmer numero" << endl;
                cin >> num1;
                cout << "Ingrese el segundo numero" << endl;
                cin >> num2;
                cout << "El resultado de la resta es  " << num1 - num2 << endl;
                break;
            case 3:
                cout << "Ingrese el pirmer numero" << endl;
                cin >> num1;
                cout << "Ingrese el segundo numero" << endl;
                cin >> num2;
                cout << "El resultado de la multiplicacion es  " << num1 * num2 << endl;
                break;
            case 4:
                cout << "Ingrese el pirmer numero" << endl;
                cin >> num1;
                cout << "Ingrese el segundo numero" << endl;
                cin >> num2;
                if ((num2 != 0))
                {
                    cout << "La division es " << num1 / num2 << endl;
                }
                else
                {
                    cout << "Error no se puede dividir para 0 " << endl;
                }
                break;

            case 5:
                cout << "Ingrese la base (a)" << endl;
                cin >> a;
                cout << "Ingrese el exponente (b)" << endl;
                cin >> b;

                if (a < 0)
                {
                    cout << "Error la base debe ser positiva " << endl;
                }
                else
                {
                    cout << "El resultado de la potencia es " << pow(a, b) << endl;
                }
                break;

            case 6:
                cout << "Ingrese un numero" << endl;
                cin >> num1;
                if ( num1 < 0 ) {
                    cout << "Error no se puede calcular la raiz " << endl ;
                }
                else {
                    cout << "El resultado de la raiz es  " << sqrt(num1) << endl ;
                    break;
                }

                case 7 :
                cout << "Saliendo del menu de operaciones matematicas " << endl ;
                break;

                default :
                cout << "Opcion no valida " << endl ;
            }
        }
        if (opc != 7 ) {
            cout << " ¿Quieres hacer otra operacion ?  s/n " << endl ;
            cin >> continuar ;
        }
        else {
            continuar = 'n';
        }

    } while ( continuar == 's' || continuar == 'S'); 

    cout << "Gracias por usar el menu de operaicones matematicas " << endl ;

    return 0;
}
