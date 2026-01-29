#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits> 

using namespace std;

struct Libro {
    string nombre;
    string categoria;
    int disponibles;
    int prestados;
    vector<int> prestamosPorDia; 
};

vector<Libro> biblioteca;

// Utilidades
bool idValido(int id) {
    return id >= 0 && id < (int)biblioteca.size();
}

// Limpiar buffer de entrada
void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Funciones
void guardar_libro(string nombre, string categoria, int cantidad) {
    biblioteca.push_back({nombre, categoria, cantidad, 0, vector<int>(5, 0)});
}

void insertar_Libro(int pos, string nombre, string categoria, int cantidad) {
    if (pos < 0 || pos > (int)biblioteca.size()) {
        cout << "Posicion invalida." << endl;
        return;
    }
    biblioteca.insert(biblioteca.begin() + pos, {nombre, categoria, cantidad, 0, vector<int>(5, 0)});
}

void prestar_Libro(int id, int dia, int cantidad) {
    if (!idValido(id) || dia < 0 || dia >= 5 || cantidad <= 0) {
        cout << "Datos invalidos." << endl;
        return;
    }
    if (biblioteca[id].disponibles < cantidad) {
        cout << "Stock insuficiente." << endl;
        return;
    }

    biblioteca[id].disponibles -= cantidad;
    biblioteca[id].prestados += cantidad;
    biblioteca[id].prestamosPorDia[dia] += cantidad;
    cout << "Prestamo realizado." << endl;
}

void mostrar_Disponibles() {
    cout << "\n--- Libros Disponibles ---" << endl;
    for (int i = 0; i < (int)biblioteca.size(); i++) {
        if (biblioteca[i].disponibles > 0) {
            cout << i << ". " << biblioteca[i].nombre << " [" << biblioteca[i].categoria << "] - Stock: " << biblioteca[i].disponibles << endl;
        }
    }
}

void modificar_Libro(int id, string nombre, string categoria, int stock) {
    if (!idValido(id)) {
        cout << "ID invalido." << endl;
        return;
    }
    biblioteca[id].nombre = nombre;
    biblioteca[id].categoria = categoria;
    biblioteca[id].disponibles = stock;
    cout << "Libro modificado." << endl;
}

void eliminar_Libro(int id) {
    if (!idValido(id)) {
        cout << "ID invalido." << endl;
        return;
    }
    biblioteca.erase(biblioteca.begin() + id);
    cout << "Libro eliminado." << endl;
}

void buscar_Libro(string criterio) {
    cout << "Resultados:" << endl;
    for (int i = 0; i < (int)biblioteca.size(); i++) {
        if (biblioteca[i].nombre == criterio || biblioteca[i].categoria == criterio) {
            cout << i << ". " << biblioteca[i].nombre << " - " << biblioteca[i].categoria << endl;
        }
    }
}

void ordenar_PorNombre() {
    sort(biblioteca.begin(), biblioteca.end(), [](const Libro &a, const Libro &b) {
        return a.nombre < b.nombre;
    });
    cout << "Libros ordenados por nombre." << endl;
}

int total_Prestamos(int id) {
    if (!idValido(id)) return 0;
    return accumulate(biblioteca[id].prestamosPorDia.begin(), biblioteca[id].prestamosPorDia.end(), 0);
}

void estadisticas() {
    if (biblioteca.empty()) {
        cout << "No hay libros." << endl;
        return;
    }

    int maxLibro = 0;
    vector<int> dias(5, 0);

    for (int i = 0; i < (int)biblioteca.size(); i++) {
        if (total_Prestamos(i) > total_Prestamos(maxLibro))
            maxLibro = i;

        for (int d = 0; d < 5; d++)
            dias[d] += biblioteca[i].prestamosPorDia[d];
    }

    int diaActivo = max_element(dias.begin(), dias.end()) - dias.begin();
    string nombresDias[5] = {"Lunes","Martes","Miercoles","Jueves","Viernes"};

    cout << "Libro mas prestado: " << biblioteca[maxLibro].nombre << endl;
    cout << "Dia mas activo: " << nombresDias[diaActivo] << endl;
}

void reporte_Inventario() {
    for (Libro &l : biblioteca) {
        cout << l.nombre << ": ";
        if (l.disponibles == 0) cout << "AGOTADO";
        else if (l.prestados > 10) cout << "ALTA ROTACION";
        else cout << "BAJA ROTACION";
        cout << " (Disponibles: " << l.disponibles << ")" << endl;
    }
}

// ------- Menu --------
void menu() {
    int opc;
    string nombre, categoria, criterio;
    int id, cantidad, dia, pos;

    do {
        cout << "--- Menu Biblioteca Escolar ---" << endl;
        cout << "1. Guardar libro" << endl;
        cout << "2. Insertar libro" << endl;
        cout << "3. Prestar libro" << endl;
        cout << "4. Mostrar disponibles" << endl;
        cout << "5. Modificar libro" << endl;
        cout << "6. Eliminar libro" << endl;
        cout << "7. Buscar libro" << endl;
        cout << "8. Ordenar libros" << endl;
        cout << "9. Estadisticas" << endl;
        cout << "10. Reporte inventario" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        
        if (!(cin >> opc)) { 
            cout << "Por favor, ingrese un numero valido." << endl;
            cin.clear();
            limpiarBuffer();
            continue;
        }

        switch (opc) {
            case 1:
                limpiarBuffer();
                cout << "Nombre: "; getline(cin, nombre);
                cout << "Categoria: "; getline(cin, categoria);
                cout << "Cantidad: "; cin >> cantidad;
                guardar_libro(nombre, categoria, cantidad);
                break;
            case 2:
                cout << "Posicion: "; cin >> pos;
                limpiarBuffer();
                cout << "Nombre: "; getline(cin, nombre);
                cout << "Categoria: "; getline(cin, categoria);
                cout << "Cantidad: "; cin >> cantidad;
                insertar_Libro(pos, nombre, categoria, cantidad);
                break;
            case 3:
                cout << "ID del libro: "; cin >> id;
                cout << "Dia (0-Lunes a 4-Viernes): "; cin >> dia;
                cout << "Cantidad: "; cin >> cantidad;
                prestar_Libro(id, dia, cantidad);
                break;
            case 4:
                mostrar_Disponibles();
                break;
            case 5:
                cout << "ID a modificar: "; cin >> id;
                limpiarBuffer();
                cout << "Nuevo Nombre: "; getline(cin, nombre);
                cout << "Nueva Categoria: "; getline(cin, categoria);
                cout << "Nuevo Stock: "; cin >> cantidad;
                modificar_Libro(id, nombre, categoria, cantidad);
                break;
            case 6:
                cout << "ID a eliminar: "; cin >> id;
                eliminar_Libro(id);
                break;
            case 7:
                limpiarBuffer();
                cout << "Nombre o Categoria a buscar: "; getline(cin, criterio);
                buscar_Libro(criterio);
                break;
            case 8:
                ordenar_PorNombre();
                break;
            case 9:
                estadisticas();
                break;
            case 10:
                reporte_Inventario();
                break;
        }
    } while (opc != 0);
}

int main() {
    menu();
    return 0;
}
