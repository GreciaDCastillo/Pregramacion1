// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 03/09/2024
// Número de ejercicio: 7
// Problema planteado:  Dar la trabla de multiplicación de un número dado.

#include <iostream>
using namespace std;

int tablaMultiplicar(int num);
int main() {
    int num;
    cout << "Introduce un número: ";
    cin >> num;
    cout << endl;

    tablaMultiplicar(num);

    return 0;
}

int tablaMultiplicar(int num) {
    for (int i = 1; i <= 10; i++) {
        cout << num << " x " << i << " = " << num * i << endl; // Imprime la tabla de multiplicar
    }
    return 0; 
}