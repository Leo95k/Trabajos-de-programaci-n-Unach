#include <iostream>
using namespace std;

int main()
{
    const string correo = "Leo";
    string contrasena = "2025";
    string entrada_correo, entrada_contrasena, nueva_contrasena, confirmar_contrasena;
    int intentos = 0;
    const int max_intentos = 3;
    int opc;
    float saldo = 0.0;
    char continuar;

    // Centro de control//
    while (intentos < max_intentos)
    {
        cout << "Ingrese su nombre de usuario: ";
        cin >> entrada_correo;  
        cout << "Ingrese su contrasena: ";
        cin >> entrada_contrasena;
        intentos++;

        if (entrada_correo == correo && entrada_contrasena == contrasena)
        {
            cout << "Bienvenido a su gmail" << correo << endl;

            // Menú de opciones
            do
            {
                cout << "Menu de opciones:" << endl;
                cout << "1. Consultar saldo" << endl;
                cout << "2. Cambiar contrasena" << endl;
                cout << "3. Salir" << endl;
                cout << "Seleccione una opcion " << endl ;
                cin >> opc;

                switch (opc)
                {
                case 1:
                    cout << "Ingrese su saldo inicial" << endl ;
                    cin >> saldo;
                    cout << "Tu saldo es: " << saldo << endl;
                    break;

                case 2:
                    cout << "Ingrese nueva contrasena" << endl ;
                    cin >> nueva_contrasena;
                    cout << "Confirmar la nueva contrasena" << endl;
                    cin >> confirmar_contrasena;

                    if (nueva_contrasena == confirmar_contrasena)
                    {
                        contrasena = nueva_contrasena;
                        cout << "Contrasena cambiada exitosamente" << endl;
                    }
                    else
                    {
                        cout << "Error: Las contrasenas no coinciden. Intente de nuevo" << endl;
                    }
                    break;

                case 3:
                    cout << "Saliendo" << endl;
                    break;

                default:
                    cout << "Opcion invalida. Intente nuevamente" << endl;
                }

                cout << "Desea realizar otra operacion? (s/n)" << endl ;
                cin >> continuar;

            } while (continuar == 's' || continuar == 'S');

            return 0; // Salir del programca despues del menu de opciones//
        }
        else
        {
            cout << "Error: Usuario o contrasena incorrectos. Intentos " << intentos << " de " << max_intentos << "." << endl;
        }
    }

    // Si se agotan los intentos no puedes entrar //
    cout << "Acceso bloqueado." << endl;
    return 0;
}
