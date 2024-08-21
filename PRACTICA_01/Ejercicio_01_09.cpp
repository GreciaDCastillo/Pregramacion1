// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 9
// Problema planteado: 100 numeros primos.

#include <iostream>
using namespace std;

int main() {
    int numero = 0;
    for (int i = 2; i < 100; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                numero++;
            }
        }
        if (numero == 0) {
            cout << i << " ";
        }
        numero = 0;
    }
    return 0;
}