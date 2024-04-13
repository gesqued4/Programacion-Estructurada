#include <iostream>
#include <vector>
using namespace std;
#include "Act_11_lib.cpp"

int main (){
    bool op_while = true;       //declarar variables
    char op_switch;
    int i = 0 ;
    const int tamano = 50;
    int array [tamano] = {0};
    while(op_while){            // inicio ciclo while
        cout << "\n1. Ingresar valores\n2. Listar valores\n3. Salir\n" << endl;
        cin >> op_switch;
        switch(op_switch){      // inicio switch
            case '1':       // case 1: ingresar valores
                ingresar_valores(array, tamano, i);

            break;          // fin case 1
            case '2':       // case 2: listar valores
                cout << "Los valores ingresados son:" << endl;
                ordenar_arreglo(array, tamano);
                listar_arreglo(array, tamano);
            break;          // fin case 2
            case '3':       // case 3: salir
                op_while = false;
            break;
            default:
                cout << "Esa opcion no existe...";
        }       // fin switch
    }       //fin ciclo while
return 0;
}       // fin main