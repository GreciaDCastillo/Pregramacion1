// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/09/2024
// Número de ejercicio: 7
// Problema planteado: Generar secuencia.

/*
        1 1 2 3 4 …………..n
        1 1 2 3 4……. n-1
        1 1 2 3 …...n-2
        1 ……….
        1 1

*/

#include <iostream>
using namespace std;

void secuencia(int num);

int main() {
    int num;
    cout << "Ingresa un numero: ";
    cin >> num;

    secuencia(num);

    return 0;
}

void secuencia(int num) {

    for (int i = num; i >= 1; i--) { // Controla la cantidad de filas (inicia desde n y disminuye hasta 1)
        for (int j = 1; j <= i; j++) { // Controla los números impresos en cada fila (de 1 a i)
            cout << j << " ";
        }
        cout << endl;
    }  
}