// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 04/09/2024
// Número de ejercicio: 13
// Problema planteado:  Generar una secuencia de numeros aleatorios (entre 0 y 100). Y ver si son divisibles por 5.

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void generarSecuencia(int n);

int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;

    generarSecuencia(numero);
    return 0;
}

void generarSecuencia(int n) {

    for (int i = 0; i < n; i++) {
       int num = rand() % 100 + 1; // Generar un número aleatorio entre 1 y 100
       cout << num ;

       if (num % 5 == 0) {
            cout << "*";
       }
       cout << " ";
    }
    cout << endl;
}