// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 04/09/2024
// Número de ejercicio: 14
// Problema planteado:  Generar cuadrados perfectos en el rango 1 a n.

#include <iostream>
#include <cmath>
using namespace std;

void cuadrado(int num);
int main() {
    int num;
    cout << "Introduce el rango: ";
    cin >> num;

    cuadrado(num);

    return 0;
}

void cuadrado(int num) {
    for (int i = 1; i * i <= num; i++) {
        cout << i * i << " ";
    }
    cout << endl;
}