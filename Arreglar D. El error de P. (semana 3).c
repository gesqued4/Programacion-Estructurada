#include<stdio.h>
#include<math.h> 
int main(void){ 
double interval;
int i;

printf("\n----------------------\n");

for(i = 0; i < 10; i++){    // ciclo for para imprimir el seno de el intervalo entre 0 y 1
 interval = i/10.0;
 printf("sin( %lf ) = %lf \n", interval, sin(interval));
}

printf("\n----------------------\n");

for(i = 0; i < 10; i++){    // ciclo for para imprimir el coseno de el intervalo entre 0 y 1
 interval = i/10.0;
 printf("cos( %lf ) = %lf \n", interval, cos(interval));
}

printf("\n----------------------\n");
return 0;
}