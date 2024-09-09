// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/09/2024
// Número de ejercicio: 5
// Problema planteado: Simular lanzamiento de una moneda y determinar su porcentaje de caras.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int moneda() {
    return rand() % 2;
}
double porcentaje(int x, int y) {
    if (y == 0) {
        return 0;
    } else {
        return (x * 100) / y;
    }
}
int main() {
    int num;
    int caras = 0;
    int sellos = 0;

    cout << "Introduce la cantidad de veces que quieres lanzar la moneda: ";
    cin >> num;

    srand(time(NULL));

    cout << "\nCaras: " << 1 << " Sellos: " << 0 << endl; 
    cout << "Lanzamiento de la moneda: ";

    

    for (int i = 0; i < num; i++) {
        int resultado = moneda();
        cout << resultado << " ";
        if (resultado == 1) {
            caras++;
        } else {
            sellos++;
        }
    }

    cout << endl;

    cout << "El porcentaje de caras es: " << porcentaje(caras, num) << "%" << endl;
    cout << "El porcentaje de sellos es: " << porcentaje(sellos, num) << "%" << endl;

    return 0;
}