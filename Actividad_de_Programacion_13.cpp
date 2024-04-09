/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 09 de Abril de 2024
        PROGRAMA: Actividad_de_Programacion_13.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: 
        Pedir al usuario una palabra o frase
        Debe contar el número de vocales, consonantes y espacios
        Debe determinar si es una palabra palíndromo 
        Convertir palabra o frase a Mayúsculas y minúsculas
        Solicitar otra palabra o frase y que se concatene con la anterior
**************************************************************/
#include <iostream>
using namespace std;
#include "Act_13_lib.cpp"
#include <cctype>

int main (){
    string palabra, frase;
    char conv_palabra;
    int vocales = 0, consonantes = 0, espacios = 0;
 
        cout << "Ingrese una palabra sin acentos: ";
        getline(cin, palabra);
        contar_vocales_consonantes(palabra, vocales, consonantes, espacios);
        cout << "Vocales: " << vocales << endl;
        cout << "Consonantes: "<< consonantes <<  endl;
        cout << "Espacios: " << espacios << endl;
        // Imprime el resultado
        if (palindromo(palabra)) {
            cout << "Palindromo: Si" << endl;
        } else {
            cout << "Palindromo: No" << endl;
        }
        cout << "\t1. Convertir a mayusculas\n\t2. Convertir a minusculas" << endl;
        cin >> conv_palabra;

        switch(conv_palabra){
            case '1': 
                for (char &letra : palabra) {
                    letra = toupper(letra); // Convertir el carácter a mayúsculas
                }
                cout << "En mayusculas: " << palabra << endl;
            break;
            case '2': 
                for (char &letra : palabra) {
                    letra = tolower(letra); // Convertir el carácter a minúsculas
                }
                cout << "En minusculas: " << palabra << endl;
            break;
            default:
                cout << "Opcion incorrecta";
        }

        cin.ignore();
        cout << "Ingrese otra palabra: ";
        getline(cin, frase);

        cout << "Frase concatenada: " << palabra << " " << frase;

    return 0;
}