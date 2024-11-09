// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/11/2024
// Número de ejercicio: 8
// Problema planteado: Funcion recursiva  dado un vector de números enteros, retorne la suma de sus elementos.

#include <iostream>
using namespace std;

int sumaVector(int vector[], int num);

int main() {
    int num = 0;
    cout << "Ingrese el tamanio del vector: ";
    cin >> num;
    int vector[num];
    for (int i = 0; i < num; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> vector[i];
    }

    cout << "La suma de los elementos del vector es: " << sumaVector(vector, num) << endl;
    return 0;
}

int sumaVector(int vector[], int num) {
    if (num == 0) {
        return 0;
    } else {
        return vector[num - 1] + sumaVector(vector, num - 1); // Llamada recursiva para calcular la suma de los elementos
    }
}