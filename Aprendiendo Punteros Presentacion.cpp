#include <iostream>
using namespace std;

int main() {








// Direccion de memoria
int num;
int *punt;
punt = &num;
cout << "\n\nLa direccion de memoria de la variable W es: " << punt << endl;








// Desreferenciacion
float *p;
float n = 1.44;
p = &n;
cout << "\n\nEl numero contenido en la posicion apuntada es: " << *p << endl;







// Incremento y Decremento                Navegacion entre arrays
long long array[] = {10, 20, 30, 40, 50};
long long *ptr = &array[0]; // Asignamos al puntero la dirección del primer elemento del array

cout << "\n\nRecorriendo el array:\n" << endl;
for (int i = 0; i < 5; i++) {
    cout << "Direccion de memoria: " << ptr << endl; // Imprime la direccion de memoria del array 
    cout << "Valor contenido: " << *ptr << endl; // Imprime el valor al que apunta ptr
    ptr++; // Avanza al siguiente elemento del array
}

// 6422224 6422228 6422232 tipo int
// 6422200 6422208 6422216 tipo long long

// Otra manera de hacer el incremento y decremento 
long long *pter = &array[0]; 

cout << "\n\n" << *(pter + 0) << endl; // primer numero
cout << *(pter + 1) << endl; // segundo numero
cout << *(pter + 2) << endl; // tercer numero
cout << *(pter + 3) << endl; // cuarto numero
cout << *(pter + 4) << endl; // quinto numero







//Diferencia de Punteros
/*int *ptr1 = &array[0]; // Primer puntero apunta al primer elemento
int *ptr2 = &array[3]; // Segundo puntero apunta al cuarto elemento

    // Calculamos la diferencia entre los punteros
int diferencia = ptr2 - ptr1;

cout << "\n\nLa diferencia entre los punteros es: " << diferencia;*/







    return 0;
}