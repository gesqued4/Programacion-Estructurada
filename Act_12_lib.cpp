// Función para imprimir el estado actual de la torre de Hanoi
void imprimir_torre (int **torre_hanoi, int num_discos, int filas){
    cout << endl;
    for(int i = 0; i < num_discos; i++){        //Imprimir el array
        for(int j = 0; j < filas; j++){
            cout << torre_hanoi[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "_________________" << endl;
    cout << "A\tB\tC" << endl;
    cout << endl;
    
}

// Función para mover un disco de una columna a otra
void mover_disco(int **torre_hanoi, int num_discos, int columna_origen, int columna_destino) {
    // Encontrar la última posición vacía en la columna de destino
    int fila_destino = 0;
    while (fila_destino < num_discos && torre_hanoi[columna_destino][fila_destino] != 0) {
        fila_destino++;
    }

    if (fila_destino < num_discos) {
        // Mover el disco desde la parte superior de la columna de origen a la última posición vacía de la columna de destino
        torre_hanoi[columna_destino][fila_destino] = torre_hanoi[columna_origen][0];
        torre_hanoi[columna_origen][0] = 0; // Limpiar la posición de origen
        cout << "Se movio un disco desde la columna " << columna_origen + 1 << " a la posicion " << fila_destino + 1 << " de la columna " << columna_destino + 1 << "." << endl;
    } else {
        cout << "La columna de destino esta llena. No se puede mover el disco." << endl;
    }
}

// Función recursiva que resuelve el problema de las Torres de Hanoi
void hanoi(int num, char origen, char destino, char auxiliar, int &movimientos) {
    if (num == 1) {
        cout << "Mueva el disco " << num << " desde " << origen << " hasta " << destino << "\t\t" << endl;
        movimientos++;
    } else {
        hanoi(num - 1, origen, auxiliar, destino, movimientos);
        cout << "Mueva el disco " << num << " desde " << origen << " hasta " << destino << endl;
        movimientos++;
        hanoi(num - 1, auxiliar, destino, origen, movimientos);
    }
}