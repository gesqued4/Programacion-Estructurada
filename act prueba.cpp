#include <iostream>
#include <vector>
#include <string>
#include "funciones_conjunto.h"
using namespace std;

int main() {
    bool op_ciclo = true;
    char op_salir;
    vector<string> universo;
    vector<string> conjunto_uno;
    vector<string> conjunto_dos;

    while (op_ciclo) {
        int op_switch;
        cout << "\n\nSeleccione una opcion:\n";
        cout << "\n1. Ingresar valores primer conjunto\n2. Ingresar valores segundo conjunto\n3. Listar valores\n4. Borrar valores primer conjunto";
        cout << "\n5. Borrar valores segundo conjunto\n6. Editar primer conjunto\n7. Editar segundo conjunto\n8. Vaciar primer conjunto";
        cout << "\n9. Vaciar segundo conjunto\n10. Operaciones\n11. Salir\n\n";
        cin >> op_switch;

        switch (op_switch) {
            case 1:
                ingresarConjunto(conjunto_uno, universo);
                break;
            case 2:
                ingresarConjunto(conjunto_dos, universo);
                break;
            case 3:
                listarConjuntos(universo, conjunto_uno, conjunto_dos);
                break;
            case 4:
                borrarElemento(conjunto_uno);
                break;
            case 5:
                borrarElemento(conjunto_dos);
                break;
            case 6:
                editarElemento(conjunto_uno);
                break;
            case 7:
                editarElemento(conjunto_dos);
                break;
            case 8:
                vaciarConjunto(conjunto_uno);
                break;
            case 9:
                vaciarConjunto(conjunto_dos);
                break;
            case 10:
                realizarOperaciones(conjunto_uno, conjunto_dos);
                break;
            case 11:
                cout << "\n\nDesea finalizar la ejecucion del programa. Por favor, confirme su decision. S/N\n\n";
                cin >> op_salir;
                if (op_salir == 'S' || op_salir == 's') {
                    op_ciclo = false;
                } else {
                    cout << "\nVolviendo al menu principal...";
                }
                break;
            default:
                cout << "\nOpcion incorrecta, seleccione una opcion valida...";
        }
    }

    return 0;
}