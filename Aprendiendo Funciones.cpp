#include <iostream>
using namespace std;
#include "Aprendiendo_Librerias_Funciones.cpp"

//declaracion de funcinones para que identifique que existe una funcion mas abajo
void hello();

int main() {
    hello(); // Llamada a la función hello
    imp("Mi nombre es:");
    imp("Gerardo Esqueda Padilla");
    imp(19);
    imp(12.41);
    imp(suma(15, 35));
    imp(suma(15.4, 35.3));
    cout << valida('@') << endl;
    cout << booltotxt ( valida('q'));
    goodbye();// Llamasa a la funcion goodbye
    return 0;
} //fin del main

//definicion de funcinoes

//funcion saludo inicial
void hello() {
    cout << "Welcome to my first lib program" << endl;
    cout << "\tVersion 1.0" << endl;
    cout << "********************************" << endl;
} // fin de hello