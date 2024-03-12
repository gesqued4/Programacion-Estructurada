/* Biblioteca de Funciones
Actividad de Programación 10
Gerardo Esqueda Padilla*/

void matriz_resultado(int matrizRes[][15], int size);
// Funcion para imprimir el menu de opciones
void menu_option(){
        cout << "\n\n\nSeleccione una opcion:\n"; // impresion de menu de opciones
        cout << "\n1. Ingresar valores \n2. LLenado numeros random\n3. Listar valores";
        cout << "\n4. Borrar elementos\n5. Editar elementos";
        cout << "\n6. Vaciar matriz\n7. Operaciones\n8. Salir\n\n";
}

// Funcion para ingresar valores
void ingresar_valores(int matriz[][15], int size){

        int i = 0, j = 0;

            while (i < size){ // ciclo while para ingresar valores en la matriz
                cout << "\nPosicion Matriz [" << i << "] [" << j << "]\nIngrese un numero: ";
                cin >> matriz[i][j];

                j++;

                if (j == size){
                    i++;
                    j = 0;
                }
    
            } // fin while

            if (i >= size){
                cout << "\nMatriz llena, vacie la matriz para continuar..." << endl;
            }
            
}

// Funciones valores aleatorios
void valores_aleatorios(int matriz[][15], int size, int seed){

            // Inicializar la semilla para la función rand() utilizando el tiempo actual
            srand(seed);

            // Llenar la matriz con valores aleatorios en el rango de -200 a 400
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    matriz[i][j] = rand() % 601 - 200; // Generar números aleatorios en el rango de -200 a 400
                }
            }

}

// Funcion para listar valores
void listar_valores(int matriz[][15], int size) {
    if (size >= 2 && size <= 15) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << "[" << matriz[i][j] << "]" << "\t";
                    }
                cout << "\n";
            }
    } else {
        cout << "\nMatriz vacia, ingrese valores para continuar...";
    }
}

// Funcion para borrar valores
void borrar_valores(int matriz[][15], int size){
    int i = 0, j = 0;

    if (size == 0){
        cout << "\nMatriz vacia";
    } else{
        cout << "\nIngrese la fila del elemento que desea borrar: ";
        cin >> i;

        cout << "Ingrese la columna del elemento que desea borrar: ";
        cin >> j;
    }

    if ((i >= 0 && i < size) && (j >= 0 && j < size)){
                matriz[i][j] = 0;
                cout << "Se ha eliminado el valor en la coordenada [" << i << "] [" << j << "]";
            }
            else{
                cout << " o posicion fuera de rango, ingrese valores para continuar...";
            }
    
}

// Funcion para editar valores
void editar_valores(int matriz[][15], int size){
    int i = 0, j = 0;

            if (size == 0){
                cout << "\nMatriz vacia";
            }
            else{
                cout << "\nIngrese la fila del elemento que desea editar: ";
                cin >> i;

                cout << "Ingrese la columna del elemento que desea editar: ";
                cin >> j;
            }

            if ((i >= 0 && i < size) && (j >= 0 && j < size)){
                cout << "Ingrese el nuevo valor de la matriz: ";
                cin >> matriz[i][j];
                cout << "Se ha editado el valor en la coordenada [" << i << "] [" << j << "]";
            }
            else{
                cout << " o posicion fuera de rango, ingrese valores para continuar...";
            }
}

// Funcion para vaciar matrices
void vaciar_matriz(int matriz[][15], int size){
    if (size == 0){
        cout << "\nLa matriz ya esta vacia...";
    } else {
        for (int i = 0; i < size; i++){ // ciclo for para recorrer los indices e igualarlos a 0 
            for (int j = 0; j < size; j++){
                matriz[i][j] = 0;
                    }
                }
            cout << "\nLos elementos de la matriz han sido eliminados con exito...";
        }

}

// Función para sumar dos matrices
void suma_matriz(int matrizA[][15], int matrizB[][15], int matrizRes[][15], int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrizRes[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
    matriz_resultado(matrizRes, size);             
}

// Función para restar dos matrices
void resta_matriz(int matrizA[][15], int matrizB[][15], int matrizRes[][15], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrizRes[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
    matriz_resultado(matrizRes, size);
}

// Función para multiplicar dos matrices
void multi_matriz(int matrizA[][15], int matrizB[][15], int matrizRes[][15], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrizRes[i][j] = 0;
            for (int k = 0; k < size; k++) {
                matrizRes[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    matriz_resultado(matrizRes, size);
}

// Funcion para dividir matrices
void dividir_matriz(int matrizA[][15], int matrizB[][15], double matrizRes[][15], int size) {

    bool inverso = true;
    for (int i = 0; i < size; i++) {
        if (matrizB[i][i] == 0) {
            inverso = false;
            break;
        }
    }

    if (!inverso) {
        cout << "La matriz B no es inverso. La división no es posible." << endl;
        return;
    }

    // Calcular la inversa de la matriz B
    int inverso_matrizB[15][15]; // Usamos double para permitir fracciones en los resultados
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                inverso_matrizB[i][j] = 1.0 / matrizB[i][j]; // Invertir los elementos de la diagonal principal
			}
            else {
                inverso_matrizB[i][j] = 0; // Los elementos fuera de la diagonal principal se mantienen como cero
             }
            }
        }
    // Multiplicar la matriz A por la inversa de la matriz B
    multi_matriz(matrizA, inverso_matrizB, matrizRes, size);

	matriz_resultado(matrizRes, size);
}

// Funcion para imprimir matriz resultado operacion
void matriz_resultado(int matrizRes[][15], int size){
    cout << "\n\nEl resultado de sumar estas matrices es:\n";
        for (int i = 0; i < size; i++){ // ciclo for para imprimir la matriz suma
            for (int j = 0; j < size; j++){
                cout << "[" << matrizRes[i][j] << "]"<< "\t";
                        }
                cout << "\n";
                    }
}

