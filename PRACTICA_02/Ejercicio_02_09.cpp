// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 04/09/2024
// Número de ejercicio: 9
// Problema planteado:  Leer un número y determinar si aparece en la secuencia de Fibonacci.

#include <iostream>
using namespace std;

int esFibonacci(int num);
int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;

    if (esFibonacci(numero)) {
        cout << "El número " << numero << " aparece en la secuencia de Fibonacci." << endl;
    } else {
        cout << "El número " << numero << " no aparece en la secuencia de Fibonacci." << endl;
    }

    return 0;
}

// Función para verificar si un número pertenece a la secuencia de Fibonacci
int esFibonacci(int num) {
    int a = 0, b = 1, c;

    if (num == a || num == b) {
        return 1;
    }

    while (true) {
        c = a + b;
        if (c == num) {
            return 1;
        } else if (c > num) {
            return 0;
        }
        a = b;
        b = c;
    }
}