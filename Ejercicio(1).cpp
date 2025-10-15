#include <iostream>
using  namespace std ;
int main () {
    int experiencia ;
    string nivel_de_educacion , resultados ; 

    cout << "Ingrese los anios de experience" << endl ;   
    cin >> experiencia ; 
    cout << "Ingrese su niveles de eduacion primaria, secundario, universitario " << endl ; 
    cin >>  nivel_de_educacion; 

    resultados=(experiencia >= 5 && nivel_de_educacion == "universitario") ? "Aprobado" :
    ((experiencia >= 3 || experiencia >= 5 )  && nivel_de_educacion == "secundario") ? "Aprobado" :
    "No aprobado " ;
    cout << "El resultado de su oferta es " << resultados << endl ;

}
