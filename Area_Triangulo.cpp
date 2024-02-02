#include <stdio.h>
using namespace std;
    float base, altura, area;
        int main (){
            printf("Calculadora Area Triangulo\nIngrese la base del triangulo: ");
            scanf("%f", &base);
            printf("Ingrese la altura del triangulo: ");
            scanf("%f", &altura);
            
            area = (base * altura) / 2;

            printf("El area de su triangulo es: %.2f", area);

        return 0;
    }