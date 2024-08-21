// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 9
// Problema planteado: 100 numeros primos.

#include <iostream>
using namespace std;

int main() {
    int numero = 0;
    for (int i = 2; i < 100; i++) { // Contador de los 100 primeros números.
        for (int j = 2; j < i; j++) {  // Contador de los divisores.
            if (i % j == 0) { // Si el divisor es 0, no es primo.
                numero++; 
            }
        }
        if (numero == 0) { // Si el contador de divisores es 0, es primo.
            cout << i << " ";
        }
        numero = 0;
    }
    return 0;
}