// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 6
// Problema planteado: Verificar número amigo.

#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    int suma = 0;
    cout << "Introduce el primer número: ";
    cin >> num1;
    cout << "Introduce el segundo número: ";
    cin >> num2;

    for (int i = 1; i < num1; i++) { // Calcula la suma de los divisores de num1
        if (num1 % i == 0) {
            suma += i;
        }
    } 

    if (suma == num2) {
        cout << num1 << " es un número amigo de " << num2 << endl;
    } else {
        cout << num1 << " no es un número amigo de " << num2 << endl;
    }
    return 0;
}