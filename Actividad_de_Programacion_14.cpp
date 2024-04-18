/*************************Presentacion*************************
        NOMBRE: Gerardo Esqueda Padilla
        FECHA: 17 de Abril de 2024
        PROGRAMA: Actividad_de_Programacion_14.cpp
        CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
        INGENIERIA EN COMPUTACION / 2DO SEMESTRE
        PROFESOR: Sergio Franco Casillas
        DESCRIPCION: 
        Tener un banaco de al menos 20 palabras
        La computadora va a elegir una al azar y el ususario debe adivinar el resultado
        Si el usuario elige una vocal, se debe penalizar con 1 intento, es decir, tendra una oportunidad menos
        Contar el numero de intentos por jugador
**************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
#include "Act_14_lib.cpp"

int main(){
    string banco_palabras[] = {"logica", "cibernetica", "programacion", "algoritmo", "datos", "redes", "codigo", "hardware", "software", "nube", "seguridad", "innovacion", "digitalizacion", "tecnologia", "interfaz", "conectividad", "informatica", "aplicacion", "internet", "automatizacion"};
    char letras_disponibles[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    bool op_while = true, coincidencia, palabra_adivinada, es_letra, es_vocal, letras_repetidas;
    char op_switch = '0', letra = '0';
    string palabra, entrada_switch, entrada_letra, adivinar_palabra;
    int longitud, intentos_fallidos = 0, vidas = 6;
    vector<char> user_input;
    vector<char> letras_ingresadas;
    
    
    //  Inicializar semilla rand
    srand(time(0));
    int pos = rand() % 20;  //  Genera un numero aleatorio entre 0 y 19
    cout << pos; 

    while (op_while){   // Inicio ciclo while
        es_letra = false;
        es_vocal = false;

        if(op_switch == '0'){
                /*Menu de opciones*/
                cout << "\t\t\tJuego del Ahorcado" << endl;
                cout << "1. Instrucciones" << endl;
                cout << "2. Jugar" << endl;
                cout << "3. Salir" << endl;
                cout << "Seleccione una opcion: ";
                getline(cin, entrada_switch);       // Leer toda la linea de entrada
                if (entrada_switch.length() == 1){    // Verificar que solo sea un caracter
                    op_switch = entrada_switch[0];  // Guardar el caracter ingresado en otra variable
                }
                else {
                    cout << "Entrada no valida, por favor ingrese solo un caracter..." << endl;
                    cout << "Presione enter para continuar...";
                    cin.ignore(); // Ignorar cualquier entrada adicional
                    cin.get(); // Esperar a que el usuario presione enter, con el fin de mostrar el msj de error y pausar un poco la ejecucion del programa
                    op_switch = '0';
                }
                system("cls");
        }
        
        if (op_switch != '0'){
            switch (op_switch){     // Inicio switch
                case '1': {  // Case 1: Instrucciones
                    cout << "\t\t\tInstrucciones para el Juego del Ahorcado\n\n";

                    cout << "Objetivo:\n";
                    cout << "Adivina la palabra oculta antes de que se complete el dibujo del hombre ahorcado y pierdas todas tus vidas.\n\n";

                    cout << "Como jugar:\n";
                    cout << "1. Selecciona una letra por turno para adivinar la palabra.\n";
                    cout << "2. Si la letra esta en la palabra, se revela su posicion.\n";
                    cout << "3. Si la letra no esta en la palabra, se anade una parte al dibujo del hombre ahorcado y pierdes una vida.\n";
                    cout << "4. Cada vez que ingreses una vocal incorrecta, tambien perderas una vida.\n";
                    cout << "5. Gana si adivinas la palabra antes de que se complete el dibujo del hombre ahorcado.\n";
                    cout << "6. Pierde si se completa el dibujo del hombre ahorcado o pierdes todas tus vidas.\n\n";

                    cout << "Consejos:\n";
                    cout << "- Adivina las letras mas comunes primero.\n";
                    cout << "- Evita ingresar letras que ya has intentado antes.\n";
                    cout << "- Ten cuidado al ingresar vocales, ya que cada vocal incorrecta hara que pierdas una vida.\n\n";

                    cout << "Diviertete y buena suerte!\n";
                    cout << "Presione enter para continuar...";
                    cin.ignore(); // Ignorar cualquier entrada adicional
                    cin.get(); // Esperar a que el usuario presione enter, y pausar un poco la ejecucion del programa
                    system("cls");
                    op_switch = '0';
                break;
                }
                case '2': {  // Case 2: Jugar

                    if(letra == '0'){   // Condicion que verifica si es la primera vuelta del ciclo
                        imprimir_ahorcado(intentos_fallidos, vidas);
                    }
                    cout << "\n ";

                    palabra = banco_palabras[pos];  // Guardar la palabra en variable string
                    longitud = palabra.length();    // Encontrar la cantidad de letras de la palabra

                    // Si el vector user_input esta vacio inicializarlo con guiones bajos
                    if (user_input.empty()) {                   
                        user_input.assign(longitud, '_');
                    }

                    if (letra == '0'){
                        for (int i = 0; i < longitud; i ++){    // Imprimir los espacios de la cantidad de letras a adivinar
                            cout << " _ ";
                        }

                        if (intentos_fallidos <= 4){
                                cout << endl << endl;
                                imprimir_letras(letra, letras_disponibles);
                                cout << endl << endl << endl;
                                cout << "**************************************************************";
                        }
                    }   
                    else {  // Condicion que verifica si es segunda vuelta del ciclo
                        coincidencia = false;

                        if (isalpha(letra)){    // Verificar si la letra ingresada es letra
                            es_letra = true;
                            letra = tolower(letra); // Convertir a minuscula para evitar problemas en la comparacion
                        }

                        // Guardo las letras adivinadas en un array para imprimirlo posteriormente
                        for (int i = 0; i < longitud; i++) {
                            // Si letra coincide y la posicion en user_input es un guion bajo, actualizar
                            if (letra == palabra[i] && user_input[i] == '_' && !letras_repetidas) {
                                user_input[i] = letra;
                                coincidencia = true;
                            }
                        }

                        // Si no coincide la letra intentos fallidos se incrementa
                        if (!coincidencia && intentos_fallidos <= 4 && !letras_repetidas) {      // Verifica que no sea la ultima oportunidad de adivinar la palabra
                            intentos_fallidos++;
                            vidas--;
                        }
                        if (intentos_fallidos <= 4 && coincidencia && !letras_repetidas){    // Verifica que no sea la ultima oportunidad
                            //  Verifica si la letra ingresada es vocal
                            es_vocal = validar_vocal(letra, intentos_fallidos, vidas);
                        }

                        palabra_adivinada = true;      // Verifica si has adivinado la palabra 

                        // Verifica si has adivinado la palabra 
                        for (int i = 0; i < longitud; i++){
                            if (user_input[i] != palabra[i]){
                                palabra_adivinada = false;
                            }
                        }
                        // Ultima oportunidad de adivinar palabra
                        if (adivinar_palabra == palabra){
                            palabra_adivinada = true;   
                        }

                        if (!palabra_adivinada){    // Imprimir el estado del ahorcado si no ha ganado
                            imprimir_ahorcado(intentos_fallidos, vidas);   // Imprimir el estado actualizado del ahorcado
                            cout << endl;
                    
                            // Bucles y condiciones para imprimir mensajes de estado
                            for (int i = 0; i < longitud; i++) {
                                if (user_input[i] == '_'){
                                    cout << " _ ";  // Imprimir guiones y espacios para darle mas presentacion
                                } else {
                                    cout << user_input[i] << " ";   //  Imprimir la entrada del usuario
                                }
                            }

                            if (intentos_fallidos <= 4){
                                cout << endl << endl;
                                imprimir_letras(letra, letras_disponibles);
                                cout << endl << endl;
                                cout << "\nMensaje: " << endl;
                            }
                        }
                        else {  // Imprimir el estado del ahorcado ganador
                            imprimir_ahorcadoWin(vidas);   // Imprimir el estado actualizado del ahorcado
                            cout << endl;
                    
                            // Bucles y condiciones para imprimir mensajes de estado
                            for (int i = 0; i < longitud; i++) {
                                if (intentos_fallidos <= 4){
                                    if (user_input[i] == '_'){
                                        cout << " _ ";  // Imprimir guiones y espacios para darle mas presentacion
                                    } else {
                                        cout << user_input[i] << " ";   //  Imprimir la entrada del usuario
                                    }
                                }
                                else {
                                    user_input[i] = adivinar_palabra[i];
                                    cout << user_input[i] << " ";   //  Imprimir la entrada del usuario
                                }
                            }
                            cout << endl << endl;
                            cout << "\nMensaje: " << endl;
                            if (adivinar_palabra == palabra){
                                cout << "Genial, has acertado...";
                            }
                        }

                        // Condiciones para imprimir mensajes de estado

                        if (letras_repetidas && intentos_fallidos <= 4 && es_letra) {     // Verificar si la letra ya ha sido ingresada
                            cout << "Ya has ingresado esta letra, prueba con otra diferente..." << endl;
                        }
                
                        if (coincidencia && intentos_fallidos <= 4 && !letras_repetidas){
                            cout << "La letra ingresada se encuentra en la palabra secreta!" << endl;
                        }

                        if (!coincidencia && intentos_fallidos <= 4 && !letras_repetidas) {
                            cout << "La letra ingresada no coincide con ninguna letra de la palabra..." << endl;
                        }

                        if (!es_letra && intentos_fallidos <= 4) {  
                            cout << "La entrada no es una letra valida..." << endl;
                        }

                        if (letra == '1' && intentos_fallidos <= 4){    // Verifica que solo ingrese un caracter
                            cout << "O has ingresado mas de un caracter pierdes una vida..." << endl;
                        }

                        if(es_vocal && intentos_fallidos <= 4 && !letras_repetidas){
                            cout << "La letra ingresada es una vocal, pierdes una vida..." << endl;
                        }

                        if (palabra_adivinada && intentos_fallidos < 6) {    //  Imprimir mensaje en caso de adivinar la palabra
                            cout << endl << endl << endl;
                            cout << "**************************************************************";
                            cout << "\n\n\nFelicidades has adivinado la palabra..." << endl;
                            cout << "Gracias por jugar, vuelve pronto..." << endl;
                            cout << "Presione enter para continuar..." << endl;
                            cin.ignore(); // Ignorar cualquier entrada adicional
                            cin.get(); // Esperar a que el usuario presione enter, con el fin de mostrar el msj de error y pausar un poco la ejecucion del programa
                            op_while = false;
                            
                        }
                        else if (intentos_fallidos >= 6) {
                            cout << endl << endl << endl;
                            cout << "**************************************************************";
                            cout << "\n\n\nHas muerto, intentalo de nuevo..." << endl;
                            cout << "La palabra secreta era: " << palabra << endl;
                            cout << "Presione enter para continuar...";
                            cin.ignore(); // Ignorar cualquier entrada adicional
                            cin.get(); // Esperar a que el usuario presione enter, con el fin de mostrar el msj de error y pausar un poco la ejecucion del programa
                            op_while = false;
                        }
                        if (!palabra_adivinada && intentos_fallidos <= 4){
                            cout << endl << endl << endl;
                            cout << "**************************************************************";
                        }
                    }

                    if (intentos_fallidos >= 0 && intentos_fallidos <= 4 && !palabra_adivinada){     // Validar si tienes al menos 4 vidas para solicitar ingresar una letra

                        cout << "\n\n" << palabra;
                            
                        cout << "\n\nIngrese una letra: ";  // Solicito la letra a comparar
                        getline(cin, entrada_letra);
                        if (entrada_letra.length() == 1){   //  Verificar que solo sea una letra ingresada
                            letra = entrada_letra[0];

                            letras_repetidas = letra_repetida(letra, letras_ingresadas);
                            if(isalpha(letra)){
                                letras_ingresadas.push_back(letra); // Agregar la letra al vector de letras ingresadas
                            }
                        }
                        else {
                            letra = '1';
                        }
                        system("cls");

                    }
                    else if (intentos_fallidos == 5 && !palabra_adivinada){   // Verifica si has fallado 5 veces para darte una oportunidad final para adivinar la palabra
                        cout << endl << endl << endl;
                        cout << "**************************************************************";
                        cout << "\n\nUltima oportunidad para salvar al ahorcado!" << endl;
                        cout << "Ingresa la palabra completa y demuestra tus habilidades: ";
                        cin >> adivinar_palabra;
                        
                        if (adivinar_palabra != palabra){
                            intentos_fallidos++;
                            vidas--;
                        }
                        system("cls");
                    }

        
                break;
                }
                case '3': {  // Case 3: Salir
                    op_while = false;
                break;
                }
                default:
                    cout << "Opcion incorrecta, seleccione una opcion valida..." << endl;
                    op_switch = '0';
            }   // Fin switch
        }   // Condicion para evaluar que el caracter ingresado sea un digito
    }   // Fin ciclo while
    return 0;
}