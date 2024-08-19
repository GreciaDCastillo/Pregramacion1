// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 2
// Problema planteado: Volumen de una esfera.

#include <iostream>
using namespace std;

int main() {
    float radio, volumen;
    cout << "Introduce el radio de la esfera: ";
    cin >> radio;
    volumen = (4.0 / 3.0) * 3.14 * radio * radio * radio;
    cout << "El volumen de la esfera es: " << volumen << endl;
    return 0;
}
