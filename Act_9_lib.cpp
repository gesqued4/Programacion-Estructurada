/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 04 de Marzo de 2024
        PROGRAMA: Act_9_lib.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION:
            Utilizando Librerias de Funciones
            Inserción de valores por parte del usuario (arreglos o vectores)
            Pueden ser textuales o numéricos
            Borrado y edición de elementos
            Vaciado de conjuntos
            Operaciones de Unión, Intersección, Diferencia y complemento.
**************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void ingresar_conjunto(vector<string> &conjunto, const vector<string> &universo);
void listar_conjuntos(const vector<string> &universo, const vector<string> &conjunto_uno, const vector<string> &conjunto_dos);
void borrar_elemento(vector<string> &conjunto);
void editar_elemento(vector<string> &conjunto);
void vaciar_conjunto(vector<string> &conjunto);
void realizar_operaciones(const vector<string> &conjunto_uno, const vector<string> &conjunto_dos);
void finalizar_ejecucion(bool &op_ciclo);

// funcion para imprimir menu de opciones
void print_menu() {   
    cout << "\n\nSeleccione una opcion:\n"; 
    cout << "\n1. Ingresar valores primer conjunto\n2. Ingresar valores segunda conjunto\n3. Listar valores\n4. Borrar valores primer conjunto";
    cout << "\n5. Borrar valores segundo conjunto\n6. Editar primer conjunto\n7. Editar segundo conjunto\n8. Vaciar primer conjunto";
    cout << "\n9. Vaciar segundo conjunto\n10. Operaciones\n11. Salir\n\n";
}

// funcion para listar conjuntos
void listar_conjuntos(const vector<string> &universo, const vector<string> &conjunto_uno, const vector<string> &conjunto_dos) {
    cout << "\nUniverso:\n";
    for (const auto &elem : universo) {
        cout << "[" << elem << "] ";
    }
    cout << "\n\nPrimer Conjunto:\n";
    for (const auto &elem : conjunto_uno) {
        cout << "[" << elem << "] ";
    }
    cout << "\n\nSegundo Conjunto:\n";
    for (const auto &elem : conjunto_dos) {
        cout << "[" << elem << "] ";
    }
}

// funcion para ingresar valores 
void ingresar_conjunto(vector<string> &conjunto, const vector<string> &universo) {
    int size_conjunto;
    cout << "\nDefina el tamano del conjunto: ";
    cin >> size_conjunto;

    cout << "Ingrese los elementos del conjunto:\n";
    for (int i = 0; i < size_conjunto; ++i) {
        string elementos_conjunto;
        cin >> elementos_conjunto;

        bool is_valid = true; // Bandera para verificar si el elemento es válido
    
        // Verificar si el elemento contiene caracteres especiales
        for (char c : elementos_conjunto) {
            if (!isalnum(c)) {
                cout << "El valor contiene simbolos. Ingrese solo caracteres alfanumericos." << endl;
                is_valid = false;
                break;
            }
        }

        if (!is_valid) // Si el elemento no es válido, continuar con el siguiente ingreso
            continue;

        // Verificar si el elemento ya está en el conjunto
        if (find(conjunto.begin(), conjunto.end(), elementos_conjunto) != conjunto.end()) {
            cout << "El valor ya esta en el conjunto." << endl;
        }
        // Verificar si el elemento está en el universo
        else if (find(universo.begin(), universo.end(), elementos_conjunto) != universo.end()) {
            conjunto.push_back(elementos_conjunto);
        }
        else {
            cout << "El valor no es valido en el universo." << endl;
        }
    }

}

// funcion para borrar valores
void borrar_elemento(vector<string> &conjunto) {
    int i = 0;
    cout << "\nIngrese la posicion del elemento que desea borrar (0 - " << conjunto.size() - 1 << "): ";
    cin >> i;

    conjunto.erase(conjunto.begin() + i);
    cout << "Se ha eliminado el valor en la posicion no. " << i;
}

