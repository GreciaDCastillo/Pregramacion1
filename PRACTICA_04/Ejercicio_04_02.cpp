// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 18/09/2024
// Número de ejercicio: 2
// Problema planteado: Escribir un programa que lea un arretglo de voltios y desplegue la matriz de 3x3.

#include <iostream>
using namespace std;

void desplegar( int num, double matriz[] );

int main() {

    int num = 9;
    double arreglo[num];

    cout << "Introduce los valores: " << endl;

    for (int i = 0; i < num; i++) {
        cout << "Voltio[" << i+1 << "]: ";
        cin >> arreglo[i];
    }

    cout << "\nLa matriz de voltios es: " << endl;
    cout << endl;
    desplegar( num, arreglo );
    return 0;
}

void desplegar( int num, double arreglo[] ) {

    for (int i = 0; i < num; i++) {
        cout << "\t" << arreglo[i] << "\t";

        if ((i + 1) % 3 == 0) // Imprime una nueva linea cada 3 elementos
            cout << endl;
    }
    
} 