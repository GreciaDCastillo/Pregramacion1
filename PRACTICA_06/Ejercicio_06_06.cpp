// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 08/10/2024
// Número de ejercicio: 5
// Problema planteado:  Determine transpuesta de una matriz

#include <iostream>
#include<cstdlib>
#include<ctime>
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
void transpuesta(int m[][10], int nf, int nc, int t[][10]){
    
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            t[j][i] = m[i][j];
        }
    }
    mostrarMatriz(nc, nf, t);
}


int main(){

    int m[10][10];
    int t[10][10];
    int nf;
    int nc;

    cout << "Introduce el numero de filas: ";
    cin >> nf;
    cout << "\nIntroduce el numero de columnas: ";
    cin >> nc;
    srand(time(NULL));

    llenarMatriz(nf, nc, m);
    cout << "\nLa matriz original es: " << endl;
    cout << endl;
    mostrarMatriz(nf, nc, m);
    cout << endl;
    cout << "\nLa transpuesta es: " << endl;
    cout << endl;
    transpuesta(m, nf, nc, t);

    return 0;
}