/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 11 de Marzo de 2024
        PROGRAMA: Actividad_de_Programacion_10.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: Operaciones basicas con matrices, division, y librerias de funciones
**************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "Act_10_lib.cpp"
int main() { 



    int size = 0, seedA = time(0), seedB = time(0) + 1;
    bool op_while = true;
    char op_switch, op_operaciones, op;
    const int filas = 15, columnas = filas;
    int matrizA[filas][columnas], matrizB[filas][columnas], matrizRes[filas][columnas];


    while(op_while){ 
        menu_option();
        cin >> op_switch;

        switch (op_switch){ // switch opciones

        case '1': // case 1: ingresar valores 
            if (size < 2 || size > 15){
            cout << "\nIngrese el tamano de las matrices (2x2 - 15x15): "; 
            cin >> size;
            } 
            if (size < 2 || size > 15){ 
                cout << "Tamano de matriz no valido, ingrese un tamano valido..." << endl; 
            } 
            else if (size >= 2 || size <= 15){ 
                cout << "\nLlenar matriz A" << endl;
                ingresar_valores(matrizA, size);

                cout << "\nLlenar matriz B" << endl;
                ingresar_valores(matrizB, size);
            } 
            break; // fin case 1

        case '2': // case 2: ingresar valores aleatorios
            cout << "\nLlenado de matrices con numeros aleatorios" << endl;
            cout << "\nLlenando matriz A..." << endl;
                valores_aleatorios(matrizA, size, seedA);
            cout << "Llenando matriz B..." << endl;
                valores_aleatorios(matrizB, size, seedB);
            cout << "\nOperacion exitosa, matrices llenadas con valores aleatorios." << endl;
           break;   // fin case 2

        case '3': // case 3: listar valores
            cout << "\n\nPrimer Matriz\n";
            listar_valores(matrizA, size);
            cout << "\n\nSegunda Matriz\n";
            listar_valores(matrizB, size);
            break;  // fin case 3

        case '4':   // case 4: borrar elementos matriz
        cout << "\nBorrar elementos: \n1. Primer matriz\n2. Segunda matriz" << endl;
        cin >> op; 
            switch(op){
            case '1':
                cout << "\nBorrar elementos, primer matriz";
                borrar_valores(matrizA, size);
                break;
            case '2':
                cout << "\nBorrar elementos, segunda matriz";
                borrar_valores(matrizB, size);
                break;
            default:
                cout << "Opcion invalida, seleccione una opcion valida..";
            }    
            break;  // fin case 4

        case '5':   // case 5: editar elementos matriz 
        cout << "\nEditar elementos: \n1. Primer matriz\n2. Segunda matriz" << endl;
        cin >> op;
            switch(op){
            case '1':
                cout << "\nEditar elementos, primer matriz";
                editar_valores(matrizA, size);
                break;
            case '2':
                cout << "\nEditar elementos, segunda matriz";
                editar_valores(matrizB, size);
                break;
            default:
                cout << "Opcion invalida, seleccione una opcion valida..";
            }
            break;  // fin case 5

        case '6':
        cout << "\nVaciar matriz: \n1. Primer matriz\n2. Segunda matriz" << endl;
        cin >> op;
            switch(op){
            case '1':
                cout << "\nVaciar primera matriz";
                vaciar_matriz(matrizA, size);
                break;
            case '2':
                cout << "\nVaciar segunda matriz";
                vaciar_matriz(matrizB, size);
                break;
            default:
                cout << "Opcion invalida, seleccione una opcion valida..";
            }
            break;

        case '7':
            cout << "\nMenu operaciones\n\nQue operacion desea realizar?\n";
            cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n\n";
            cin >> op_operaciones;

            switch (op_operaciones){       // switch menu operaciones
                case '1': // case 1: suma
                    if (size >= 2 && size <= 15) {
                        suma_matriz(matrizA, matrizB, matrizRes, size);
                    }
                    else {
                        cout << "\nMatriz vacia, ingrese valores para continuar...";
                    }
                    break;
                case '2': // case 2: resta
                    if (size >= 2 && size <= 15) {
                        resta_matriz(matrizA, matrizB, matrizRes, size);
                    }
                    else {
                        cout << "\nMatriz vacia, ingrese valores para continuar...";
                    }
                    break;
                case '3': // case 3: multiplicacion
                    if (size >= 2 && size <= 15) {
                        multi_matriz(matrizA, matrizB, matrizRes, size);
                    }
                    else {
                        cout << "\nMatriz vacia, ingrese valores para continuar...";
                    }
                    break;
               /* case '4':   // case 4: division
                    if (size >= 2 && size <= 15) {
                        dividir_matriz(matrizA, matrizB, matrizRes, size);
                    }
                    else {
                        cout << "\nMatriz vacia, ingrese valores para continuar...";
                    } */
                default:
                    cout << "Opcion invalida, seleccione una opcion valida..";
            }
            break;

        case '8': // case 12: salir
            op_while = false;
            break; // fin case 12

        default: // default
            cout << "\nOpcion incorrecta, seleccione una opcion valida...";
        } // fin switch
    }     // fin ciclo while

    return 0;
} // fin main