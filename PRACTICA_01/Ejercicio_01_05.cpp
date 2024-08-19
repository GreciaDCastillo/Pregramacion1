// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 1
// Problema planteado: Verificar número primo.

#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Introduce un numero: ";
    cin >> numero;
    for (int i = 2; i < numero; i++) {
        if (numero % i == 0) {
            cout << numero << " no es un numero primo." << endl;
            return 0;
        }
    }
    cout << numero << " es un numero primo." << endl;
    return 0;
}