// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 20/08/2024
// Número de ejercicio: 17
// Problema planteado: Transformar decimal a binario.

#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;

    int binarioInvertido = 0;
    int factor = 1;

    while (numero > 0) {
        binarioInvertido += (numero % 2) * factor;
        factor *= 10;
        numero /= 2;
    }
    cout << "El binario de " << numero << " es: " << binarioInvertido << endl;

    return 0;
}