/**************Gerardo Esqueda Padilla****************
******************Practica Condicional If*******************/
#include <stdio.h>      //libreria standar de entrada y salida de datos
int num;                //declaro variables globales
int main() {            //funcion principal
    printf("Ingrese un numero entero: ");           //imprimo instrucciones al usuario
    scanf("%d", &num);                              //entrada de datos
/*Ciclo for para que la variable ingresada aumente de acuerdo al dato ingresado*/
    for(int i = num; i <= num*10; i = i + num){     
    if(i==num*10){                                      //condicional if para imprimir solo el dato final
        printf("Valor final ciclo for: %d", i);
    }
    }

    if(num % 2 == 0){                                   //condicional if para saber si el dato de entrada es par
        printf("El numero que ingreso es par");
    }
    else {                                              //o por lo contrario es impar
        printf("El numero que ingreso no es par");
    }

    return 0;
}