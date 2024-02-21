/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 02 de Febrero de 2024
        PROGRAMA: Actividad_de_Programacion_3.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: 
**************************************************************/

#include <stdio.h>               //libreria de entrada y salida de datos
int main () {                    //funcion main
bool ciclo = true;              //variables
int num, res;
char option;
//ciclo do while para repetir ejecucion del programa
do{                          
    printf("Ingrese un valor: ");       //imprimo instrucciones al usuario
    scanf("%d", &num);
        if (num>0 && num<=500){                             //validar numero
            int veces = 100, sum = 5;
                    for(int i = 1; i <= veces; i++){        //ciclo for 
                    res = num += sum;
                    printf("No. %d: %d\n", i, res);
                }
            }
        else if (num>500 && num<=1000){                     //validar numero
            int veces = 50, sum = 10;
                    for(int i = 1; i <= veces; i++){        //ciclo for
                    res = num += sum;
                    printf("No. %d: %d\n", i, res);
                }
        }
        else if (num < 0 || num>1000){                      //validar numero
            printf("No se puede calcular");
        }
        fflush(stdin);                                       //fflush para limpiar la basura de stdin
        printf("\t\t\t\t\t\t\t\t\t\tpress 'E' for exit or press any key to continue\n |_______|\b\b\b\b\b");
        scanf ("%c", &option);
        printf("\n");
        //condicion para terminar el programa
        if (option == 'E' || option == 'e'){
            ciclo = false;
        }
} while (ciclo);    //fin del ciclo do while
}                   //fin funcion main