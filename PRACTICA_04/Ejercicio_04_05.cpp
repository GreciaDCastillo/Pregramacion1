// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 18/09/2024
// Número de ejercicio: 5
// Problema planteado: Leer 2 vectores de dimención n y combinar ambos en otro vector.

#include <iostream>
using namespace std;

void leerVector(int num, double vector[]);
void combinarVectores(int num, double vector1[], double vector2[], double resultado[]);
void imprimirVectores(int num, double vector1[], double vector2[]);
void imprimirResultado(int num, double resultado[]);

int main() {
    int num;  

    cout << "Introduce el tamaño de los vectores: ";
    cin >> num;

    double vector1[num], vector2[num], resultado[num];

    cout << "Introduce los elementos del primer vector:" << endl;
    leerVector(num, vector1);

    cout << "Introduce los elementos del segundo vector:" << endl;
    leerVector(num, vector2);

    combinarVectores(num, vector1, vector2, resultado);

    cout << "\nVectores:" << endl;
    imprimirVectores(num, vector1, vector2);

    cout << "\nCombinación:" << endl;
    imprimirResultado(num, resultado);

    return 0;
}

void leerVector(int num, double vector[]) {
    for (int i = 0; i < num; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vector[i];
    }
}

void combinarVectores(int num, double vector1[], double vector2[], double resultado[]) {
    for (int i = 0; i < num; i++) {
        resultado[i] = vector1[i] + vector2[i]; // Suma
    }
}

void imprimirVectores(int num, double vector1[], double vector2[]) {
    for (int i = 0; i < num; i++) {
        cout << "\t "<< vector1[i] << "\t ";
    }
    cout << endl;
    for (int i = 0; i < num; i++) {
        cout << "\t " << vector2[i] << "\t ";
    }
    cout << endl;
}

void imprimirResultado(int num, double resultado[]) {
    for (int i = 0; i < num; i++) {
        cout << "\t " << resultado[i] << "\t ";
    }
    cout << endl;
}