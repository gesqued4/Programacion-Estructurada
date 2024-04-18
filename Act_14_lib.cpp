void imprimir_vidas(int vidas){
    cout << "\t\t\t\t\t\t";
    cout << "Vidas: " << vidas << endl;
}

void imprimir_monito(int &intentos_fallidos) {
    // Vector que contiene las partes del monito según los intentos fallidos
    vector<string> partes_monito = {
        "\t|",             // No se ha cometido ningún error
        "\t|         O",       // Se ha cometido un error
        "\t|         O\n\t|        /",          // Se han cometido dos errores
        "\t|         O\n\t|        /|",         // Se han cometido tres errores
        "\t|         O\n\t|        /|\\",       // Se han cometido cuatro errores
        "\t|         O\n\t|        /|\\\n\t|        /",     // Se han cometido cinco errores (monito completo)
        "\t|         O\n\t|        /|\\\n\t|        / \\ "
    };
    // Imprimir la parte correspondiente del monito según los intentos fallidos
    cout << partes_monito[intentos_fallidos];
}

void imprimir_monitoWin(int monito_completo) {
    // Vector que contiene las partes del monito según los intentos fallidos
    vector<string> partes_monito = {
        "\t|",             // No se ha cometido ningún error
        "\t|         O",       // Se ha cometido un error
        "\t|         O\n\t|        /",          // Se han cometido dos errores
        "\t|         O\n\t|        /|",         // Se han cometido tres errores
        "\t|         O\n\t|        /|\\",       // Se han cometido cuatro errores
        "\t|         O\n\t|        /|\\\n\t|        /",     // Se han cometido cinco errores (monito completo)
        "\t|         O\n\t|        /|\\\n\t|        / \\ "
    };
    // Imprimir la parte correspondiente del monito según los intentos fallidos
    cout << partes_monito[monito_completo];
}

void imprimir_ahorcado(int &intentos_fallidos, int &vidas){
    cout << "**************************************************************" << endl << endl;
    cout << "\t\t\tJuego del Ahorcado" << endl;
    imprimir_vidas(vidas);
    /*Imprimir horca*/
    cout << "         _________ " << endl;
    cout << "\t|         |\n";
    imprimir_monito(intentos_fallidos);
    cout << endl;
    for (int i = 0; i < 4; i++){
        cout << "\t|" << endl;
    }
    cout << "     ___|___" << endl;
}

void imprimir_ahorcadoWin(int vidas){
    cout << "**************************************************************" << endl << endl;
    cout << "\t\t\tJuego del Ahorcado" << endl;
    imprimir_vidas(vidas);
    /*Imprimir horca*/
    cout << "         _________ " << endl;
    cout << "\t|         |";
    cout << endl;
    for (int i = 0; i < 4; i++){
        cout << "\t|" << endl;
    }
    imprimir_monitoWin(6);
    cout << endl;
    cout << "     ___|___" << endl;
}

void imprimir_letras(char letter, char letras_disponibles[]){
    letter = toupper(letter);
    
    for (int i = 0; i < 26; i++){
        if (letter == letras_disponibles[i]){
            letras_disponibles[i] = '-';
        }
        cout << letras_disponibles[i] << " ";
        if (i == 9){
            cout << "\n ";
        }
        if (i == 18){
            cout << "\n  ";
        }

    }
}

bool validar_vocal(char letra, int &intentos_fallidos, int &vidas){
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
        intentos_fallidos++;
        vidas--;
        return true;
    }
    else{
        return false;
    }
}

bool letra_repetida(char letra, vector<char> letras_ingresadas) {
    for (char l : letras_ingresadas) {
            if (tolower(l) == tolower(letra) && letra != '1') {
                return true;
            }
    }
    return false;
}

