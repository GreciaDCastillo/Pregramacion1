// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 1
// Problema planteado: Convercion de grados.

#include <iostream>
using namespace std;

int main() {
    int gradosC;
    cout << "Introduce los grados centigrados: ";
    cin >> gradosC;
    float gradosK = (gradosC + 273.15);
    cout << "Los grados kelvin son: " << gradosK << endl;
    return 0;
}
