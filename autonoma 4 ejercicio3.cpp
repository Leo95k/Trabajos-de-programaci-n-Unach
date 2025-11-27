#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void imprimir_rango(int n, int minimo, int maximo)
{
    int f = fibonacci(n);

    if (f > maximo)
        return;

    if (f >= minimo && f <= maximo)
    {
        cout << f << " ";
    }
    imprimir_rango(n + 1, minimo, maximo);
}

int contar_rango(int n, int minimo, int maximo)
{
    int f = fibonacci(n);
    if (f > maximo)
        return 0;
    if (f >= minimo && f <= maximo)
        return 1 + contar_rango(n + 1, minimo, maximo);
        
    return contar_rango(n + 1, minimo, maximo);
}

int main()
{
    int minimo = 1000, maximo = 2000;

    cout << "Numeros de Fibonacci en el rango [" << minimo << ", " << maximo << "]: ";
    imprimir_rango(0, minimo, maximo);
    cout << " Cantidad " << contar_rango(0, minimo, maximo) << endl;
}
