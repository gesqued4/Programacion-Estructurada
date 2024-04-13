
//este archivo no lo puedo compilar ya que no tiene la estructura de un archivo .cpp
//mas sin embargo lo puedo mandar a llamar en otro archivo.cpp e incluir las funciones de este archivo


//definicion de funciones



//funcion saludo inicial
void goodbye() {
    cout << "\nGoodbye my friend..." << endl;
    cout << "\tVersion 1.0" << endl;
    cout << "Autor: Gerardo Esqueda Padilla" << endl;
    cout << "**********************" << endl;
} // fin de hello

void imp(string texto) {
    cout << texto << endl;
} //fin de imp

void impln(string texto) {
    cout << texto << endl;
} //fin de imp

void imp(int num) {
    cout << num << endl;
} //fin de imp

void imp(double num) {
    cout << num << endl;
} //fin de imp

/*esta funcion retorna la suma de num1 con num2*/
int suma(int num1, int num2) {
    int sum;
    sum = num1 + num2;
    return sum;
}

float suma(double num1, double num2) {
    float sum;
    sum = num1 + num2;
    return sum;
}

bool valida(char caracter) {
    if((caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122))
        return true;
    else 
        return false;
}

string booltotxt(bool val) {
    if(val == 1)
        return "Verdadero";
    else
        return "False";
} //fin bool

