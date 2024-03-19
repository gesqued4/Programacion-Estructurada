// Función para validar si un carácter es un dígito numérico del 0 al 9
bool valida(char caracter) {
    return (caracter >= '0' && caracter <= '9');
}

// Función para verificar si un valor ya existe en el arreglo
bool valor_existente(int *array, int tamano, int valor, int i) {
    for (int j = 0; j < i; ++j) {
        if (*(array + j) == valor) {
            return true; // El valor ya existe en el arreglo
        }
    }
    return false; // El valor no existe en el arreglo
}

// Funcion para ingresar valores
void ingresar_valores(int *array, int tamano, int &i) {
    if (i < tamano) {
        char entrada[100]; // Arreglo para almacenar la entrada del usuario
        cout << "\nIngresar un valor: ";
        cin >> entrada; // Leer la entrada del usuario

        // Validar que la entrada sea un número
        bool es_valido = true;
        for (int j = 0; entrada[j] != '\0'; ++j) {
            if (!valida(entrada[j])) {
                es_valido = false;
                break;
            }
        }

        // Si la entrada es un número válido, convertirlo a entero y almacenarlo en el arreglo
        if (es_valido) {
            int valor = atoi(entrada); // Convertir la entrada a entero
            if (!valor_existente(array, tamano, valor, i)) {
                *(array + i) = valor; // Almacenar el valor en el arreglo
                i++; // Incrementar la posición
            } else {
                cout << "El valor ya existe en el arreglo." << endl;
            }
        } else {
            cout << "Entrada invalida. Se esperaba un numero." << endl;
        }
    } else {
        cout << "Arreglo lleno..." << endl;
    }
}

// Función para ordenar el arreglo de menor a mayor
void ordenar_arreglo(int *array, int tamano) {
    for (int i = 0; i < tamano - 1; ++i) {
        for (int j = 0; j < tamano - i - 1; ++j) {
            if (*(array + j) > *(array + j + 1)) {
                // Intercambiar elementos si están en el orden incorrecto
                int temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}

// Funcion para listar valores
void listar_arreglo(int *array, int tamano){
    for (int i = 0; i < tamano; ++i) {
            cout << "[" << *(array + i) << "] "; // Muestra los valores del arreglo
    }
    cout << endl;
}