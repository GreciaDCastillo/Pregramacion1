// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/11/2024
// Número de ejercicio: 9
// Problema planteado:  Realizar un algoritmo recursivo para comparar si dos vectores son iguales.

#include <iostream>
using namespace std;

bool iguales(int[], int[], int);

int main() {

    int num; 
    cout << "Introduce el tamaño de los vectores: ";
    cin >> num;

    cout << "Introduce los elementos del primer vector:" << endl;
    cout << endl;
    int vector1[num];
    for (int i = 0; i < num; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vector1[i];
    }

    cout << "\nIntroduce los elementos del segundo vector:" << endl;
    cout << endl;
    int vector2[num];
    for (int i = 0; i < num; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vector2[i];
    }

    if (iguales(vector1, vector2, num)) {
        cout << "Los vectores son iguales." << endl;
    }
    else {
        cout << "Los vectores son diferentes." << endl;
    }

    return 0;
}

bool iguales(int vector1[], int vector2[], int num) {
    if (num == 0) { // Caso base
        return true;
    }
    else if (vector1[num - 1] != vector2[num - 1]) { // Comparación de elementos 
        return false;
    }
    else {
        return iguales(vector1, vector2, num - 1); // Llamada recursiva para comparar los elementos del vector
    }
}