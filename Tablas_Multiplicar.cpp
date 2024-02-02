/**************Gerardo Esqueda Padilla****************
******************Practica Ciclo For*******************/
#include <stdio.h>
using namespace std;
int main() {
    printf("Tablas de Multiplicar\n");
    for(int i = 1; i <= 10; i++){
        printf("\n");
                for(int j = 1; j <= 10; j++){
                    int tablas = i*j;
                    printf("%d ", tablas);
                }
     }
    return 0;
}