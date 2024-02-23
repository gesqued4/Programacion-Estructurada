#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{                         // inicio main
    bool op_ciclo = true; // variables
    char op_vaciar, op_salir;
    int op_switch, op_operaciones, pos_del_edit_i, pos_del_edit_j;
    int indice_fila = 0, indice_columna = 0, indice_fila_2 = 0, indice_columna_2 = 0;
    int matriz_uno[10][10] = {0}, matriz_dos[10][10] = {0}, matriz_operacion[10][10] = {0};
    int pos_i = 0, pos_j = 0, i = 0, j = 0, pos_y = 0, pos_x = 0, y = 0, x = 0;

    while (op_ciclo)
    {                                             // ciclo while principal del programa
        cout << "\n\n\nSeleccione una opcion:\n"; // impresion de menu de opciones
        cout << "\n1. Ingresar valores primer matriz\n2. Ingresar valores segunda matriz\n3. LLenado numeros random\n4. Listar valores";
        cout << "\n5. Borrar elementos primer matriz\n6. Borrar elementos segunda matriz\n7. Editar  primer matriz\n8. Editar elementos segunda matriz";
        cout << "\n9. Vaciar primer matriz\n10. Vaciar segunda matriz\n11. Operaciones\n12. Salir\n\n";
        cin >> op_switch;

        switch (op_switch)
        { // switch opciones

        case 1: // case 1: ingresar valores primer matriz

            cout << "\nMatriz No.1";
            cout << "\nRango matriz (2x2) - (10x10)\n";

            if (indice_fila < 2 || indice_fila > 10)
            { // condicional if para validar el rango de la matriz
                cout << "\nNumero de filas: ";
                cin >> indice_fila;

                if (indice_fila < 2 || indice_fila > 10)
                {
                    cout << "Indice fuera de rango, ingrese un rango valido, volviendo al menu principal...";
                    break;
                }
            }
            if (indice_columna < 2 || indice_columna > 10)
            {
                cout << "Numero de columnas: ";
                cin >> indice_columna;

                if (indice_columna < 2 || indice_columna > 10)
                {
                    cout << "Indice fuera de rango, ingrese un rango valido, volviendo al menu principal...";
                    break;
                }
            }

            while (i < indice_fila)
            { // ciclo while para ingresar valores en la matriz
                cout << "\nPosicion Matriz [" << pos_i << "] [" << pos_j << "]\nIngrese un numero: ";
                cin >> matriz_uno[i][j];

                pos_j++;
                j++;

                if (j == indice_columna)
                {
                    i++;
                    pos_i++;
                    j = 0;
                    pos_j = 0;
                }
                break;
            } // fin while

            if (i >= indice_fila)
            {
                cout << "Matriz llena, vacie la matriz para continuar... ";
            }
            break; // fin case 1

        case 2: // case 2: ingresar valores segunda matriz

            cout << "\nMatriz No.2";
            cout << "\nRango matriz (2x2) - (10x10)\n";
            if (indice_fila_2 < 2 || indice_fila_2 > 10)
            { // condicional if para validar el rango de la matriz
                cout << "\nNumero de filas: ";
                cin >> indice_fila_2;

                if (indice_fila_2 < 2 || indice_fila_2 > 10)
                {
                    cout << "Indice fuera de rango, ingrese un rango valido, volviendo al menu principal...";
                    break;
                }
            }
            if (indice_columna_2 < 2 || indice_columna_2 > 10)
            {
                cout << "Numero de columnas: ";
                cin >> indice_columna_2;

                if (indice_columna_2 < 2 || indice_columna_2 > 10)
                {
                    cout << "Indice fuera de rango, ingrese un rango valido, volviendo al menu principal...";
                    break;
                }
            }

            while (y < indice_fila_2)
            { // ciclo while para ingresar valores en la matriz
                cout << "\nPosicion Matriz [" << pos_y << "] [" << pos_x << "]\nIngrese un numero: ";
                cin >> matriz_dos[y][x];

                pos_x++;
                x++;

                if (x == indice_columna_2)
                {
                    y++;
                    pos_y++;
                    x = 0;
                    pos_x = 0;
                }
                break;
            } // fin while

            if (y >= indice_fila_2)
            {
                cout << "\nMatriz llena, vacia la matriz para continuar... ";
            }
            break; // fin case 2

        case 3: // llenado numero random

            cout << "\nLlenado de matrices con numeros aleatorios\nLa matrices se vaciaran para introducir numeros aleatorios...\n";
            cout << "\nEsta seguro de querer vaciar la primera matriz? Esta operacion eliminara todos los elementos contenidos en la matriz. ";
            cout << "Por favor, confirme su decision. S/N\n\n";
            cin >> op_vaciar;

            if (op_vaciar == 'S' || op_vaciar == 's')
            {
                for (i = 0; i < indice_fila; i++)
                {
                    for (j = 0; j < indice_columna; j++)
                    {
                        matriz_uno[i][j] = 0;
                    }
                }
                cout << "\nLos elementos de la matriz han sido eliminados con exito...";
                i = 0, j = 0, indice_fila = 0, indice_columna = 0;
                cout << "\nMatriz No.1\nRango matriz (2x2) - (10x10)\n";

                if (indice_fila < 2 || indice_fila > 10)
                { // condicional if para validar el rango de la matriz
                    cout << "\nNumero de filas: ";
                    cin >> indice_fila;

                    if (indice_fila < 2 || indice_fila > 10)
                    {
                        cout << "Indice fuera de rango, ingrese un rango valido, volviendo al menu principal...";
                        break;
                    }
                }
                if (indice_columna < 2 || indice_columna > 10)
                {
                    cout << "Numero de columnas: ";
                    cin >> indice_columna;

                    if (indice_columna < 2 || indice_columna > 10)
                    {
                        cout << "Indice fuera de rango, ingrese un rango valido, volviendo al menu principal...";
                        break;
                    }
                }
            }
            else
            {
                break;
            }

            cout << "\nEsta seguro de querer vaciar la segunda matriz? Esta operacion eliminara todos los elementos contenidos en la matriz. ";
            cout << "Por favor, confirme su decision. S/N\n";
            cin >> op_vaciar;

            if (op_vaciar == 'S' || op_vaciar == 's')
            {
                for (y = 0; y < indice_fila_2; y++)
                {
                    for (x = 0; x < indice_columna_2; x++)
                    {
                        matriz_dos[y][x] = 0;
                    }
                }
                cout << "\nLos elementos de la matriz han sido eliminados con exito...";
                y = 0, x = 0, indice_fila_2 = 0, indice_columna_2 = 0;

                cout << "\nMatriz No.2";
                cout << "\nRango matriz (2x2) - (10x10)\n";
                if (indice_fila_2 < 2 || indice_fila_2 > 10)
                { // condicional if para validar el rango de la matriz
                    cout << "\nNumero de filas: ";
                    cin >> indice_fila_2;

                    if (indice_fila_2 < 2 || indice_fila_2 > 10)
                    {
                        cout << "Indice fuera de rango, ingrese un rango valido, volviendo al menu principal...";
                        break;
                    }
                }
                if (indice_columna_2 < 2 || indice_columna_2 > 10)
                {
                    cout << "Numero de columnas: ";
                    cin >> indice_columna_2;

                    if (indice_columna_2 < 2 || indice_columna_2 > 10)
                    {
                        cout << "Indice fuera de rango, ingrese un rango valido, volviendo al menu principal...";
                        break;
                    }
                }
            }
            else
            {
                break;
            }

            // Inicializar la semilla para la función rand() utilizando el tiempo actual
            srand(time(0));

            // Llenar la matriz_uno con valores aleatorios en el rango de -100 a 100
            for (i = 0; i < indice_fila; ++i)
            {
                for (j = 0; j < indice_columna; ++j)
                {
                    matriz_uno[i][j] = rand() % 201 - 100; // Generar números aleatorios en el rango de -100 a 100
                }
            }

            // Llenar la matriz2 con valores aleatorios en el rango de -100 a 100
            for (i = 0; i < indice_fila_2; ++i)
            {
                for (j = 0; j < indice_columna_2; ++j)
                {
                    matriz_dos[i][j] = rand() % 201 - 100; // Generar números aleatorios en el rango de -100 a 100
                }
            }

            cout << "\nOperacion exitosa, matrices llenadas con valores aleatorios..." << endl;

            break;

        case 4: // case 4: listar valores

            if ((indice_fila >= 2 && indice_fila <= 10) || (indice_columna >= 2 && indice_columna <= 10))
            {
                cout << "\n\nPrimer Matriz\n";
                for (i = 0; i < indice_fila; i++)
                {
                    for (j = 0; j < indice_columna; j++)
                    {
                        cout << "[" << matriz_uno[i][j] << "]"
                             << "\t";
                    }
                    cout << "\n";
                }
            }
            else
            {
                cout << "\nPrimer matriz vacia, ingrese valores para continuar...";
            }
            if ((indice_fila_2 >= 2 && indice_fila_2 <= 10) || (indice_columna_2 >= 2 && indice_columna_2 <= 10))
            {
                cout << "\n\nSegunda Matriz\n";
                for (y = 0; y < indice_fila_2; y++)
                {
                    for (x = 0; x < indice_columna_2; x++)
                    {
                        cout << "[" << matriz_dos[y][x] << "]"
                             << "\t";
                    }
                    cout << "\n";
                }
            }
            else
            {
                cout << "\nSegunda matriz vacia, ingrese valores para continuar...";
            }

            break; // fin case 4

        case 5: // case 5: borrar elementos primer matriz

            pos_del_edit_i = 0;
            pos_del_edit_j = 0;

            cout << "\nBorrar elementos, primer matriz";
            if (indice_fila == 0 || indice_columna == 0)
            {
                cout << "\nMatriz vacia";
            }
            else
            {
                cout << "\nIngrese la fila del elemento que desea borrar: ";
                cin >> pos_del_edit_i;

                cout << "Ingrese la columna del elemento que desea borrar: ";
                cin >> pos_del_edit_j;
            }

            if ((pos_del_edit_i >= 0 && pos_del_edit_i < indice_fila) && (pos_del_edit_j >= 0 && pos_del_edit_j < indice_columna))
            {
                matriz_uno[pos_del_edit_i][pos_del_edit_j] = 0;
                cout << "Se ha eliminado el valor en la coordenada [" << pos_del_edit_i << "] [" << pos_del_edit_j << "]";
            }
            else
            {
                cout << " o posicion fuera de rango, ingrese valores para continuar...";
            }
            break; // fin case 5

        case 6: // case 6: borrar elementos segunda matriz

            pos_del_edit_i = 0;
            pos_del_edit_j = 0;

            cout << "\nBorrar elementos, segunda matriz";
            if (indice_fila_2 == 0 || indice_columna_2 == 0)
            {
                cout << "\nMatriz vacia";
            }
            else
            {
                cout << "\nIngrese la fila del elemento que desea borrar: ";
                cin >> pos_del_edit_i;

                cout << "Ingrese la columna del elemento que desea borrar: ";
                cin >> pos_del_edit_j;
            }

            if ((pos_del_edit_i >= 0 && pos_del_edit_j < indice_fila_2) && (pos_del_edit_i >= 0 && pos_del_edit_j < indice_columna_2))
            {
                matriz_dos[pos_del_edit_i][pos_del_edit_j] = 0;
                cout << "Se ha eliminado el valor en la coordenada [" << pos_del_edit_i << "] [" << pos_del_edit_j << "]";
            }
            else
            {
                cout << " o posicion fuera de rango, ingrese valores para continuar...";
            }
            break; // fin case 6

        case 7: // case 7: editar primer arreglo

            pos_del_edit_i = 0;
            pos_del_edit_j = 0;

            cout << "\nEditar elementos, primer matriz";

            if (indice_fila == 0 || indice_columna == 0)
            {
                cout << "\nMatriz vacia";
            }
            else
            {
                cout << "\nIngrese la fila del elemento que desea editar: ";
                cin >> pos_del_edit_i;

                cout << "Ingrese la columna del elemento que desea editar: ";
                cin >> pos_del_edit_j;
            }

            if ((pos_del_edit_i >= 0 && pos_del_edit_i < indice_fila) && (pos_del_edit_j >= 0 && pos_del_edit_j < indice_columna))
            {
                cout << "Ingrese el nuevo valor de la matriz: ";
                cin >> matriz_uno[pos_del_edit_i][pos_del_edit_j];
                cout << "Se ha editado el valor en la coordenada [" << pos_del_edit_i << "] [" << pos_del_edit_j << "]";
            }
            else
            {
                cout << "o posicion fuera de rango, ingrese valores para continuar...";
            }
            break; // fin case 6

        case 8: // case 8: editar segundo arreglo

            pos_del_edit_i = 0;
            pos_del_edit_j = 0;

            cout << "\nEditar elementos, segunda matriz";

            if (indice_fila_2 == 0 || indice_columna_2 == 0)
            {
                cout << "\nMatriz vacia";
            }
            else
            {
                cout << "\nIngrese la fila del elemento que desea editar: ";
                cin >> pos_del_edit_i;

                cout << "Ingrese la columna del elemento que desea editar: ";
                cin >> pos_del_edit_j;
            }

            if ((pos_del_edit_i >= 0 && pos_del_edit_i < indice_fila_2) && (pos_del_edit_j >= 0 && pos_del_edit_j < indice_columna_2))
            {
                cout << "Ingrese el nuevo valor de la matriz: ";
                cin >> matriz_dos[pos_del_edit_i][pos_del_edit_j];
                cout << "Se ha editado el valor en la coordenada [" << pos_del_edit_i << "] [" << pos_del_edit_j << "]";
            }
            else
            {
                cout << " o posicion fuera de rango, ingrese valores para continuar...";
            }
            break; // fin case 8

        case 9: // case 9: vaciar primer arreglo

            if (indice_fila == 0 || indice_columna == 0)
            {
                cout << "\nLa matriz ya esta vacia...";
            }
            else
            {
                cout << "\nEsta seguro de querer vaciar la primera matriz? Esta operacion eliminara todos los elementos contenidos en la matriz. ";
                cout << "Por favor, confirme su decision. S/N\n\n";
                cin >> op_vaciar;

                if (op_vaciar == 'S' || op_vaciar == 's')
                {
                    for (i = 0; i < indice_fila; i++)
                    {
                        for (j = 0; j < indice_columna; j++)
                        {
                            matriz_uno[i][j] = 0;
                        }
                    }
                    cout << "\nLos elementos de la matriz han sido eliminados con exito...";
                    i = 0, j = 0, pos_i = 0, pos_j = 0;
                    indice_fila = 0, indice_columna = 0;
                }
                else
                {
                    break;
                }
            }
            break; // fin case 9

        case 10: // case 10: vaciar segundo arreglo

            if (indice_fila_2 == 0 || indice_columna_2 == 0)
            {
                cout << "\nLa matriz ya esta vacia...";
            }
            else
            {
                cout << "\nEsta seguro de querer vaciar la segunda matriz? Esta operacion eliminara todos los elementos contenidos en la matriz. ";
                cout << "Por favor, confirme su decision. S/N\n";
                cin >> op_vaciar;

                if (op_vaciar == 'S' || op_vaciar == 's')
                {
                    for (y = 0; y < indice_fila_2; y++)
                    {
                        for (x = 0; x < indice_columna_2; x++)
                        {
                            matriz_dos[y][x] = 0;
                        }
                    }
                    cout << "\nLos elementos de la matriz han sido eliminados con exito...";
                    y = 0, x = 0, pos_y = 0, pos_x = 0;
                    indice_fila_2 = 0, indice_columna_2 = 0;
                }
                else
                {
                    break;
                }
            }

            break; // fin case 10

        case 11: // case 11: operaciones

            cout << "\nMenu operaciones\n\nQue operacion desea realizar?\n";
            cout << "1. Suma\n2. Resta\n3. Multiplicacion\n\n";
            cin >> op_operaciones;

            switch (op_operaciones)
            {       // switch menu operaciones
            case 1: // case 1: suma

                if (indice_fila == indice_fila_2 && indice_columna == indice_columna_2)
                {
                    i = 0;
                    j = 0;
                    x = 0;
                    y = 0;

                    while (i < indice_fila && y < indice_fila_2)
                    { // ciclo while para iterar los indices para sumar los valores
                        matriz_operacion[i][j] = matriz_uno[i][j] + matriz_dos[i][j];
                        j++;
                        x++;

                        if (j == indice_columna && x == indice_columna_2)
                        {
                            i++;
                            y++;
                            j = 0;
                            x = 0;
                        }
                    }

                    cout << "\n\nEl resultado de sumar estas matrices es:\n";
                    for (i = 0; i < indice_fila; i++)
                    { // ciclo for para imprimir la matriz suma
                        for (j = 0; j < indice_columna; j++)
                        {
                            cout << "[" << matriz_operacion[i][j] << "]"
                                 << "\t";
                        }
                        cout << "\n";
                    }
                }
                else
                {
                    cout << "\nLas dimensiones de las matrices no coinciden";
                }

                break; // fin case 1

            case 2: // case 2: resta

                if (indice_fila == indice_fila_2 && indice_columna == indice_columna_2)
                {
                    i = 0;
                    j = 0;
                    x = 0;
                    y = 0;

                    while (i < indice_fila && y < indice_fila_2)
                    { // ciclo while para iterar los indices para restar los valores
                        matriz_operacion[i][j] = matriz_uno[i][j] - matriz_dos[i][j];
                        j++;
                        x++;

                        if (j == indice_columna && x == indice_columna_2)
                        {
                            i++;
                            y++;
                            j = 0;
                            x = 0;
                        }
                    }

                    cout << "\n\nEl resultado de restar estas matrices es:\n";
                    for (i = 0; i < indice_fila; i++)
                    { // ciclo for para imprimir la matriz resta
                        for (j = 0; j < indice_columna; j++)
                        {
                            cout << "[" << matriz_operacion[i][j] << "]"
                                 << "\t";
                        }
                        cout << "\n";
                    }
                }
                else
                {
                    cout << "\nLas dimensiones de las matrices no coinciden";
                }
                break; // fin case 2
            case 3:    // case 3: multiplicacion

                if (indice_columna == indice_fila_2)
                {

                    // iterar sobre cada elemento de la matriz resultado
                    for (int i = 0; i < indice_fila; ++i)
                    {
                        for (int x = 0; x < indice_fila_2; ++x)
                        {
                            // Calcular el producto punto de la fila i de la primera matriz
                            // y la columna x de la segunda matriz
                            for (int k = 0; k < indice_columna; ++k)
                            {
                                matriz_operacion[i][x] += matriz_uno[i][k] * matriz_dos[k][x];
                            }
                        }
                    }

                    // Imprimir la matriz resultado
                    cout << "\n\nEl resultado de la multiplicacion de estas matrices es:\n";
                    for (int i = 0; i < indice_fila; ++i)
                    {
                        for (int x = 0; x < indice_fila_2; ++x)
                        {
                            cout << "[" << matriz_operacion[i][x] << "]"
                                 << "\t";
                        }
                        cout << "\n";
                    }
                }
                else
                {
                    cout << "Las dimensiones de las matrices no son compatibles para la multiplicación.";
                } // fin case 3
                break;

            default:
                cout << "\nOpcion incorrecta, seleccione una opcion valida...";

            } // fin switch menu operaciones

            break; // fin case 11

        case 12: // case 12: salir

            cout << "\n\nDesea finalizar la ejecucion del programa. Por favor, confirme su decision. S/N\n";
            cin >> op_salir;

            if (op_salir == 'S' || op_salir == 's')
            {
                op_ciclo = false;
            }
            else
            {
                cout << "\nVolviendo al menu principal...";
            }

            break; // fin case 12

        default: // default
            cout << "\nOpcion incorrecta, seleccione una opcion valida...";
        } // fin switch
    }     // fin ciclo while

    return 0;
} // fin main