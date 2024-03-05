/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 04 de Marzo de 2024
        PROGRAMA: Actividad_de_Programacion_9.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION:
            Utilizando Librerias de Funciones
            Inserción de valores por parte del usuario (arreglos o vectores)
            Pueden ser textuales o numéricos
            Borrado y edición de elementos
            Vaciado de conjuntos
            Operaciones de Unión, Intersección, Diferencia y complemento.
**************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include "Act_9_lib.cpp"

int main()
{ // inicio main

    //declaracion de variables
    bool op_ciclo = true;
    string elementos_universo, elementos_conjunto_uno, elementos_conjunto_dos;
    int op_switch;
    int size_universo = 0, pos = 0, conjunto_one = 0, conjunto_two = 0;
    vector<string> universo;
    vector<string> conjunto_uno;
    vector<string> conjunto_dos;
    vector<string> conjunto_operacion;

    while (op_ciclo)
    { // ciclo while repeticion programa

        if (size_universo == 0) // condicional para evitar la repeticion de este bloque en el while general
        {
            cout << "Operaciones con Conjuntos\nDefina el tamano del universo: ";
            cin >> size_universo;

            cout << "Ingrese los elementos del universo (caracteres o numeros):\n";
            while (pos < size_universo)
            { // ciclo while para ingresar elementos al conjunto universo
                cin >> elementos_universo;
                universo.push_back(elementos_universo);
                pos++;
            } // fin ciclo while
        }

        print_menu();    //imprimir menu
        cin >> op_switch;


        switch (op_switch)
        {       // switch menu de opciones
        case 1: // case 1: ingresar caracteres primer conjunto
            if (conjunto_one != 1){
                    ingresar_conjunto(conjunto_uno, universo);
                    conjunto_one = 1;
                } else {
                    cout << "El tamano del conjunto esta fuera de rango respecto al universo, volviendo al menu principal...";
                }

            if (conjunto_one == 1){
                cout << "\nConjunto lleno, vacie el conjunto para continuar...";
            }
            break; // fin case 1
        case 2: // case 2: ingresar valores segundo conjunto
            if (conjunto_two != 1){
                    ingresar_conjunto(conjunto_dos, universo);
                    conjunto_two = 1;
                } else {
                    cout << "El tamano del conjunto esta fuera de rango respecto al universo, volviendo al menu principal...";
                }

             if (conjunto_two == 1) {
                cout << "\nConjunto lleno, vacie el conjunto para continuar";
            }
            break; // fin case 2
        case 3:    // case 3: listar valores
            listar_conjuntos(universo, conjunto_uno, conjunto_dos);
            break; // fin case 3
        case 4:    // case 4: borrar valores primer conjunto
            borrar_elemento(conjunto_uno);
            break; // fin case 4
        case 5: // case 5: borrar valores segundo conjunto
            borrar_elemento(conjunto_dos);
            break; // fin case 5
        case 6: // case 6: editar valores primer conjunto
            editar_elemento(conjunto_uno);
            break; // fin case 6
        case 7:    // case 7: editar valores segundo conjunto
            editar_elemento(conjunto_dos);
            break; // fin case 7
        case 8:    // case 8: vaciar primer conjunto
            vaciar_conjunto(conjunto_uno);
            break; // fin case 8
        case 9:    // case 9: vaciar segundo conjunto
            vaciar_conjunto(conjunto_dos);
            break; // fin case 9
        case 10:   // case 10: operaciones conjuntos
            realizar_operaciones(conjunto_uno, conjunto_dos);
            break; // fin case 10

        case 11: // case 11: salir
            finalizar_ejecucion(op_ciclo);
            break; // fin case 11
        default: // default
            cout << "\nOpcion incorrecta, seleccione una opcion valida...";
        } // fin switch menu opciones
    }     // fin ciclo while

    return 0;
} // fin main