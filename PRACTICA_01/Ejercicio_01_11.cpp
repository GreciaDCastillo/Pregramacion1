// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 1
// Problema planteado: Multiplicar dos números sin usar operadores.

#include <iostream>
using namespace std;

int main() {
    int num1, num2; 
    cout << "Introduce el primer numero: ";
    cin >> num1;
    cout << "Introduce el segundo numero: ";
    cin >> num2;

    int suma = 0;

    for (int i = 0; i < num2; i++) {
        suma += num1;
    }
    cout << num1 << " * " << num2 << " = " << suma << endl;
    return 0;
}