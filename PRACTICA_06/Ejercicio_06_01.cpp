// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 04/10/2024
// Número de ejercicio: 1
// Problema planteado: De una matriz n x n. Cambiar la fila 1 por la fila n.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenarMatriz(int nf, int nc, int m[][10]);
void mostrarMatriz(int nf, int nc, int m[][10]);
void cambiarFilas(int nf, int nc, int m[][10]);

int main() {

    int m[10][10];
    int nf;
    int nc;

    cout << "Introduce el nuemro de filas: ";
    cin >> nf;
    cout << "Introduce el nuemro de columnas: ";
    cin >> nc;

    srand(time(NULL));

    llenarMatriz(nf, nc, m);
    cout << "La matriz original es: " << endl;
    cout << endl;
    mostrarMatriz(nf, nc, m);
    cout << endl;
    cambiarFilas(nf, nc, m);
    cout << "La nueva matriz es: " << endl;
    cout << endl;
    mostrarMatriz(nf, nc, m);
    

    return 0;
}

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

void cambiarFilas(int nf, int nc, int m[][10]) {
    for (int i = 0; i < nc; i++) {
        int aux = m[0][i];  
        m[0][i] = m[nf - 1][i]; // cambio de filas
        m[nf - 1][i] = aux;
    }
}