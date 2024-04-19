int contar_vocales_consonantes (string palabra, int &vocales, int &consonantes, int &espacios){
    for (char letra : palabra) {
        letra = tolower(letra); // Convertir el carácter a minúsculas
            switch (letra) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    vocales++;
                break;
                case ' ':
                    espacios++;
                break;
                default:
                    if (isalpha(letra)){
                        consonantes++;
                    }
                break;
            }
        }
    return vocales;
    return espacios;
    return consonantes;
}

void eliminarEspacios(string& cadena) {
    size_t j = 0;
    for (size_t i = 0; i < cadena.length(); i++) {
        if (cadena[i] != ' ') {
            cadena[j++] = cadena[i];
        }
    }
    cadena.resize(j); // Redimensionar la cadena para eliminar los caracteres restantes
}

// Función para verificar si una palabra es un palíndromo
bool palindromo(string palabra) {
    eliminarEspacios(palabra); // Eliminar los espacios de la palabra
    int longitud = palabra.length();

    // Verifica la condición de palíndromo
    for (int i = 0; i < longitud / 2; i++) {
        if (tolower(palabra[i]) != tolower(palabra[longitud - i - 1])) {
            return false;
        }
    }
return true;
}

