/*Gerardo Esqueda Padilla*/
//inlcuyo la libreria stdio
#include <stdio.h>                                                                    
using namespace std;
//declaro mis variables globales
int num;
//funcion principal
int main() {
    printf("Ingrese el numero que desea imprimir las tablas de multiplicar: ");     //imprimo las instrucciones al usuario
    scanf("%d", &num);                                                              //entrada de datos
//ciclo for para imprimir las tablas de multiplicar de la variable num 
    for(int i = num; i <= num*10; i = i + num){                     
        printf("%d ", i);
    }

    return 0;
}
