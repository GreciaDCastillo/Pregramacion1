// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/11/2024
// Número de ejercicio: 14
// Problema planteado: Realizar un algoritmo recursivo para elaborar un programa en el que dado
//                     un entero n > 1, calcule e imprima los elementos correspondientes a la
//                     conjetura de Ullman 

#include <iostream>
using namespace std;

int conjeturaUllman(int n);

int main() {
    int n;
    cout << "Ingrese un número entero positivo mayor que 1: ";
    cin >> n;

    // Validación de entrada
    if (n > 1) {
        cout << "Secuencia de Ullman para " << n << ": ";
        conjeturaUllman(n);
        cout << endl;
    } else {
        cout << "Por favor, ingrese un número mayor que 1." << endl;
    }

    return 0;
}

int conjeturaUllman(int n) {
    // Imprimir el número actual
    cout << n << " ";

    // Caso base: si el número llega a 1, terminamos la recursión
    if (n == 1) {
        return 1;
    }

    // Llamada recursiva dependiendo de si el número es par o impar
    if (n % 2 == 0) {
        return conjeturaUllman(n / 2);  // Si es par, dividimos entre 2
    } else {
        return conjeturaUllman(3 * n + 1);  // Si es impar, multiplicamos por 3 y sumamos 1
    }
}