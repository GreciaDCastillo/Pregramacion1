// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 3
// Problema planteado: Calcular promedio de notas.

#include <iostream>
using namespace std;

int main() {
    int practicas, laboratorio, examen;
    float promedio;
    cout << "Introduce las calificaciones de las notas: "<< endl;
    cout << "Practicas: "; cin >> practicas;
    cout << "Laboratorio: "; cin >> laboratorio;
    cout << "Examen: "; cin >> examen;
    promedio = (practicas + laboratorio + examen) / 3;
    cout << "El promedio de las 3 notas es: " << promedio << endl;
    return 0;
}