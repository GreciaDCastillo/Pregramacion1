// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 06/11/2024
// Número de ejercicio: 6
// Problema planteado: Funcion recursiva para calcular el máximo común divisor de
//                     dos números enteros aplicando el algoritmo de Euclides.

#include <iostream>
using namespace std;

int mcd(int num1, int num2);

int main() {
    int num1, num2;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "El maximo comun divisor de " << num1 << " y " << num2 << " es: " << mcd(num1, num2) << endl;
    
    return 0;
}

int mcd(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return mcd(num2, num1 % num2); // Llamada recursiva del algoritmo de Euclides 
    }
}