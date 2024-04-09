void factorial(int *fact){
    int i = 1, resul = 1;

    for (i = 1; i <= *fact; i++) {
        resul = resul*i;
    }

    *fact = resul;

}