// funcion para editar valores
void editar_elemento(vector<string> &conjunto) {
    int i = 0;
    string nuevo_valor;
    cout << "\nIngrese la posicion del elemento que desea editar: ";
    cin >> i;

    cout << "Ingrese el nuevo valor en el conjunto: ";
    cin >> nuevo_valor;

    conjunto[i] = nuevo_valor;
    cout << "\nEl elemento ha sido modificado con exito...";
}

//funcion para vaciar conjuntos
void vaciar_conjunto(vector<string> &conjunto) {
    char op_vaciar;
    cout << "\nEsta seguro de querer vaciar el conjunto? Esta operacion eliminara todos los elementos contenidos en el conjunto. ";
    cout << "Por favor, confirme su decisión. S/N\n\n";
    cin >> op_vaciar;

    if (op_vaciar == 'S' || op_vaciar == 's') {
        conjunto.clear();
        cout << "\nLos elementos del conjunto han sido eliminados con éxito...";
    } else {
        cout << "\nOpción incorrecta, seleccione una opción válida...";
    }
}

//funcion para realizar operaciones
void realizar_operaciones(const vector<string> &conjunto_uno, const vector<string> &conjunto_dos) {
    int op_operaciones;
    cout << "\nMenu operaciones\nElija una opción:\n1. Unión\n2. Intersección\n3. Diferencia\n4. Complemento\n\n";
    cin >> op_operaciones;

    switch (op_operaciones) {
        case 1: {
            vector<string> conjunto_union = conjunto_uno;
            for (const auto &elem : conjunto_dos) {
                if (find(conjunto_uno.begin(), conjunto_uno.end(), elem) == conjunto_uno.end()) {
                    conjunto_union.push_back(elem);
                }
            }
            cout << "\nUnión de conjuntos: ";
            for (const auto &elem : conjunto_union) {
                cout << "[" << elem << "] ";
            }
            break;
        }
        case 2: {
            vector<string> conjunto_interseccion;
            for (const auto &elem : conjunto_uno) {
                if (find(conjunto_dos.begin(), conjunto_dos.end(), elem) != conjunto_dos.end()) {
                    conjunto_interseccion.push_back(elem);
                }
            }
            cout << "\nIntersección de conjuntos: ";
            for (const auto &elem : conjunto_interseccion) {
                cout << "[" << elem << "] ";
            }
            break;
        }
        case 3: {
            vector<string> conjunto_diferencia;
            for (const auto &elem : conjunto_uno) {
                if (find(conjunto_dos.begin(), conjunto_dos.end(), elem) == conjunto_dos.end()) {
                    conjunto_diferencia.push_back(elem);
                }
            }
            cout << "\nDiferencia de conjuntos (conjunto_uno - conjunto_dos): ";
            for (const auto &elem : conjunto_diferencia) {
                cout << "[" << elem << "] ";
            }
            break;
        }
        case 4: {
            vector<string> conjunto_complemento;
            for (const auto &elem : conjunto_uno) {
                if (find(conjunto_dos.begin(), conjunto_dos.end(), elem) == conjunto_dos.end()) {
                    conjunto_complemento.push_back(elem);
                }
            }
            cout << "\nComplemento del conjunto uno respecto al conjunto dos: ";
            for (const auto &elem : conjunto_complemento) {
                cout << "[" << elem << "] ";
            }
            break;
        }
        default:
            cout << "\nOpción incorrecta, seleccione una opción válida...";
    }
}

// funcion para terminar el programa
void finalizar_ejecucion(bool &op_ciclo) {
    char op_salir;
    cout << "\n\nDesea finalizar la ejecucion del programa. Por favor, confirme su decision. S/N\n\n";
    cin >> op_salir;
    if (op_salir == 'S' || op_salir == 's') {
        op_ciclo = false;
    } else {
        cout << "\nVolviendo al menu principal...";
    }
}