// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 1
// Problema planteado: Factorial de un número sin usar producto.

#include <iostream>
using namespace std;

int main() {
    int numero, factorial = 1;
    cout << "Ingrese un número: ";
    cin >> numero;

    for (int i = 1; i <= numero; i++) {
        int aux = 0;
        for (int j = i; j > 0; j--) {
            aux +=factorial;
        }
        factorial = aux;
    }
    cout << "Factorial de " << numero << " es: " << factorial;

    return 0;
}