#include <iostream>
using namespace std;

// Función para calcular el promedio de notas enteras

int calcularPromedio(int suma, int cantidad)
{
    return (suma) / cantidad;
}

// Función para calcular el promedio de notas flotantes

float calcularPromedio(float suma, int cantidad)
{
    return suma / cantidad;
}

int main()
{
    int opc;
    int sumaEnteros = 0, cantidadEnteros = 0;
    float sumaFlotantes = 0.0;
    int cantidadFlotantes = 0;

    do
    {
        cout << "Ingrese el tipo de nota a ingresar (1- Entero, 2- Flotante, 0- Salir): ";
        cin >> opc;

        if (opc == 1)
        {
            int notaEntera;
            cout << "Ingrese la nota entera" << endl;
            cin >> notaEntera;
            sumaEnteros += notaEntera;
            cantidadEnteros++;
        }
        else if (opc == 2)
        {
            float notaFlotante;
            cout << "Ingrese la nota flotante" << endl;
            cin >> notaFlotante;
            sumaFlotantes += notaFlotante;
            cantidadFlotantes++;
        }
    } while (opc != 0);

    if (cantidadEnteros > 0)
    {
        int promedioEnteros = calcularPromedio(sumaEnteros, cantidadEnteros);
        cout << "El promedio de las notas enteras es " << promedioEnteros << endl;
    }

    if (cantidadFlotantes > 0)
    {
        float promedioFlotantes = calcularPromedio(sumaFlotantes, cantidadFlotantes);
        cout << "El promedio de las notas flotantes es " << promedioFlotantes << endl;
    }

    return 0;
}
