#include <stdio.h>
using namespace std;
    float num1, num2;
        int main () {
            printf("What number is bigger?\nIngrese un numero: ");
            scanf("%f", &num1);
            printf("Ingrese otro numero: ");
            scanf("%f", &num2);

            if (num1 > num2) {
                printf("%.1f es mayor", num1);
            }
            else if (num1 == num2) {
                printf("%.1f y %.1f son iguales", num1 , num2);
            }
            else {
                printf("%.1f es mayor", num2);
            }
            return 0;
        }