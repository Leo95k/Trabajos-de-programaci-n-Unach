#include <iostream>
using namespace std;

int main() {
    int  votos , candidatoA=0 , candidatoB=0 , candidatoC=0 ;


    
    do { 
        cout << "Bienvenidos al menu de opciones" << endl ;
        cout << "Elija una opcion" << endl;
        cout << "1 - Candidato A" << endl ; 
        cout << "2 - Candidato B" << endl ;
        cout << "3 - Candidato C" << endl ;
        cout << "0 - Terminar" << endl;
        cout << "Votos ";
        cin >> votos;
         
        // En este menu es donde se realizara el proceso //
        switch (votos) 
        {
            
            case 1:
                candidatoA++;
                break;
            case 2:
                candidatoB++;
                break;
            case 3:
                candidatoC++;
                break;
            case 0:
                cout << "Fin del sufragio "<< endl;
                break;
            default:
                cout << "Opción no valida elija otra opcion " << endl ;
        }
    } 
    while (votos != 0);
     
    // Aqui en donde se visualizara los resultados 

    cout << " Resultados de votos " << endl ;
    cout << " Candidato A " << candidatoA << " votos" << endl ;
    cout << " Candidato B " << candidatoB << " votos" << endl;
    cout << " Candidato C " << candidatoC << " votos" << endl;

    return 0;
}
