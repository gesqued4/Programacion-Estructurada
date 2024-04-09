#include <iostream>
using namespace std;

int main () {

int a;
int *b;

cin >> a;
b = &a;
cout << "El valor de a es: " << a << endl << endl;
cout << "El valor almacenado en b es: " << b << endl;
cout << "La posicion de B es: " << &b << endl;
cout << "El valor almacenado en b es: " << *b << endl;

    return 0;
}