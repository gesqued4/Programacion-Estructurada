#include <iostream>
using namespace std;
int espacios;
int i, j, aux;
int main(){

    cout << "Ingrese los espacios a usar: ";
    cin >> espacios;
    int ordenar[espacios];
    cout << "Ingresa el numero los numeros a ordenar" << endl;
    for(int i = 0; i < espacios; i++){          //guardar valores en el array
        cout << "Elemento " << i + 1 << ": ";
        cin >> ordenar[i];
    }
    //algoritmo del metodo burbuja
    for(i = 0; i < espacios; i++){
        for(j = 0; j < espacios; j++){
            if(ordenar[j] > ordenar[j + 1]){
                aux = ordenar[j];
                ordenar[j] = ordenar[j + 1];
                ordenar[j + 1] = aux;
            }
        }
    }   //fin del metodo burbuja
    cout << "Array ingresado: [";
    for(int i = 0; i < espacios; i++){          //guardar valores en el array
        cout << ordenar[i];
        if(i < espacios - 1){
            cout << ", ";
        }
    }
    cout << "]" << endl;



    return 0;
}