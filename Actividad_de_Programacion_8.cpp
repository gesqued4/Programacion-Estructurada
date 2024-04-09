/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 23 de Febrero de 2024
        PROGRAMA: Actividad_de_Programacion_8.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION:
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

int main()
{ // inicio main

    bool op_ciclo = true;
    char op_vaciar, op_salir;
    string elementos_universo, elementos_conjunto_uno, elementos_conjunto_dos;
    int op_switch, op_operaciones, i;
    int size_universo = 0, pos = 0, size_conjunto_uno = 0, size_conjunto_dos = 0, conjunto_one = 0, conjunto_two = 0;
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

        cout << "\n\nSeleccione una opcion:\n"; // impresion de menu de opciones
        cout << "\n1. Ingresar valores primer conjunto\n2. Ingresar valores segunda conjunto\n3. Listar valores\n4. Borrar valores primer conjunto";
        cout << "\n5. Borrar valores segundo conjunto\n6. Editar primer conjunto\n7. Editar segundo conjunto\n8. Vaciar primer conjunto";
        cout << "\n9. Vaciar segundo conjunto\n10. Operaciones\n11. Salir\n\n";
        cin >> op_switch;
        switch (op_switch)
        {       // switch menu de opciones
        case 1: // case 1: ingresar caracteres primer conjunto
            if (conjunto_one != 1)
            {
                cout << "\nIngresar valores primer conjunto\nDefina el tamano del conjunto: ";
                cin >> size_conjunto_uno;

                if (size_conjunto_uno > 0 && size_conjunto_uno <= size_universo - size_conjunto_dos) // validar que el tamano sea menor al universo
                {
                    cout << "Ingrese los elementos del conjunto:\n";
                    for (i = 0; i < size_conjunto_uno; i++)
                    {
                        cin >> elementos_conjunto_uno;
                        /* Validar si el elemento está en el universo */
                        if (find(universo.begin(), universo.end(), elementos_conjunto_uno) != universo.end())
                        {
                            conjunto_uno.push_back(elementos_conjunto_uno);
                        }
                        else
                        {
                            cout << "Elemento '" << elementos_conjunto_uno << "' no es valido en el universo.\n";
                            break; // Si el elemento no es valido sales del bucle
                        }
                    }
                    conjunto_one = 1;
                }
                else
                {
                    cout << "El tamano del conjunto esta fuera de rango respecto al universo, volviendo al menu principal...";
                }
            }
            else if (conjunto_one == 1)
            {
                cout << "\nConjunto lleno, vacie el conjunto para continuar...";
            }
            break; // fin case 1

        case 2: // case 2: ingresar valores segundo conjunto

            if (conjunto_two != 1)
            {
                cout << "\nIngresar valores segundo conjunto\nDefina el tamano del conjunto: ";
                cin >> size_conjunto_dos;

                if (size_conjunto_dos > 0 && size_conjunto_dos <= size_universo - size_conjunto_uno) // validar que el tamano sea menor al universo
                {
                    cout << "Ingrese los elementos del conjunto:\n";
                    for (i = 0; i < size_conjunto_dos; i++)
                    {
                        cin >> elementos_conjunto_dos;
                        /* Validar si el elemento está en el universo */
                        if (find(universo.begin(), universo.end(), elementos_conjunto_dos) != universo.end())
                        {
                            conjunto_dos.push_back(elementos_conjunto_dos);
                        }
                        else
                        {
                            cout << "Elemento '" << elementos_conjunto_dos << "' no es valido en el universo.\n";
                            break; // Si el elemento no es valido sales del bucle
                        }
                    }
                    conjunto_two = 1;
                }
                else
                {
                    cout << "El tamano del conjunto esta fuera de rango respecto al universo, volviendo al menu principal...";
                }
            }
            else if (conjunto_two == 1)
            {
                cout << "\nConjunto lleno, vacie el conjunto para continuar";
            }
            break; // fin case 2
        case 3:    // case 3: listar valores

            cout << "\nUniverso:\n";
            for (i = 0; i < universo.size(); i++)
            {
                cout << "[" << universo[i] << "] ";
            }
            cout << "\n\nPrimer Conjunto:\n";
            for (i = 0; i < conjunto_uno.size(); i++)
            {
                cout << "[" << conjunto_uno[i] << "] ";
            }
            cout << "\n\nSegundo Conjunto:\n";
            for (i = 0; i < conjunto_dos.size(); i++)
            {
                cout << "[" << conjunto_dos[i] << "] ";
            }
            break; // fin case 3
        case 4:    // case 4: borrar valores primer conjunto

            cout << "\nBorrar valores primer conjunto";
            cout << "\nIngrese la posicion del elemento que desea borrar (0 - " << size_conjunto_uno - 1 << "): ";
            cin >> i;

            conjunto_uno.erase(conjunto_uno.begin() + i);
            cout << "Se ha eliminado el valor en la posicion no. " << i;

            break; // fin case 4

        case 5: // case 5: borrar valores segundo conjunto
            cout << "\nBorrar valores segundo conjunto";
            cout << "\nIngrese la posicion del elemento que desea borrar (0 - " << size_conjunto_dos - 1 << "): ";
            cin >> i;

            conjunto_dos.erase(conjunto_dos.begin() + i);
            cout << "Se ha eliminado el valor en la posicion no. " << i;

            break; // fin case 5

        case 6: // case 6: editar valores primer conjunto
            cout << "\nIngrese la posicion del elemento que desea editar: ";
            cin >> i;

            cout << "Ingrese el nuevo valor en el conjunto uno: ";
            cin >> conjunto_uno[i];
            cout << "\nEl elemento ha sido modificado con exito...";

            break; // fin case 6
        case 7:    // case 7: editar valores segundo conjunto
            cout << "\nIngrese la posicion del elemento que desea editar: ";
            cin >> i;

            cout << "Ingrese el nuevo valor en el conjunto dos: ";
            cin >> conjunto_dos[i];
            cout << "\nEl elemento ha sido modificado con exito...";
            break; // fin case 7
        case 8:    // case 8: vaciar primer conjunto
            cout << "\nEsta seguro de querer vaciar el primer conjunto? Esta operacion eliminara todos los elementos contenidos en el conjunto. ";
            cout << "Por favor, confirme su decision. S/N\n\n";
            cin >> op_vaciar;

            if (op_vaciar == 'S' || op_vaciar == 's')
            {

                conjunto_uno.clear();
                cout << "\nLos elementos del conjunto han sido eliminados con exito...";
            }
            else
            {
                cout << "\nOpcion incorrecta, seleccione una opcion valida...";
            }


            break; // fin case 8
        case 9:    // case 9: vaciar segundo conjunto
            cout << "\nEsta seguro de querer vaciar el segundo conjunto? Esta operacion eliminara todos los elementos contenidos en el conjunto. ";
            cout << "Por favor, confirme su decision. S/N\n\n";
            cin >> op_vaciar;

            if (op_vaciar == 'S' || op_vaciar == 's')
            {

                conjunto_dos.clear();
                cout << "\nLos elementos del conjunto han sido eliminados con exito...";
            }
            else
            {
                cout << "\nOpcion incorrecta, seleccione una opcion valida...";
            }
            break; // fin case 9
        case 10:   // case 10: operaciones conjuntos

            cout << "\nMenu operaciones\nEliga una opcion:\n1. Union\n2. Interseccion\n3. Diferencia\n4. Complemento\n\n";
            cin >> op_operaciones;

            switch (op_operaciones)
            {       // switch menu operaciones
            case 1: // case 1: union

                conjunto_operacion.clear();
                conjunto_operacion = conjunto_uno; // Agregar todos los elementos de conjunto_uno a la unión

                for (const auto &elem : conjunto_dos)
                {
                    if (find(conjunto_uno.begin(), conjunto_uno.end(), elem) == conjunto_uno.end())
                    {
                        conjunto_operacion.push_back(elem); // Agregar solo los elementos de conjunto_dos que no estan en conjunto_uno
                    }
                }
                cout << "\nUnion de conjuntos: ";
                for (const auto &elem : conjunto_operacion)
                {
                    cout << "[" << elem << "] ";
                }

                break;

            case 2: // case 2: interseccion

                conjunto_operacion.clear(); // Limpiar conjunto_operacion antes de la interseccion
                for (const auto &elem : conjunto_uno)
                {
                    if (find(conjunto_dos.begin(), conjunto_dos.end(), elem) != conjunto_dos.end())
                    {
                        conjunto_operacion.push_back(elem); // Agregar elemento a la interseccion si esta en ambos conjuntos
                    }
                }
                cout << "\nInterseccion de conjuntos: ";
                for (const auto &elem : conjunto_operacion)
                {
                    cout << "[" << elem << "] ";
                }
                break;

            case 3: // case 3: diferencia

                conjunto_operacion.clear(); // Limpiar conjunto_operacion antes de la diferencia
                // Agregar todos los elementos de conjunto_uno que no están en conjunto_dos a conjunto_operacion
                for (const auto &elem : conjunto_uno)
                {
                    if (find(conjunto_dos.begin(), conjunto_dos.end(), elem) == conjunto_dos.end())
                    {
                        conjunto_operacion.push_back(elem);
                    }
                }
                cout << "\nDiferencia de conjuntos (conjunto_uno - conjunto_dos): ";
                for (const auto &elem : conjunto_operacion)
                {
                    cout << "[" << elem << "] ";
                }
                break;

            case 4:                         // case 4: complemento
                conjunto_operacion.clear(); // Limpiar conjunto_operacion antes del complemento
                // Agregar todos los elementos del universo que no están en conjunto_uno a conjunto_operacion
                for (const auto &elem : universo)
                {
                    if (find(conjunto_uno.begin(), conjunto_uno.end(), elem) == conjunto_uno.end())
                    {
                        conjunto_operacion.push_back(elem);
                    }
                }
                cout << "\nComplemento del conjunto respecto al universo: ";
                for (const auto &elem : conjunto_operacion)
                {
                    cout << "[" << elem << "] ";
                }
                break;

            default:
                cout << "\nOpcion incorrecta, seleccione una opcion valida...";
            }      // fin switch menu operaciones
            break; // fin case 10

        case 11: // case 11: salir

            cout << "\n\nDesea finalizar la ejecucion del programa. Por favor, confirme su decision. S/N\n\n";
            cin >> op_salir;

            if (op_salir == 'S' || op_salir == 's')
            {
                op_ciclo = false;
            }
            else
            {
                cout << "\nVolviendo al menu principal...";
            }
            break; // fin case 11

        default: // default

            cout << "\nOpcion incorrecta, seleccione una opcion valida...";

        } // fin switch menu opciones
    }     // fin ciclo while

    return 0;
} // fin main