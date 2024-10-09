// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 08/10/2024
// Número de ejercicio: 3
// Problema planteado:  

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int nf = 3;  // Número de filas
const int nc = 4;  // Número de columnas

// Función para mostrar la matriz
void mostrarMapa(char mapa[nf][nc]) {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para contar filas sin zombies
int contarFilassinZ(char mapa[nf][nc]) {
    int filassinZ = 0;
    for (int i = 0; i < nf; i++) {
        bool filaSegura = true;
        for (int j = 0; j < nc; j++) {
            if (mapa[i][j] == 'x') {
                filaSegura = false;
                break;
            }
        }
        if (filaSegura) {
            filassinZ++;
        }
    }
    return filassinZ;
}

// Función para contar columnas sin zombies
int contarColumnasinZ(char mapa[nf][nc]) {
    int columnasinZ = 0;
    for (int j = 0; j < nc; j++) {
        bool columnaSegura = true;
        for (int i = 0; i < nf; i++) {
            if (mapa[i][j] == 'x') {
                columnaSegura = false;
                break;
            }
        }
        if (columnaSegura) {
            columnasinZ++;
        }
    }
    return columnasinZ;
}

// Función para obtener coordenadas de los zombies
void coordenadasZ(char mapa[nf][nc], int filasZ[], int columnasZ[], int& cantidadZ) {
    cantidadZ = 0;
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            if (mapa[i][j] == 'x') {
                filasZ[cantidadZ] = i;
                columnasZ[cantidadZ] = j;
                cantidadZ++;
            }
        }
    }
}

// Función para contar el total de zombies
int contarZ(char mapa[nf][nc]) {
    int total = 0;
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            if (mapa[i][j] == 'x') {
                total++;
            }
        }
    }
    return total;
}

// Función para verificar si se puede entrar al complejo
void verificarEntrada(char mapa[nf][nc]) {
    int primeraColumnaZ = 0;
    for (int i = 0; i < nf; i++) {
        if (mapa[i][0] == 'x') {
            primeraColumnaZ++;
        }
    }
    if (primeraColumnaZ >= 2) {
        cout << "\nNo es posible entrar al complejo!" << endl;
    } else {
        cout << "\nEs posible entrar al complejo!" << endl;
    }
}

// Función para contar espacios vacíos
int calcularEspaciosVacios(char mapa[nf][nc]) {
    int espaciosVacios = 0;
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            if (mapa[i][j] == 'o') {
                espaciosVacios++;
            }
        }
    }
    return espaciosVacios;
}

// Función para generar un mapa aleatorio
void generarMapaAleatorio(char mapa[nf][nc]) {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            if (rand() % 4 == 0) {
                mapa[i][j] = 'x';
            } else {
                mapa[i][j] = 'o';
            }
        }
    }
}

int main() {
    srand(time(NULL));  // Inicializar semilla aleatoria

    char mapa[nf][nc];
    int max_Z = nf * nc;

    cout << "Mapa del complejo:" << endl;
    generarMapaAleatorio(mapa);
    mostrarMapa(mapa);

    cout << "\nCantidad de filas libres: " << contarFilassinZ(mapa) << endl;
    cout << "Cantidad de columnas libres: " << contarColumnasinZ(mapa) << endl;

    int filasZ[max_Z], columnasZ[max_Z], cantidadZ = 0;
    coordenadasZ(mapa, filasZ, columnasZ, cantidadZ);

    cout << "\nPosiciones de los zombies en el mapa:" << endl;
    for (int i = 0; i < cantidadZ; i++) {
        cout << "Fila " << filasZ[i] << " -- Columna " << columnasZ[i] << endl;
    }

    cout << "\nTotal de zombies: " << contarZ(mapa) << endl;

    verificarEntrada(mapa);

    cout << "\nEspacios libres: " << calcularEspaciosVacios(mapa) << endl;

    return 0;
}
