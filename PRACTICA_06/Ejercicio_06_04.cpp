// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 08/10/2024
// Número de ejercicio: 4
// Problema planteado:  Generear una matriz n x n y hacer una secuencia en las columnas.

#include <iostream>
using namespace std;

void mostrarMatriz(int n, int m[][10]);
void llenarMatriz(int n, int m[][10]);

int main() {
    int m[10][10];
    int n;

    cout << "Introduce el tamaño de la matriz: ";
    cin >> n;

    llenarMatriz(n, m);

    cout << "La matriz es: " << endl;
    cout << endl;
    mostrarMatriz(n, m);

    return 0;
}

void llenarMatriz(int n, int m[][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = j + 2 * i + 1; 
        }
    }
}

void mostrarMatriz(int n, int m[][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "\t" << m[i][j];
        }
        cout << endl;
    }
}