#include <iostream>
#include <cmath>
using namespace std;

// Función para calcular el discriminante

double calcularDiscriminante(float a, float b, float c)
{
    return b * b - 4 * a * c ;
}

// Función para redondear a dos decimales

float redondear(double valor)
{
    return (valor * 100 + 0.5) / 100 ;
}

//Funcio para resolver la ecuacion segun el discriminante

void resolverEcuacion(double &a, double &b, double &c)
{
    double D = calcularDiscriminante(a, b, c);

    if (D > 0)
    {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Dos soluciones reales y distintas" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (D == 0)
    {
        double x = -b / (2 * a);
        cout << "Una solucion real doble" << endl;
        cout << "x = " << x << endl;
    }
    else
    {
        double parteReal = -b / (2 * a);
        double parteImaginaria = sqrt(-D) / (2 * a);
        cout << "Dos soluciones complejas" << endl;
        cout << "x1 = " << parteReal << " = + " << parteImaginaria << " i " << endl;
        cout << "x2 = " << parteReal << " = - " << parteImaginaria << " i " << endl;
    }
}

int main()
{
    double a, b, c;
    cout << "Ingrese los coeficientes a, b y c" << endl;
    cin >> a >> b >> c;

    if (a == 0)
    {
        cout << "No es una ecuacion cuadratica" << endl;
    }
    else
    {
        resolverEcuacion(a, b, c);
    }

    return 0;
}
