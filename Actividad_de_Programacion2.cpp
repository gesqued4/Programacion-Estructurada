/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 26 de Enero de 2024
        PROGRAMA: Actividad_de_Programacion2.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: Imprimiendo Secuencias de Escape y Cadenas de Control de Tipo
**************************************************************/
/*Caracteres de Secuencia de Escape en este programa: \n \b \t \r \f \"
  Cadenas de Control de Tipo de Salida: %d %.2f %s %e %u %i*/

#include <stdio.h>                  //libreria de entrada y salida de datos
using namespace std;

char name[50];                     //array de una dimension para almacenar cadena de texto
int age, back_or_exit;              //declaro mis variables globales
float transfer, saldo_restante;
unsigned int option = 0;
int main (){                        //funcion principal
    printf("\t\t\t\t\tBanco de Mexico\nBuenas tardes, ingrese su nombre: ");            //imprimo instrucciones al usuario
    fgets(name, 50, stdin);                                                             //funcion fgets para almacenar cadena de caracteres
/*bucle do while para repetir la ejecucion del programa si asi el usuario lo desea*/
do {                                                                           
    printf("Bienvenido Sr/a %s\nQue desea realizar el dia de hoy?"                      //imprimo instrucciones al usuario
    "\n\t1. Consultar Saldo\n\t2. Transferir saldo\n\t3. Salir\n\n", name);
    printf("|_______|\b\b\b\b\b");                                             
    fflush stdin;                                                                       //fflush para limpiar el buffer de entrada
    scanf("%u", &option);
    printf("\n");

     switch(option){                                                                    //switch de opciones que puede elegir y realizar el usuario         
            case 1:                                                                     //case 1: Consultar saldo
                printf("Su saldo es $5'345,425.00 mxn\f\r\t\t\t\t\tVolver = \"1\" Salir = \"0\"\n");
                printf("|_______|\b\b\b\b\b");
                scanf("%d", &back_or_exit);                                     //back_or_exit variable para volver o salir en el bucle do while
                printf("\n");
                break;
            case 2:                                                                     //case 2: Transferir dinero
                printf("Ingrese la cantidad a transferir: $_____________\b\b\b\b\b\b\b\b\b\b\b\b\b");
                scanf("%f", &transfer);
                saldo_restante = 5345425.00 - transfer;
                printf("Su saldo restante es : $%.2f O en notacion cientifica $%e\f\r\t\t\t\t\tVolver = \"1\" Salir = \"0\"\n", saldo_restante, saldo_restante);
                printf("|_______|\b\b\b\b\b");
                scanf("%d", &back_or_exit);
                printf("\n");
                break;
            case 3:                                                                     //case 3: Salir
                printf("Gracias por su visita, vuelva pronto!\f\r\t\t\t\t\tVolver = \"1\" Salir = \"0\"\n");
                printf("|_______|\b\b\b\b\b");
                scanf("%d", &back_or_exit);
                printf("\n");
                break;
            default:                                                                    //default: Dato Erroneo
                printf("Dato erroneo\f\r\t\t\t\t\tVolver = \"1\" Salir = \"0\"\n");
                printf("|_______|\b\b\b\b\b");
                scanf("%d", &back_or_exit);
                printf("\n");
    }
} while (back_or_exit > 0 && back_or_exit == 1);                                        //condicion del bucle
    
    
    return 0;                                                                           //fin funcion main

}