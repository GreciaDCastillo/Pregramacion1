// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 08/10/2024
// Número de ejercicio: 5
// Problema planteado:  Multiplique dos matrices una de N x M y la otra de M x N

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenarMatriz(int nf, int nc, int m[][10]) {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            m[i][j] = rand() % 10;
        }
    }
}

void mostrarMatriz(int nf, int nc, int m[][10]) {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            cout << "\t" << m[i][j];
        }
        cout << endl;
    }
}

void multiplicarMatrices(int nf, int nc, int m1[][10], int m2[][10], int resultado[][10]) {

    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < nc; k++) {
                resultado[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    
}
int main() {
    int m1[10][10];
    int m2[10][10];
    int resultado[10][10];

    int nf;
    int nc;

    cout << "Introduce el numero de filas: ";
    cin >> nf;
    cout << "Introduce el numero de columnas: ";
    cin >> nc;

    srand(time(NULL));

    llenarMatriz(nf, nc, m1);
    cout << "La matriz 1 es: " << endl;
    cout << endl;
    mostrarMatriz(nf, nc, m1);
    cout << endl;

    llenarMatriz(nf, nc, m2);
    cout << "La matriz 2 es: " << endl;
    cout << endl;
    mostrarMatriz(nf, nc, m2);
    cout << endl;

    multiplicarMatrices(nf, nc, m1, m2, resultado);
    cout << "La multiplicacion de las matrices es: " << endl;
    cout << endl;
    mostrarMatriz(nf, nc, resultado);

    return 0;
}

