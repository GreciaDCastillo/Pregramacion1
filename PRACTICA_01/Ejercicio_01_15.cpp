// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 15
// Problema planteado: Crear una piramide.

#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;
    for (int i = 1; i <= numero; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        for (int k = i - 1; k >= 1; k--) {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}