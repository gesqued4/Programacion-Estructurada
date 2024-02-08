#include <stdio.h>
int main (){
    //declarar variables locales
    bool ciclo = true;
    int numuser, veces, suma;
    char op;


    //iniciar ciclo retorno de programa
    while(ciclo){
        printf("Escribe un numero: ");
        scanf("%d", &numuser);
        //validar numero
        if(numuser < 0 || numuser > 1000){
            printf("No se puede calcular el valor");
        }
        else if(numuser > 0  && numuser <= 500){
            veces = 100;
            suma = 5;
        } else {
            veces = 50;
            suma = 10;
        }
    //inicio de for
    for(int i = 1; i <= veces; i++){
        int res;
        res = numuser += suma;
        printf("La vez: %d es de: %d\n", i, res);
    }

    printf("Termine el ciclo, \"S\" para salir o cualquier otra tecla para continuar");
    scanf ("%c", op);
    //condicion para terminar programa
    if (op == 'S' || op == 's'){
        ciclo = false;
    }

    }       //fin del ciclo while del retorno del programa
}           //fin de main