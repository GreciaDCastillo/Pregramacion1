// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 03/09/2024
// Número de ejercicio: 4
// Problema planteado: Determinar triangulo rectangulo con el teorema de pitagoras.

#include <iostream>
using namespace std;

int esTrianguloRectangulo(int a, int b, int c, int &hipotenusa) {
    // Verificar si alguno de los lados cumple con el teorema de Pitágoras
    if (a * a + b * b == c * c) {
        hipotenusa = c;
        return 1;  
    } else if (a * a + c * c == b * b) {
        hipotenusa = b;
        return 1;  
    } else if (b * b + c * c == a * a) {
        hipotenusa = a;
        return 1;  // Indica que es un triángulo rectángulo
    } else {
        return 0;  // No es un triángulo rectángulo
    }
}

int main() {
    int a, b, c, hipotenusa;
    cout << "Ingrese el valor de a: ";
    cin >> a;
    cout << "Ingrese el valor de b: ";
    cin >> b;
    cout << "Ingrese el valor de c: ";
    cin >> c;

    if (esTrianguloRectangulo(a, b, c, hipotenusa) == 1) {
        cout << "Es un triángulo rectángulo." << endl;
        cout << "La hipotenusa es: " << hipotenusa << endl;
    } else {
        cout << "No es un triángulo rectángulo." << endl;
    }

    return 0;
}

