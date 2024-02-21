/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 15 de Febrero de 2024
        PROGRAMA: Actividad_de_Programacion_6.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: Programa vector sin limite
**************************************************************/

#include <iostream>                                                                             //librerias
#include <vector>
using namespace std;
int main(){
    bool op_ciclo = true;                                                                       //variables
    int op_switch, sum = 0, i, pos = 0, valor;
    vector<int> array;
    char op_vaciar, op_salir;

    while(op_ciclo){                                                                        //ciclo principal del programa
        cout << "\n\nSeleccione una opcion:\n";                                             //impresion de menu de opciones
        cout << "\n1. Ingresar valores\n2. Sumar valores\n3. Listar valores\n4. Borrar elementos\n5. Editar elementos\n6. Vaciar arreglo\n7. Salir\n\n";
        cin >> op_switch;

        switch(op_switch){                                                                  //switch para las diferentes opciones
            case 1:                                                                         //ingresar valores

                    cout <<"\nPosicion No. " << pos << "\nIngrese un numero: ";
                    cin >> valor;
                    array.push_back(valor);
                    pos++;

                break;

            case 2:                                                                        //sumar valores

                cout << "\n";
                for(i = 0; i < array.size(); i++){
                    sum += array[i];
                }
                cout << "La suma de los valores ingresados es: " << sum;
                break;

            case 3:                                                                         //listar valores

                cout << "\n";
                for(i = 0; i < array.size(); i++){
                    cout << "[" << array[i] << "] ";
                }
                break;

            case 4:                                                                         //borrar elementos

                cout << "\nIngrese la posicion del elemento que desea borrar: ";
                cin >> i;

                    array.erase(array.begin()+i);
                    cout << "Se ha eliminado el valor en la posicion no. " << i;
                    pos--;

                break;

            case 5:                                                                         //editar elementos

                cout << "\nIngrese la posicion del elemento que desea editar: ";
                cin >> i;

                    cout << "Ingrese el nuevo valor en el arreglo: ";
                    cin >> array[i];
                    cout << "\nEl elemento del arreglo ha sido modificado con exito...";

                break;

            case 6:                                                                         //vaciar arreglo

                cout << "\nEsta seguro de querer vaciar el arreglo? Esta operacion eliminara todos los elementos contenidos en el arreglo. ";
                cout << "Por favor, confirme su decision. S/N\n\n";
                cin >> op_vaciar;

                if(op_vaciar == 'S' || op_vaciar == 's'){
                    for(i = 0; i < array.size(); i++){
                        array.clear();
                    }
                    cout << "\nLos elementos del arreglo han sido eliminados con exito...";
                    pos = 0;
                } else {
                    cout << "\nOpcion incorrecta, seleccione una opcion valida...";
                }
                break;

            case 7:                                                                         //salir

                cout << "\n\nDesea finalizar la ejecucion del programa. Por favor, confirme su decision. S/N\n\n";
                cin >> op_salir;

                if(op_salir == 'S' || op_salir == 's'){
                    op_ciclo = false;
                } else{
                    cout << "\nVolviendo al menu principal...";
                }

                break;

            default:                                                                        //opcion invalida
                cout << "\nOpcion incorrecta, seleccione una opcion valida...";
        }                                                                                   //fin switch
    }                                                                                       //fin ciclo while


    return 0;
}                                              //fin main
