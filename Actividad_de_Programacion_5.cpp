/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 15 de Febrero de 2024
        PROGRAMA: Actividad_de_Programacion_5.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: Programa de un array de 10 espacios
**************************************************************/

#include <iostream>                                                                             //librerias
using namespace std;
int main(){
	bool op_ciclo = true;                                                                       //variables
	int array[10];
    int indice = 0, op_switch, sum = 0, i, pos = 0;
    char op_vaciar, op_salir;

        while(op_ciclo){                                                                        //ciclo principal del programa
            cout << "\n\nSeleccione una opcion:\n";                                             //impresion de menu de opciones
            cout << "\n1. Ingresar valores\n2. Sumar valores\n3. Listar valores\n4. Borrar elementos\n5. Editar elementos\n6. Vaciar arreglo\n7. Salir\n\n"; 
            cout <<"|_______|\b\b\b\b\b";
            cin >> op_switch;

            switch(op_switch){                                                                  //switch para las diferentes opciones
                case 1:                                                                         //ingresar valores

                if(indice >= 0 && indice < 10){
                    cout <<"\nPosicion No. " << pos << "\nIngrese un numero: ";
                    cin >> array[indice];
                    pos++;
                    indice++;
                } else {
                    cout << "\nArray lleno, vacia el arreglo para continuar... ";
                }
                    break;

                case 2:                                                                        //sumar valores

                    cout << "\n";
                    for(i = 0; i < indice; i++){
                        sum += array[i];
                    }
                    cout << "La suma de los valores ingresados es: " << sum;
                    break;

                case 3:                                                                         //listar valores

                    cout << "\n";
                    for(i = 0; i < indice; i++){
                        cout << "[" << array[i] << "] ";
                    }
                    break;

                case 4:                                                                         //borrar elementos
                    
                    cout << "\nIngrese la posicion del elemento que desea borrar: ";
                    cin >> i;

                    if(i >= 0 && i < 10){
                        array[i] = 0;
                        cout << "Se ha eliminado el valor en la posicion no. " << i;
                    } else {
                        cout << "\nEsa posicion no existe";
                    }
                    break;

                case 5:                                                                         //editar elementos

                    cout << "\nIngrese la posicion del elemento que desea editar: ";
                    cin >> i;

                    if(i >= 0 && i < 10){   
                        cout << "Ingrese el nuevo valor en el arreglo: ";
                        cin >> array[i];
                        cout << "\nEl elemento del arreglo ha sido modificado con exito...";
                    } else {
                        cout << "\nEsa posicion no existe";
                    }
                 
                    break;

                case 6:                                                                         //vaciar arreglo

                    cout << "\nEsta seguro de querer vaciar el arreglo? Esta operacion eliminara todos los elementos contenidos en el arreglo. ";
                    cout << "Por favor, confirme su decision. S/N\n\n";
                    cout <<"|_______|\b\b\b\b\b";
                    cin >> op_vaciar;

                    if(op_vaciar == 'S' || op_vaciar == 's'){
                        for(i = 0; i < indice; i++){
                            array[i] = 0;
                        } 
                        cout << "\nLos elementos del arreglo han sido eliminados con exito...";
                        indice = 0;
                        pos = 0;
                    } else {
                        cout << "\nOpcion incorrecta, seleccione una opcion valida...";
                    }
                    break;
                
                case 7:                                                                         //salir

                    cout << "\n\nDesea finalizar la ejecucion del programa. Por favor, confirme su decision. S/N\n\n";
                    cout <<"|_______|\b\b\b\b\b";
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