// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 08/10/2024
// Número de ejercicio: 2
// Problema planteado: Generar una matriz n x n y determinar:
/* 
    - La suma de la ultima columna.
    - El producto total de la última fila.
    - Obtener el mayor valor y su posición.
    - Obtener la desviación estandar de todos los elementos de la matriz.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>  
using namespace std;

void llenarMatriz(int nf, int nc, int a, int b, int m[][20]);
void mostrarMatriz(int nf, int nc, int m[][20]);
void sumaultimaColumna(int nf, int nc, int m[][20]);
void productoFila(int nf, int nc, int m[][20]);  
void mayorValor(int nf, int nc, int m[][20]);
void desviacionMatriz(int nf, int nc, int m[][20]);  

int main() {

    int m[20][20];
    int nf;
    int nc;
    int a;
    int b;

    cout << "Introduce el numero de filas: ";
    cin >> nf;
    cout << "Introduce el numero de columnas: ";
    cin >> nc;

    cout << "\nIntroduce el primer delimitante: ";
    cin >> a;
    cout << "Introduce el segundo delimitante: ";
    cin >> b;

    srand(time(NULL));

    llenarMatriz(nf, nc, a, b, m);
    cout << "La matriz es: " << endl;
    cout << endl;
    mostrarMatriz(nf, nc, m);

    sumaultimaColumna(nf, nc, m);
    productoFila(nf, nc, m);  
    mayorValor(nf, nc, m);   
    desviacionMatriz(nf, nc, m);  

    return 0;
}

void llenarMatriz(int nf, int nc, int a, int b, int m[][20]) {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            m[i][j] = rand() % (b - a + 1) + a;
        }
    }
}

void mostrarMatriz(int nf, int nc, int m[][20]) {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            cout << "\t" << m[i][j];
        }
        cout << endl;
    }
}

void sumaultimaColumna(int nf, int nc, int m[][20]) {
    int suma = 0;
    for (int i = 0; i < nf; i++) {
        suma += m[i][nc - 1];  // Solo sumamos la última columna directamente
    }
    cout << "\nLa suma de la ultima columna es: " << suma << endl;
}

void productoFila(int nf, int nc, int m[][20]) {
    int producto = 1;
    for (int j = 0; j < nc; j++) {
        producto *= m[nf - 1][j];  // Multiplicamos los valores de la última fila
    }
    cout << "\nEl producto total de la ultima fila es: " << producto << endl;
}

void mayorValor(int nf, int nc, int m[][20]) {
    int mayor = m[0][0];
    int pfila = 0, pcolumna = 0;

    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            if (m[i][j] > mayor) {
                mayor = m[i][j];
                pfila = i;
                pcolumna = j;
            }
        }
    }
    cout << "\nEl mayor valor es: " << mayor << " y se encuentra en la fila: " << pfila + 1 << " y en la columna: " << pcolumna + 1 << endl;
}

void desviacionMatriz(int nf, int nc, int m[][20]) {
    double media = 0;
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            media += m[i][j];
        }
    }
    media /= (nf * nc);

    double suma = 0;
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            suma += (m[i][j] - media) * (m[i][j] - media);
        }
    }

    double desviacion = sqrt(suma / (nf * nc));
    cout << "\nLa desviacion estandar es: " << desviacion << endl;
}
