// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 03/09/2024
// Número de ejercicio: 3
// Problema planteado: Calculo distancia de dos puntos en el plano cartesiano. 

#include <iostream>
#include <math.h>
using namespace std;

int distancia(int x1, int y1, int x2, int y2);
int main() {
    int x1, y1, x2, y2;
    x1 = y1 = x2 = y2 = 0;
    float d;
    cout << "Introduce el valor de x1: ";
    cin >> x1;
    cout << "Introduce el valor de y1: ";
    cin >> y1;
    cout << "Introduce el valor de x2: ";
    cin >> x2;
    cout << "Introduce el valor de y2: ";
    cin >> y2;
    d = distancia(x1, y1, x2, y2);
    cout << "La distancia entre los puntos es: " << d << endl;
    return 0;
}

int distancia(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // Distancia = √(x2-x1)^2 + (y2-y1)^2
}