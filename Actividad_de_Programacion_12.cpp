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
    int ciclo = true;

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
            
            
                // Solicitar la torre de origen y destino para mover el disco
                char torre_origen, torre_destino;
                int torreA = 0, torreB = 1, torreC = 2;
                int posA, posB, posC, topA, topB, topC;
                int mov = 0;

                while(ciclo){
                    int discosA = num_discos - 1;
                    int discosB = num_discos - 1;
                    int discosC = num_discos - 1;
   
                    cout << "Ingrese la torre de origen (A - C): ";
                    cin >> torre_origen;

                    switch (torre_origen){
                        case 'A':
                            cout << "Ingrese la posicion de origen (1 - " << num_discos << "): ";
                            cin >> posA;

                            topA = posA - 1;

                            if(posA > 0 && posA <= num_discos){
                                if(torre_hanoi[topA][torreA] != 0 && torre_hanoi[posA - 1][torreA] != 1){
                                    topA--;
                                }
                            }

                            if((posA > 0 && posA <= num_discos && torre_hanoi[posA - 1][torreA] != 0) && (torre_hanoi[topA][torreA] == 0 || torre_hanoi[posA - 1][torreA] == 1)){

                                cout << "Ingrese la torre de destino (B o C): ";
                                cin >> torre_destino;

                                switch (torre_destino){
                                    case 'B':

                                    cout << "Ingrese la posicion de destino (1 - " << num_discos << "): ";
                                    cin >> posB;

                                    if(posB > 0 && posB <= num_discos && torre_hanoi[posB - 1][torreB] == 0){

                                        while(torre_hanoi[discosB][torreB] != 0){
                                            discosB--;
                                        }
                                    
                                        if((discosB == num_discos - 1 || torre_hanoi[posA - 1][torreA] < torre_hanoi[posB][torreB]) && posB - 1 == discosB){
                                            torre_hanoi[discosB][torreB] = torre_hanoi[posA - 1][torreA];
                                            torre_hanoi[posA - 1][torreA] = 0;
                                            mov++;
                                        }
                                        else {
                                            cout << "Movimiento invalido, no puedes colocar un disco mas grande o posicion de destino incorrecta..." << endl;
                                        }
                                    }
                                    else {
                                        cout << "Posicion fuera de rango o posicion ocupada..." << endl;
                                    }
 
                                    break;
                                    case 'C':

                                        cout << "Ingrese la posicion de destino (1 - " << num_discos << "): ";
                                        cin >> posC;

                                    if(posC > 0 && posC <= num_discos && torre_hanoi[posC - 1][torreC] == 0){

                                        while(torre_hanoi[discosC][torreC] != 0){
                                            discosC--;
                                        }
                                    
                                        if((discosC == num_discos - 1 || torre_hanoi[posA - 1][torreA] < torre_hanoi[posC][torreC]) && posC - 1 == discosC){
                                            torre_hanoi[discosC][torreC] = torre_hanoi[posA - 1][torreA];
                                            torre_hanoi[posA - 1][torreA] = 0;
                                            mov++;
                                        }
                                        else {
                                            cout << "Movimiento invalido, no puedes colocar un disco mas grande o posicion de destino incorrecta..." << endl;
                                        }
                                    }
                                    else {
                                        cout << "Posicion fuera de rango o posicion ocupada..." << endl;
                                    }

                                    break;
                                    default:
                                        cout << "Opcion invalida" << endl;
                                }
                            }
                            else {
                                cout << "Posicion fuera de rango o vacia, selecciona un disco valido antes de continuar..." << endl;
                            }

                        break;

                        case 'B':
                            cout << "Ingrese la posicion de origen (1 - " << num_discos << "): ";
                            cin >> posB;

                            topB = posB - 1;

                            if(posB > 0 && posB <= num_discos){
                                if(torre_hanoi[topB][torreB] != 0 && torre_hanoi[posB - 1][torreB] != 1){
                                    topB--;
                                }
                            }

                            if((posB > 0 && posB <= num_discos && torre_hanoi[posB - 1][torreB] != 0) && (torre_hanoi[topB][torreB] == 0 || torre_hanoi[posB - 1][torreB] == 1)){

                                cout << "Ingrese la torre de destino (A o C): ";
                                cin >> torre_destino;

                
                                switch (torre_destino){
                                    case 'A':

                                        cout << "Ingrese la posicion de destino (1 - " << num_discos << "): ";
                                        cin >> posA;

                                        if(posA > 0 && posA <= num_discos && torre_hanoi[posA - 1][torreA] == 0){

                                            while(torre_hanoi[discosA][torreA] != 0){
                                                discosA--;
                                            }

                                            if((discosA == num_discos - 1 || torre_hanoi[posB - 1][torreB] < torre_hanoi[posA][torreA]) && posA - 1 == discosA){
                                                torre_hanoi[discosA][torreA] = torre_hanoi[posB - 1][torreB];
                                                torre_hanoi[posB - 1][torreB] = 0;
                                                mov++;
                                            }
                                            else {
                                                cout << "Movimiento invalido, no puedes colocar un disco mas grande o posicion de destino incorrecta..." << endl;
                                            }
                                        }
                                        else {
                                            cout << "Posicion fuera de rango o posicion ocupada..." << endl;
                                        }

                                    break;
                                    case 'C':

                                        cout << "Ingrese la posicion de destino (1 - " << num_discos << "): ";
                                        cin >> posC;

                                        if(posC > 0 && posC <= num_discos && torre_hanoi[posC - 1][torreC] == 0){
                                      
                                            while(torre_hanoi[discosC][torreC] != 0){
                                                discosC--;
                                            }
                                
                                            if((discosC == num_discos - 1 || torre_hanoi[posB - 1][torreB] < torre_hanoi[posC][torreC]) && posC - 1 == discosC){
                                                torre_hanoi[discosC][torreC] = torre_hanoi[posB - 1][torreB];
                                                torre_hanoi[posB - 1][torreB] = 0;
                                                mov++;
                                            }
                                            else {
                                                cout << "Movimiento invalido, no puedes colocar un disco mas grande o posicion de destino incorrecta..." << endl;
                                            }
                                        }
                                        else {
                                            cout << "Posicion fuera de rango o posicion ocupada..." << endl;
                                        }

                                    break;
                                    default:
                                        cout << "Opcion invalida" << endl;
                                }
                            }
                            else {
                                cout << "Posicion fuera de rango o vacia, selecciona un disco valido antes de continuar..." << endl;
                            }

                        break;

                        case 'C':
                            cout << "Ingrese la posicion de origen (1 - " << num_discos << "): ";
                            cin >> posC;

                            topC = posC - 1;

                            if(posC > 0 && posC <= num_discos){
                                if(torre_hanoi[topC][torreC] != 0 && torre_hanoi[posC - 1][torreC] != 1){
                                    topC--;
                                }
                            }

                            if((posC > 0 && posC <= num_discos && torre_hanoi[posC - 1][torreC] != 0) && (torre_hanoi[topC][torreC] == 0 || torre_hanoi[posC - 1][torreC] == 1)){

                                cout << "Ingrese la torre de destino (A o B): ";
                                cin >> torre_destino;

                                switch (torre_destino){
                                    case 'A':

                                        cout << "Ingrese la posicion de destino (1 - " << num_discos << "): ";
                                        cin >> posA;

                                        if(posA > 0 && posA <= num_discos && torre_hanoi[posA - 1][torreA] == 0){

                                            while(torre_hanoi[discosA][torreA] != 0){
                                                discosA--;
                                            }
                                
                                            if((discosA == num_discos - 1 || torre_hanoi[posC - 1][torreC] < torre_hanoi[posA][torreA]) && posA - 1 == discosA){
                                                torre_hanoi[discosA][torreA] = torre_hanoi[posC - 1][torreC];
                                                torre_hanoi[posC - 1][torreC] = 0;
                                                mov++;
                                            }
                                            else {
                                                cout << "Movimiento invalido, no puedes colocar un disco mas grande o posicion de destino incorrecta..." << endl;
                                            }
                                        }
                                        else {
                                            cout << "Posicion fuera de rango o posicion ocupada..." << endl;
                                        }

                                    break;
                                    case 'B':

                                        cout << "Ingrese la posicion de destino (1 - " << num_discos << "): ";
                                        cin >> posB;
                                
                                        if(posB > 0 && posB <= num_discos && torre_hanoi[posB - 1][torreB] == 0){

                                            while(torre_hanoi[discosB][torreB] != 0){
                                                discosB--;
                                            }
                                
                                            if((discosB == num_discos - 1 || torre_hanoi[posC - 1][torreC] < torre_hanoi[posB][torreB]) && posB - 1 == discosB){
                                                torre_hanoi[discosB][torreB] = torre_hanoi[posC - 1][torreC];
                                                torre_hanoi[posC - 1][torreC] = 0;
                                                mov++;
                                            }
                                            else {
                                                cout << "Movimiento invalido, no puedes colocar un disco mas grande o posicion de destino incorrecta..." << endl;
                                            }
                                        }
                                        else {
                                            cout << "Posicion fuera de rango o posicion ocupada..." << endl;
                                        }

                                    break;
                                    default:
                                        cout << "Opcion invalida" << endl;
                                    }
                            }
                            else {
                                cout << "Posicion fuera de rango o vacia, selecciona un disco valido antes de continuar..." << endl;
                            }

                        break;
                        default:
                            cout << "Opcion invalida" << endl;
                    }

                    // Imprimir el estado actualizado del array
                    imprimir_torre(torre_hanoi, num_discos, filas);
                    cout << "Movimientos: " << mov << endl << endl;

                    if(torre_hanoi[0][torreC] != 0){

                        cout << "Felicidades has completado la torre de hanoi" << endl;
                        casoGanador(num_discos, 'A', 'C', 'B', movimientos);

                        if(mov == movimientos){
                            cout << "Solucion perfecta movimientos: " << movimientos << endl;
                            ciclo = false;
                            op_switch = '0';
                        }
                        else {
                            cout << "Haz completado la torre de hanoi pero puedes hacerlo en menos movimientos..." << endl;
                            ciclo = false;
                            op_switch = '0';
                        }
                    }
                }   // fin ciclo while
            }   // condicional para validar los discos ingresados
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

