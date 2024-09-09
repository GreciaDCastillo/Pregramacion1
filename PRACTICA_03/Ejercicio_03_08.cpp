// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/09/2024
// Número de ejercicio: 8
// Problema planteado: Generar secuencia.

/*
Generar:
        121
        12321
        1234321
        123454321
        12345654321
        1234567654321
        123456787654321
        12345678987654321
*/

#include <iostream>
using namespace std;

void secuencia(int num);

int main() {

    int num;
    cout << "Ingresa un numero: ";
    cin >> num;

    secuencia(num);
    cout << endl;

    return 0;
}

void secuencia(int num) {

    for (int i = 2; i <= num; i++) { // Imprime las  filas 
        // Imprime la secuencia ascendente de 1 a i
        for (int j = 1; j <= i; j++) { 
            cout << j << " ";
        }
        for (int j = i - 1; j >= 1; j--) { // Imprime la secuencia decendiente de i-1 a 1.
            cout << j << " ";
        }
        cout << endl;
    }
}