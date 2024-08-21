// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 13
// Problema planteado: Mostrar cifras al revés.

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Introduce un número: ";
    cin >> num;
    while (num > 0) {
        cout << num % 10 << " ";
        num /= 10;
    }
    return 0;
}