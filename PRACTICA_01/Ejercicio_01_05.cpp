// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 5
// Problema planteado: Verificar número primo.

#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;
    for (int i = 2; i < numero; i++) { // i = 2 ya que 1 no es un número primo
        if (numero % i == 0) {
            cout << numero << " no es un número primo." << endl;
            return 0;
        }
    }
    cout << numero << " es un número primo." << endl;
    return 0;
}