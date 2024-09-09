// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/09/2024
// Número de ejercicio: 2
// Problema planteado: Simular el lanzamiento de un dado n veces, y mostrar la frecuencia de repetición de caras pares.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int lanzarDado();
int par(int num);

int main() {
    int num;
    cout << "Introduce el número de veces que quieres lanzar el dado: ";
    cin >> num;

    srand(time(NULL));

    cout << "Lanzamiento del dado: ";
    
    cout << "\nLa frecuencia de pares es: " << par(num) << endl;

    return 0;
}

int lanzarDado() {
    return rand() % 6 + 1;
}

int par(int num) {
    int pares = 0;
    for (int i = 0; i < num; i++) {
        int resultado = lanzarDado();
        cout << resultado << " ";
        if (resultado % 2 == 0) {
            pares++;
        }
    }
    return pares;
}