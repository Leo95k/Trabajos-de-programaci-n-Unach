#include <iostream>
using namespace std;
#include <cmath>

void sumar(int num1, int num2)
{
    cout << "La suma es : " << num1 + num2 << endl;
}

void restar(int num1, int num2)
{
    cout << "La resta es : " << num1 - num2 << endl;
}

void multi(int num1, int num2)
{
    cout << "La multiplicacion  es : " << num1 * num2 << endl;
}

void divi(int num1, int num2)
{
    if (num2 != 0)
    {
        cout << "Resultado: " << num1 / num2 << endl;
    }
    else
    {
        cout << "Error: Division por cero no permitida." << endl;
    }
}

void menu()
{
    int opc;
    float num1, num2;
    do
    {
        cout << "Menu de Operaciones" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Salir del programa" << endl ;
        cout << "Escoga una opcion" << endl;
        cin >> opc;

        if (opc >= 1 && opc <= 4)
        {
            cout << "Ingrese el primer numero: ";
            cin >> num1;
            cout << "Ingrese el segundo numero: ";
            cin >> num2;
        }

        switch (opc)
        {
        case 1:
            sumar(num1, num2);
            break;
        case 2:
            restar(num1, num2);
            break;
        case 3:
            multi(num1, num2);
            break;
        case 4:
            divi(num1, num2);
            break;
        case 5:
            cout << "Gracias por usar el programa" << endl;
            break;
            default : 
            cout << "Opcion no valida " << endl ;
        }

    }  while (opc != 5) ;

   
}

int main()
{
    menu();
    return 0;
}






