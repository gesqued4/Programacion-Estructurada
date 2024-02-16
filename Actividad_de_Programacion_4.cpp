/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 02 de Febrero de 2024
        PROGRAMA: Actividad_de_Programacion_4.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: 
**************************************************************/

#include <stdio.h>              //libreria de entrada y salida de datos
int main (){                    //funcion main
    bool ciclo = true, ciclo_while, ciclo_dowhile;        //variables
    int numend, option, numfib_1, numfib_2, i;
    char op_ciclo;                                      

    printf("\t\t\t\t\t\t\tSerie Fibonacci");
    //inicio ciclo while para repetir programa
    while(ciclo){                                                   
    printf("\nIngrese un numero en el que desea que finalice la serie fibonacci: ");
    scanf("%d", &numend);
    printf("Eliga un ciclo:\n\t\t1. For\n\t\t2. While\n\t\t3. Do while\n|_______|\b\b\b\b\b");
    scanf("%d", &option);  

    i = 0;                             //valores iniciales de la serie fibonacci
    numfib_1 = 0;
    numfib_2 = 1;

    switch (option){                            //switch de opciones
        case 1:                                 //case 1: ciclo for
            for(i = 0; i <= numend; i = numfib_1 + numfib_2){               //inicio for
                printf("%d ", i);
                numfib_1 = numfib_2;
                numfib_2 = i;
            }                                                              //fin ciclo for
            break;
        case 2:                                 //case 2: ciclo while
            ciclo_while = true;                 
            while (ciclo_while) {               //inicio while
                printf("%d ", i);
                numfib_1 = numfib_2;
                numfib_2 = i;
                i = numfib_1 + numfib_2;
                if (i > numend) {               //condicional if para terminar ciclo while
                ciclo_while = false;
                }
            }                                   //fin ciclo while
            break;
        case 3:                                          //case 3: ciclo do while
            do {                                         //inicio do while                
                printf("%d ", i);   
                numfib_1 = numfib_2;
                numfib_2 = i;
                i = numfib_1 + numfib_2;
                if (i <= numend) {                      //condicional if para bucle do while
                ciclo_dowhile = true;
                } 
                else {ciclo_dowhile = false;}           //condicional para terminar ciclo do while
            }while(ciclo_dowhile);                      //fin ciclo do while
            break;
        default:                                        //default
            printf("Opcion invalida, intentelo de nuevo");
    }                                                   //fin del switch
    fflush stdin;                                       //fflush para limpiar la basura de stdin
    printf("\n\t\t\t\t\t\tpress \"E\" for exit or press any key to continue\n|_______|\b\b\b\b\b");
    scanf("%c", &op_ciclo);

    if(op_ciclo == 'E' || op_ciclo == 'e'){             //condicional if para terminar el programa
        ciclo = false;
    }
    }                                               
    //fin ciclo while
    return 0;      
}                   //fin del main