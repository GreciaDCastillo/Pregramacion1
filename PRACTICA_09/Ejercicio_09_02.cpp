// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 06/11/2024
// Número de ejercicio: 2
// Problema planteado: Funcion recursiva para calcular la potencia de un número. 

#include <iostream>
using namespace std;
int potencia(int base, int exponente);

int main() {
    int base, exponente;
    cout << "Ingrese la base: ";
    cin >> base;
    cout << "Ingrese el exponente: ";
    cin >> exponente;
    cout << base << "^" << exponente << " = " << potencia(base, exponente) << endl;
    return 0;
}

int potencia(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    } else {
        return base * potencia(base, exponente - 1); // Llamada recursiva de la potencia de la base
    }
}