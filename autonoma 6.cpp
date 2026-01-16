#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace std;

//Funcion de validacion 
int leer_entero(string mensaje, int minimo) {
    int k;
    do {
        cout << mensaje;
        cin >> k;
        if (cin.fail() || k < minimo) {
            cin.clear();
            cin.ignore(1000);
            cout << "Valor invalido. Intente nuevamente." << endl;
        }
    } while (k < minimo);
    return k;
}

double leer_decimales(string mensaje, double minimo) {
    double k;
    do {
        cout << mensaje;
        cin >> k;
        if (cin.fail() || k < minimo) {
            cin.clear();
            cin.ignore(1000);
            cout << "Intente nuevamente" << endl;
        }
    } while (k < minimo);
    return k;
}

// Ingreso de datos 
void ingrese_datos(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int n = leer_entero("Cuantos dias desea registrar? ", 1);

    for (int i = 0; i < n; i++) {
        cout << "Dia " << i << endl;
        pasos.push_back(leer_entero("Pasos del dia: ", 0));
        minutos.push_back(leer_entero("Minutos de actividad: ", 0));
        calorias.push_back(leer_decimales("Calorias quemadas: ", 0));
    }
}

// Mostrar los datos
void mostrar_datos(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    cout << "Dia\tPasos\tMinutos\tCalorias" << endl;
    for (int i = 0; i < pasos.size(); i++) {
        cout << i << "\t" << pasos[i] << "\t" << minutos[i] << "\t" << calorias[i] << endl;
    }
}

// Funcion para insertar datos
void insetrar_datos(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int posicion = leer_entero("Posicion a insertar: ", 0);

    pasos.insert(pasos.begin() + posicion, leer_entero("Pasos: ", 0));
    minutos.insert(minutos.begin() + posicion, leer_entero("Minutos: ", 0));
    calorias.insert(calorias.begin() + posicion, leer_decimales("Calorias: ", 0));
}

// Funcion de modificar los datos
void modificar(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int posicion = leer_entero("Dia a modificar: ", 0);

    pasos[posicion] = leer_entero("Nuevo pasos: ", 0);
    minutos[posicion] = leer_entero("Nuevo minutos: ", 0);
    calorias[posicion] = leer_decimales("Nueva calorias: ", 0);
}

// Funcion buscar datos
void buscar(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int valor = leer_entero("Ingrese pasos a buscar: ", 0);

    for (int i = 0; i < pasos.size(); i++) {
        if (pasos[i] == valor) {
            cout << "Dia " << i << ": " << pasos[i] << " pasos, "
                 << minutos[i] << " minutos, "
                 << calorias[i] << " calorias" << endl;
        }
    }
}

// Funcion para ordenar los datos
void ordenamiento(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias, bool asc) {
    for (int i = 0; i < pasos.size() - 1; i++) {
        for (int j = i + 1; j < pasos.size(); j++) {
            if ((asc && pasos[i] > pasos[j]) || (!asc && pasos[i] < pasos[j])) {
                swap(pasos[i], pasos[j]);
                swap(minutos[i], minutos[j]);
                swap(calorias[i], calorias[j]);
            }
        }
    }
}

// Funcion de eliminar datos
void eliminacion(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    int posiscion = leer_entero("Posicion a eliminar: ", 0);

    pasos.erase(pasos.begin() + posiscion);
    minutos.erase(minutos.begin() + posiscion);
    calorias.erase(calorias.begin() + posiscion);
}

// Funcion estadistica 
double media(vector<double> v) {
    double s = 0;
    for (double k : v) s += k;
    return s / v.size();
}

double mediana(vector<double> v) {
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 0)
        return (v[n/2 - 1] + v[n/2]) / 2;
    else
        return v[n/2];
}

double moda(vector<double> v) {
    map<double, int> f;
    for (double k : v) f[k]++;
    int maximo = 0;
    double moda = v[0];
    for (auto p : f) {
        if (p.second > maximo) {
            maximo = p.second;
            moda = p.first;
        }
    }
    return moda;
}

// Funcion de resultados
void mostrar_estadisticas(vector<int>& pasos, vector<int>& minutos, vector<double>& calorias) {
    vector<double> p(pasos.begin(), pasos.end());
    vector<double> m(minutos.begin(), minutos.end());

    cout << "Pasos - Media: " << media(p) << " Mediana: " << mediana(p) << " Moda: " << moda(p) << endl;
    cout << "Minutos - Media: " << media(m) << " Mediana: " << mediana(m) << " Moda: " << moda(m) << endl;
    cout << "Calorias - Media: " << media(calorias) << " Mediana: " << mediana(calorias) << " Moda: " << moda(calorias) << endl;

    cout << "Analisis adicional:" << endl;
    cout << "Promedio de pasos por minuto: " << media(p) / media(m) << endl;
    cout << "Promedio de calorias por minuto: " << media(calorias) / media(m) << endl;
}

// Funcion principal 
int main() {
    vector<int> pasos, minutos;
    vector<double> calorias;

    int opc;
    do {
        cout << "Sistema de ejercicios" << endl;
        cout << " 1.Ingresar datos" << endl;
        cout << " 2.Mostrar datos" << endl;
        cout << " 3.Insertar datos" << endl;
        cout << " 4.Modificar datos" << endl;
        cout << " 5.Buscar datos" << endl;
        cout << " 6.Ordenar ascendente" << endl;
        cout << " 7.Ordenar descendente" << endl;
        cout << " 8.Eliminar datos" << endl;
        cout << " 9.Estadisticas de los datos" << endl;
        cout << " 0.Salir" << endl;     

        opc = leer_entero("Opcion: ", 0);

        switch (opc) {
            case 1: ingrese_datos(pasos, minutos, calorias); break;
            case 2: mostrar_estadisticas(pasos, minutos, calorias); break;
            case 3: ingrese_datos(pasos, minutos, calorias); break;
            case 4: modificar(pasos, minutos, calorias); break;
            case 5: buscar(pasos, minutos, calorias); break;
            case 6: ordenamiento(pasos, minutos, calorias, true); break;
            case 7: ordenamiento(pasos, minutos, calorias, false); break;
            case 8: eliminacion(pasos, minutos, calorias); break;
            case 9: mostrar_estadisticas(pasos, minutos, calorias); break;
        }

    } while (opc != 0);

    return 0;
}
