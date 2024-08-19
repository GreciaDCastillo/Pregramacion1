// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 1
// Problema planteado: Calcular cantidad de dígitos.

#include <iostream>
using namespace std;

int main() {
    int num, digitos = 0;
    cout << "Introduce un numero: ";
    cin >> num;
    while (num > 0) {
        num = num / 10;
        digitos++;
    }
    cout << "La cantidad de digitos es: " << digitos << endl;
    return 0;
}