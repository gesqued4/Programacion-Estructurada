/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 22 de Marzo de 2024
        PROGRAMA: Aprendiendo Recursividad.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: Aprendiendo Recursividad
**************************************************************/
#include <iostream>
using namespace std;

// Funcion para calcular el factorial de un numero
int factorial (int n){
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1);
}
// Funcion para calcular la serie de fibonacci
int fibonacci (int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else 
        return fibonacci(n - 1) + fibonacci (n - 2);
}
// Funcion para imprimir el abecedario al reves
void abecedario_invertido (char letraactual){
    if (letraactual <= 'z'){
        abecedario_invertido (letraactual + 1);
        cout << letraactual << " ";
    }
    return;
}
// Funcion para calcular el Maximo Comun Divisor
int calculomcd (int a, int b){
    if (b == 0){
        return a;
    }

    return calculomcd (b, a % b);
}

int main (){
char op_switch;

    cout << "Seleccione una opcion:\n1. Factorial de un numero\n2. Serie de Fibonacci\n3. Abecedario\n4. Maximo Comun Divisor" << endl;
    cin >> op_switch;

switch (op_switch){

    case '1':    // case 1: Factorial de un numero
        int num;
        cout << "Ingrese un numero para calcular su factorial: ";
        cin >> num;

        if (num < 0) {
            cout << "No se puede calcular el facturial de un numero negativo..." << endl;
        }
        else {
            cout << "El factorial de " << num << " es: " << factorial(num) << endl;
        }
    break;      // fin case 1

    case '2':   // case 2: Serie de fibonacci
        int n;
        cout << "Ingrese el numero de terminos de la serie de fibonacci: ";
        cin >> n;
        cout << "Serie de Fibonacci de " << n << " terminos:" << endl;
        for (int i = 0; i < n; i++){
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    break;      // fin case 2

    case '3':   // case 3: Abecedario Invertido
        char inicio = 'a';
        abecedario_invertido (inicio);
    break;      // fin case 3 

   case '4':       // case 4: MCD
        int num1, num2;
        cout << "Ingrese el primer numero: ";
        cin >> num1;
        cout << "Ingrese el segundo numero: ";
        cin >> num2;

        int mcd = calculomcd (num1, num2);

        cout << "El maximo comun divisor (MCD) de " << num1 << " y " << num2 << " es: " << mcd << endl;
    break;      // fin case 4 


    }   // fin switch
    return 0;
}