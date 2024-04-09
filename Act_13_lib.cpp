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

// Función para verificar si una palabra es un palíndromo
bool palindromo(string palabra) {
    int longitud = palabra.length();

    // Verifica la condición de palíndromo
    for (int i = 0; i < longitud / 2; i++) {
        if (tolower(palabra[i]) != tolower(palabra[longitud - i - 1])) {
            return false;
        }
    }
return true;
}

