// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 02/09/2024
// Número de ejercicio: 2
// Problema planteado: Calcuar la hipotenusa de un triangulo rectangulo, usasndo el teorema de pitagoras.

#include <iostream>
#include <math.h>
using namespace std;

int hipotenusaPitagoras(float cateto1, float cateto2);
int main() {
    float cateto1, cateto2, hipotenusa;
    cout << "Ingrese el valor del primer cateto: ";
    cin >> cateto1;
    cout << "Ingrese el valor del segundo cateto: ";
    cin >> cateto2;
    hipotenusa = hipotenusaPitagoras(cateto1, cateto2);
    cout << "La hipotenusa es: " << hipotenusa << endl;
    return 0;
}

int hipotenusaPitagoras(float cateto1, float cateto2) {
    float hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2)); // Hipotenusa = √(cateto1^2 + cateto2^2)
    return hipotenusa;
}