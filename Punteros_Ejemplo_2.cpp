#include <iostream>
using namespace std;
#include "Punt_Ejem_2_lib.cpp"

int main () {
    int fact;
    cout << "Introduce un numero para calcular su factorial" << endl;
    cin >> fact;
    factorial(&fact);
    cout << fact;






    return 0;
}