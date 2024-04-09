#include <iostream>
using namespace std;

int main (){
    int tam, i;
    int *b = new int (tam);
    cout << "Que tamano deseas que el puntero tenga" << endl;
    cin >> tam;

    for (i = 0; i < tam; i ++){
        b[i] = i;
        cout << b[i] << endl;
    }

    delete [] b;

    return 0;
}