// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 1
// Problema planteado: Verificar multiplo.

#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Introduce el primer numero: ";
    cin >> num1;
    cout << "Introduce el segundo numero: ";
    cin >> num2;
    if (num1 % num2 == 0) {
        cout << num1 << " es multiplo de " << num2 << endl;
    } else {
        cout << num1 << " no es multiplo de " << num2 << endl;
    }
    return 0;
}
