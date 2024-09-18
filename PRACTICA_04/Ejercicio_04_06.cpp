// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 18/09/2024
// Número de ejercicio: 6
// Problema planteado: declarar 3 vectores de 5 elementos. el vector3 será el resultado de la suma de los vectores1 y vectores2.

#include <iostream>
using namespace std;

void leerVector(int num, double vector[]);
void sumarVectores(int num, double vector1[], double vector2[], double vector3[]);
void imprimirVector(int num, double vector[]); 

int main() {
    int num = 5;

    double vector1[num], vector2[num], vector3[num];

    cout << "Introduce los elementos del primer vector:" << endl;
    leerVector(num, vector1);

    cout << "Introduce los elementos del segundo vector:" << endl;
    leerVector(num, vector2);

    sumarVectores(num, vector1, vector2, vector3);

    cout << "\nVectores:" << endl;
    imprimirVector(num, vector1);
    imprimirVector(num, vector2);
    imprimirVector(num, vector3);

    return 0;
}

void leerVector(int num, double vector[]) {
    for (int i = 0; i < num; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vector[i];
    }
}

void sumarVectores(int num, double vector1[], double vector2[], double resultado[]) {
    for (int i = 0; i < num; i++) {
        resultado[i] = vector1[i] + vector2[i];
    }
}

void imprimirVector(int num, double vector[]) {
    for (int i = 0; i < num; i++) {
        cout << "\t " << vector[i] << "\t ";
    }
    cout << endl;
}
