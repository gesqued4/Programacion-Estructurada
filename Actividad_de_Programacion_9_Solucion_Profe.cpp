#include <iostream>
#include <vector>
using namespace std;
#include "Act_9_profe_lib.cpp"

int main() {
    vector<char> conjunto_a, conjunto_b, conjunto_res;
    char op;
    bool ciclo_while = true;
    
    while(ciclo_while){
        println("1. Inserta valor");
        println("2. Imprime Conjunto");
        println("3. Salir");
        println("Seleccione una opcion: ");
        cin >> op;

        switch(op){
            case 1:{
                char val1;
                char opt;
                println("Ingresa un valor");
                cin >> val1;
                if(valida(val1) == 1){
                    println("En cual conjunto desea guardarlo A o B");
                    cin >> opt;                             // No funciona esta linea no lee la variable opt

                    if(opt == 'A'){
                        insert(conjunto_a, val1);
                    } 
                    else if(opt == 'B'){
                        insert(conjunto_b, val1);
                    }   
                    else {
                        println("No existe");
                    }
                }
                else {
                    println("Caracter no valido");
                }
            break;
            } //fin case 1
            case 2:{
                print_vector(conjunto_a);
                print_vector(conjunto_b);
                break;
            } //fin case 2
            case 3:{
                ciclo_while = false;
            } //fin case 3
            default:{
                println("No existe esa opcion");
            }




        } //fin switch
    } //fin while
    return 0;
}