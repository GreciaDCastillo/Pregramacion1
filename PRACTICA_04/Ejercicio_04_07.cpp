// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 18/09/2024
// Número de ejercicio: 7
// Problema planteado: Leer 10 números enteros y mostrarlos en pantalla. 
//                     Se detiene hasta que se introduzca un número negativo o se llene el vector. 

#include <iostream>
using namespace std;

void leerVector(int &numValidos, int vector[]);
void imprimirVector(int numValidos, int vector[]);

int main() {
    int num = 10;  
    int vector[num];
    int numValidos = 0; 

    cout << "Introduce los elementos del vector (ingresa un número negativo para detener):" << endl;
    leerVector(numValidos, vector);

    cout << "\nVector introducido:" << endl;
    imprimirVector(numValidos, vector);

    return 0;
}


void leerVector(int &numValidos, int vector[]) {
    for (int i = 0; i < 10; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> vector[i];
        if (vector[i] < 0) {
            break;  // Si el número es negativo, se detiene la lectura
        }
        numValidos++;  // Solo cuenta los elementos válidos
    }
}

void imprimirVector(int numValidos, int vector[]) { // Imprime los elementos del vector, solo los validos
    for (int i = 0; i < numValidos; i++) {
        cout << "   " << vector[i] << "   ";
    }
    cout << endl;
}
