// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 16
// Problema planteado: Mostrar consola de números N.

#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;
    for (int i = 1; i <= numero; i++) { 
        if (i % 3 == 0 && i % 5 == 0) { // Multiplo de 3 y 5
            cout << "z" << endl;
        } else if (i % 3 == 0) {
            cout << "x" << endl;
        } else if (i % 5 == 0) {
            cout << "y" << endl;
        } else {
            cout << i << endl;
        }
        cout << endl;
    }
    return 0;
}