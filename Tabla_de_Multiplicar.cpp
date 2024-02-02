#include <stdio.h>
using namespace std;

int num;

int main() {
    printf("Ingrese el numero que desea imprimir las tablas de multiplicar: ");
    scanf("%d", &num);

    for(int i = num; i <= num*10; i = i + num){
        printf("%d ", i);
    }

    return 0;
}
