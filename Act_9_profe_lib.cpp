void println(string texto){
    cout << texto << endl;
}   //fin de print

bool valingreso(vector<char> &vec, char t){
    for(int i = 0; i < vec.size(); i++){
        if(t == vec[i]){
            return true;
        }
        else {
            return false;
        }
    }

} //fin valingreso

void insert(vector<char> &vec, char t){
    if(valingreso(vec, t) == 1){        
        println("No se puede insertar");
    }
    else {
    vec.push_back(t);
}   //fin insertar
}

void print_vector(vector<char> &vec){
    for(int i = 0; i < vec.size(); i++){
        cout << "[" << vec[i] << "],";
    }

    cout << "Fin de arreglo" << endl;
} //fin imprimir vector

bool valida(char caracter) {
    if((caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122))
        return true;
    else 
        return false;
}

