#include <iostream>
using  namespace std ;

int main () { 
    float grados_celsius, grados_fahrenheit, temperatura_umbral; 
    bool mayor_umbral , multiplo_5 ; 
    string clase_temperatura ; 

    cout << "Ingrese la temperatura " << endl ; 
    cin >> grados_celsius ; 
    cout << "Ingrese la temperatura umbral " << endl ; 
    cin >> temperatura_umbral ;

    if (grados_celsius > 100 || grados_celsius < -100 ) {

        cout << "La temperatura no es valida" << endl ; 
        return 0 ;
    }
    clase_temperatura= (grados_celsius < 0) ? "Muy frio" :
    (grados_celsius >= 0 && grados_celsius <= 15 )? "Fria" :
    (grados_celsius >= 15 && grados_celsius <= 30) ? "Templada" :
    "Caliente" ;

    grados_fahrenheit = grados_celsius * 9 / 5 + 32 ;

    mayor_umbral=  temperatura_umbral > grados_celsius;
    
    multiplo_5 = static_cast<int> (grados_celsius) % 5 == 0 ; 

    cout << "El resultado es " << grados_fahrenheit << endl ; 
    cout << "El resultado es " << clase_temperatura << endl ; 
    cout << "Es mayor a umbral  " << (mayor_umbral ? "Sí" : "No") << endl ; 
    cout << "Es multiplo de 5 " << (multiplo_5 ? "Sí " : "No") << endl ; 

    return 0 ; 
}