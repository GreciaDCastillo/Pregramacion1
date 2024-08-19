// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 1
// Problema planteado: 100 numeros primos.

#include <iostream>
using namespace std;

int main() {
    int num = 0;
    for (int i = 2; i < 100; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                num++;
            }
        }
        if (num == 0) {
            cout << i << " ";
        }
        num = 0;
    }
    return 0;
}