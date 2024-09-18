// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 18/09/2024
// Número de ejercicio: 3
// Problema planteado: Calcular la varianza de una lista de calificaciones.

#include <iostream>
#include <cmath>
using namespace std;

void leerCalificaciones(int num, int calificaciones[], double &promedio);
void leerDesviaciones(int num, int calificaciones[], double desviaciones[], double promedio);
double calcularVarianza(int num, double sumaDesviaciones);

int main() {
    int num = 0;

    cout << "Introduce el número de calificaciones: ";
    cin >> num;

    int calificaciones[num];
    double desviaciones[num];
    double promedio;

    leerCalificaciones(num, calificaciones, promedio);
    leerDesviaciones(num, calificaciones, desviaciones, promedio);

  
    double sumaDesviaciones = 0.0;
    for (int i = 0; i < num; i++) {
        sumaDesviaciones += desviaciones[i] * desviaciones[i]; // Suma de las desviaciones al cuadrado
    }
    
    cout << "\nVarianza: " << calcularVarianza(num, sumaDesviaciones) << endl;

    return 0;
}

void leerCalificaciones(int num, int calificaciones[], double &promedio) {

    int sumaTotal = 0;
    for (int i = 0; i < num; i++) {
        cout << "Calificación " << i + 1 << ": ";
        cin >> calificaciones[i];
        sumaTotal += calificaciones[i];
    }
    promedio = static_cast<double>(sumaTotal) / num;
}

void leerDesviaciones(int num, int calificaciones[], double desviaciones[], double promedio) {
    cout << "\nCalificación y desviación: " << endl; 
    for (int i = 0; i < num; i++) {
        desviaciones[i] = calificaciones[i] - promedio;
        cout << "Calificación: " << calificaciones[i] << ": Desviación " << desviaciones[i] << endl;
    }
}

double calcularVarianza(int num, double sumaDesviaciones) {
    return sumaDesviaciones / num;
}



