// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 1
// Problema planteado: Área de un triángulo.

#include <iostream>
using namespace std;

int main() {
    float base, altura, area;
    cout << "Introduce la base del triángulo: ";
    cin >> base;
    cout << "Introduce la altura del triángulo: ";
    cin >> altura;
    area = (base * altura) / 2;
    cout << "El área del triángulo es: " << area << endl;
    return 0;
}
