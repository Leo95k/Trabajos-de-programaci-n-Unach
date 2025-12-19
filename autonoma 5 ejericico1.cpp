#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Validar datos que seas positivos 
const int N = 7; 
int validar_enteros_positivos(string mensaje)
{
    int valor;
    do
    {
        cout << mensaje;
        cin >> valor;
        if (valor < 0)
            cout << "Valor invalido. Ingrese nuevamente." << endl;
    } while (valor < 0);
    return valor;
}

//Validar datos que sean reales positivos 

float validar_reales_positivos(string mensaje)
{
    float valor;
    do
    {
        cout << mensaje;
        cin >> valor;
        if (valor < 0)
            cout << "Valor invalido. Ingrese nuevamente." << endl;
    } while (valor < 0);
    return valor;
}

//En esta linea se trata para analizar la produccion de los dias que hizo la maquina 
void analisis_produccion(int produccion[])
{
    int total = 0, maximo_dia = 0, minimo_dia = 0;
    for (int i = 0; i < N; i++)
    {
        total += produccion[i];
        if (produccion[i] > produccion[maximo_dia])
            maximo_dia = i;
        if (produccion[i] < produccion[minimo_dia])
            minimo_dia = i;
    }
    float promedio = (float)total / N;

    cout << "Produccion ";
    cout << "Total de lo producido " << total << endl;
    cout << "Dia mayor de produccion " << maximo_dia + 1 << " (" << produccion[maximo_dia] << ")";
    cout << "Dia menor de produccion " << minimo_dia + 1 << " (" << produccion[minimo_dia] << ")";
    cout << "Promedio de produccion: " << promedio << endl;
}

// Aqui es para analizar las horas usadas en la maquina 

void analisis_horas(float horas[])
{
    float total = 0;
    int minimo_dia = 0;
    float limite;
    cout << "Ingrese limite de sobrecarga de horas " << endl;
    cin >> limite;

    for (int i = 0; i < N; i++)
    {
        total += horas[i];
        if (horas[i] < horas[minimo_dia])
            minimo_dia = i;
    }
    int promedio = total / N;

    cout << " Horas trabajadas " << promedio  << "h" << endl;
    cout << "Dias con sobrecarga " << limite << "h" << endl;
    for (int i = 0; i < N; i++)
    {
        if (horas[i] > limite)
            cout << (i + 1) << " " << endl;
    }
    cout << "Dia con menos horas trabajadas " << minimo_dia + 1 << " (" << horas[minimo_dia] << "h)" << endl;
}

//En esta funcion se encarga de analizar el consumo usado en el dia
void analisis_energia(float energia[])
{
    float total = 0;
    for (int i = 0; i < N; i++) {
        total += energia[i];
    }
    float promedio = total / N;
    int cercano = 0;
    for (int i = 1; i < N; i++)
    {
        if (fabs(energia[i] - promedio) < fabs(energia[cercano] - promedio))
            cercano = i;
    }
    cout << "Consumo Energia " << endl;
    cout << "Consumo total: " << total << " kWh\n" << endl;
    cout << "Promedio: " << promedio << " kWh\n" << endl;
    cout << "Dia mas cercano al promedio: " << cercano + 1 << " (" << energia[cercano] << ")" << endl;
}

// En esta funcion es para analizar la temperatura en la maquina industrial 
void analisis_temperatura(float temp[])
{
    int limite_temperatura = 100; // límite de seguridad
    cout << " Temperatura de las  maquinas ";
    for (int i = 0; i < N; i++)
    {
        if (temp[i] > limite_temperatura)
        {
            cout << "Alerta: Dia " << i + 1 << " sobrecalentamiento (" << temp[i] << " grados)" << endl;
        }
    }
}

int main()
{
    int produccion[N];
    float horas[N], energia[N], temperatura[N];
    

    cout << "Sistema de produccion industrial  " << endl;
    
    for (int i = 0; i < N; i++)
    {
        cout << "Dia " << i + 1 << endl;
        produccion[i] = validar_enteros_positivos("Unidades producidas " ) ; 
        horas[i] = validar_reales_positivos("Horas de operacion ") ;
        energia[i] = validar_reales_positivos("Consumo de energia (kWh) ") ;
        temperatura[i] = validar_reales_positivos("Temperatura de maquina ") ; 

    }
    // Este es un menu de opciones 
    int opc;
    do
    {
        cout << "Menu1 de opciones" << endl;
        cout << "1. Analizar Produccion" << endl;
        cout << "2. Analizar Horas de Operacion" << endl;
        cout << "3. Analizar Consumo de Energia" << endl;
        cout << "4. Analizar Temperatura de Maquinas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion " << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            analisis_produccion(produccion);
            break;
        case 2:
            analisis_horas(horas);
            break;
        case 3:
            analisis_energia(energia);
            break;
        case 4:
            analisis_temperatura(temperatura);
            break;
        case 0:
            cout << "Saliendo" << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opc != 0);

    return 0;
}

