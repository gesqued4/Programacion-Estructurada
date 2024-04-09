/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 11 de Marzo de 2024
        PROGRAMA: Actividad_de_Programacion_10.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: 
        Elaborar el juego de las Torres de Hanoi en C++ 
            Se deben contar el número de movimientos
            Se pueden utilizar de 3 a 8 discos
            Utilizar de preferencia librerías
            Utilizar funciones y debe implementar algún método recursivo
**************************************************************/

#include <iostream>
using namespace std;
#include "Act_12_lib.cpp"

int main (){
    bool op_while = true;
    char op_switch = '0';
    int num_discos = 0, movimientos = 0;
    const int filas = 3;
    int **torre_hanoi;
    int tam_discos[num_discos] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 0;

    while(op_while){        //Ciclo while

    if (op_switch == '0'){
    cout << "\n\t\t\tTorre de Hanoi" << endl;
    cout << " 1. Instrucciones" << endl;
    cout << " 2. Solucion" << endl;
    cout << " 3. Jugar" << endl;
    cout << " 4. Salir" << endl;
    cout << "Seleccion una opcion: ";
    cin >> op_switch;
    }

    switch(op_switch){    
        case '1':       //Case 1: Instrucciones
            cout << "\nObjetivo: Mover todos los discos de la torre de origen a la torre objetivo." << endl;
            cout << "Reglas: Solo puedes mover un disco a la vez y nunca puedes colocar un disco mas grande sobre uno mas chico." << endl;
            cout << "Instrucciones: Selecciona un disco y luego la torre a la que deseas moverlo. Repite hasta completar la torre objetivo." << endl;
            cout << "Consejos: Planifica tus movimientos y prioriza los discos mas chicos." << endl;
            cout << "Finalizacion: Completas el juego cuando todos los discos esten en la torre objetivo en la misma disposicion inicial." << endl;
            op_switch = '0';
        break;          //Fin case 1
        case '2':       //Case 2: Solucion
        int n_discos;
        
            cout << "\n\t\t\tTorre de Hanoi" << endl;
            cout << "Ingrese la cantidad de discos (3-8): ";
            cin >> n_discos;
            if (n_discos >= 3 && n_discos <= 8){
                cout << "Numero de discos valido! La solucion del juego es la siguiente:" << endl;
                cout << endl;
                hanoi(n_discos, 'A', 'C', 'B', movimientos);
                cout << "Total de movimientos realizados: " << movimientos << endl;
            }
            else {
                cout << "La cantidad de discos ingresada esta fuera del rango permitido..." << endl;
            }
            movimientos = 0;
            op_switch = '0';
        
        break;          //Fin case 2
        case '3':       //Case 3: Jugar
            if(num_discos == 0){
                cout << "Ingrese la cantidad de discos (3-8): ";
                cin >> num_discos;

                if (num_discos >= 3 && num_discos <= 8){
                cout << "Numero de discos valido! Comenzando el juego..." << endl;

                torre_hanoi = new int*[num_discos];     //Reserva de memoria para la matriz
                for(int i = 0; i < num_discos; ++i)
                    torre_hanoi[i] = new int[filas];
                }
            }

            if (num_discos >= 3 && num_discos <= 8){

                if(k==0){
                    //Inicializar la torre
                    for(int i = 0; i < num_discos; i++){        //Llenar el array
                        for(int j = 0; j < filas; j++){
                            torre_hanoi[i][j] = {0};
                        }
                    }
            
                    for(int i = 0; i < num_discos; i++){        //Llenar la primera columna
                        torre_hanoi[i][0] = tam_discos[i];
                    }

                    imprimir_torre(torre_hanoi, num_discos, filas);
                k=1;

                }
            
            
            // Solicitar la columna de origen y destino para mover el disco
            int columna_origen, columna_destino;
            cout << "Ingrese la columna de origen (1-" << num_discos << "): ";
            cin >> columna_origen;
            cout << "Ingrese la columna de destino (1-" << num_discos << "): ";
            cin >> columna_destino;

            // Verificar si las columnas son válidas
            if (columna_origen >= 1 && columna_origen <= num_discos && columna_destino >= 1 && columna_destino <= num_discos) {
                // Convertir el número de columna a índice de arreglo restando 1
                columna_origen--;
                columna_destino--;

                // Verificar si hay un disco en la columna de origen
                if (torre_hanoi[columna_origen][0] != 0) {
                  mover_disco(torre_hanoi, num_discos, columna_origen, columna_destino);
                } else {
                    cout << "La columna de origen esta vacia. No hay discos para mover." << endl;
                    }
            } else {
                cout << "Columnas de origen o destino invalidas." << endl;
                }

            // Imprimir el estado actualizado del array
            imprimir_torre(torre_hanoi, num_discos, filas);
            }
            else {
                cout << "La cantidad de discos ingresada esta fuera del rango permitido..." << endl;
                num_discos = 0;
            }
        break;          //Fin case 3
        case '4':       //Case 4: Salir
            op_while = false;
        break;          //Fin case 4
        default:
            cout << "Opcion incorrecta, seleccione una opcion valida...";
            op_switch = '0';
        }       //Fin Switch
    }         //Fin ciclo while
    return 0;
}           //Fin main

