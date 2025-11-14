#include <iostream>
using namespace std;

// Funciones para cada parte del número

void unidades(int n)
{
    if (n == 1)
    {
        cout << " uno " << endl;
    }
    else if (n == 2)
    {
        cout << " dos " << endl;
    }
    else if (n == 3)
    {
        cout << " tres " << endl;
    }
    else if (n == 4)
    {
        cout << " cuatro " << endl;
    }
    else if (n == 5)
    {
        cout << " cinco " << endl;
    }
    else if (n == 6)
    {
        cout << " seis " << endl;
    }
    else if (n == 7)
    {
        cout << " siete " << endl;
    }
    else if (n == 8)
    {
        cout << " ocho " << endl;
    }
    else if (n == 9)
    {
        cout << " nueve " << endl;
    }
}

void especiales(int n)
{
    if (n == 10)
    {
        cout << " diez " << endl;
    }
    else if (n == 11)
    {
        cout << " once " << endl;
    }
    else if (n == 12)
    {
        cout << " doce " << endl;
    }
    else if (n == 13)
    {
        cout << " trece " << endl;
    }
    else if (n == 14)
    {
        cout << " catorce " << endl;
    }
    else if (n == 15)
    {
        cout << " quince " << endl;
    }
    else if (n >= 16 && n <= 19)
    {
        cout << " dieci " << endl;
        unidades(n - 10);
    }
}

void decenas(int n)
{
    if (n >= 10 && n <= 19)
    {
        especiales(n);
    }
    else if (n >= 20 && n <= 29)
    {
        if (n == 20)
            cout << " veinte " << endl;
        else
        {
            cout << " veinti " << endl;
            unidades(n - 20);
        }
    }
    else if (n >= 30 && n <= 99)
    {
        int d = n / 10;
        int u = n % 10;
        if (d == 3)
        {
            cout << "treinta" << endl;
        }
        else if (d == 4)
        {
            cout << " cuarenta " << endl;
        }
        else if (d == 5)
        {
            cout << " cincuenta " << endl;
        }
        else if (d == 6)
        {
            cout << " sesenta " << endl;
        }
        else if (d == 7)
        {
            cout << " setenta " << endl;
        }
        else if (d == 8)
        {
            cout << " ochenta " << endl;
        }
        else if (d == 9)
        {
            cout << " noventa " << endl;
        }
        if (u != 0)
        {
            cout << " y ";
            unidades(u);
        }
    }
    else if (n < 10)
    {
        unidades(n);
    }
}

void centenas(int n)
{
    int c = n / 100;
    int resto = n % 100;

    if (n == 100)
    {
        cout << " cien " << endl;
        return;
    }

    if (c == 1) {
        cout << " ciento " << endl;
    }
    else if (c == 2) {
        cout << " doscientos " << endl;
    }
    else if (c == 3) {
        cout << " trescientos " << endl;
    }
    else if (c == 4) {
        cout << " cuatrocientos " << endl;
    }
    else if (c == 5) {
        cout << " quinientos " << endl;
    }
    else if (c == 6) {
        cout << " seiscientos " << endl;
    }
    else if (c == 7) {
        cout << " setecientos " << endl;
    }
    else if (c == 8) {
        cout << " ochocientos " << endl;
    }
    else if (c == 9) {
       cout << " novecientos " << endl;
    }
    if (resto != 0)
    {
        cout << " ";
        decenas(resto);
    }
}

int main()
{
    int numero;
    cout << " Ingresa un numero entre 1 y 999 " << endl;
    cin >> numero;

    if (numero < 1 || numero > 999)
    {
        cout << " Numero fuera de rango " << endl;
    }
    else if (numero < 100)
    {
        decenas(numero);
    }
    else
    {
        centenas(numero);
    }

    return 0;
}