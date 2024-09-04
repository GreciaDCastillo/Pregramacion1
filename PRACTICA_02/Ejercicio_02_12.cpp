// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 04/09/2024
// Número de ejercicio: 12
// Problema planteado:  Leer dos valores y realizar una serie desendente o ascendente de ellos.

#include <iostream>
using namespace std;

void ascendente(int num1, int num2); // Prototipo de la función ascendente
void descendente(int num1, int num2); // Prototipo de la función descendente
int main() {
    int num1 = 0, num2 = 0;
    cout << "Introduce el primer número: ";
    cin >> num1;
    cout << "Introduce el segundo número: ";
    cin >> num2;
    
    if (num1 < num2) {
        ascendente(num1, num2);
    } else if (num1 > num2) {
        descendente(num1, num2);
    } else {
        cout << "Los números son iguales." << endl;
    }


    return 0;
}

void ascendente(int num1, int num2) { 
    for (int i = num1; i <= num2; i++) {
        cout << i << " ";
    }
    cout << endl;
}

void descendente(int num1, int num2) {
    for (int i = num1; i >= num2; i--) {
        cout << i << " ";
    }
    cout << endl;
}