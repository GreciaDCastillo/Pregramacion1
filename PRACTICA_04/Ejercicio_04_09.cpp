// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 18/09/2024
// Número de ejercicio: 9
// Problema planteado: Almacene en un arreglo las edades de varias personas (hasta ingresar un -1) y a partir
//                     de este arreglo determine la desviación típica

#include <iostream>
#include <cmath>
using namespace std;


void leerEdades(int edades[], int &numValidas);
double calcularPromedio(const int edades[], int numValidas);
double calcularDesviacionTipica(const int edades[], int numValidas, double promedio);

int main() {
    const int tamanoMax = 100; // Tamaño máximo del arreglo
    int edades[tamanoMax];
    int numValidas = 0;

    leerEdades(edades, numValidas);

    if (numValidas > 0) {
        double promedio = calcularPromedio(edades, numValidas);
        double desviacionTipica = calcularDesviacionTipica(edades, numValidas, promedio);

        cout << "\nPromedio de edades: " << promedio << endl;
        cout << "Desviación típica: " << desviacionTipica << endl;
    } else {
        cout << "No se ingresaron edades válidas." << endl;
    }

    return 0;
}


void leerEdades(int edades[], int &numValidas) {
    int edad = 0;
    cout << "Introduce las edades:" << endl;
    while (true) {
        cout << "Edad " << numValidas + 1 << ": ";
        cin >> edad;
        if (edad == -1) {
            break;
        }
        if (edad >= 0) {
            edades[numValidas] = edad;
            numValidas++;
        }
    }
}

double calcularPromedio(const int edades[], int numValidas) {
    double suma = 0.0;
    for (int i = 0; i < numValidas; i++) {
        suma += edades[i];
    }
    return suma / numValidas;
}

double calcularDesviacionTipica(const int edades[], int numValidas, double promedio) {
    double sumaDesviaciones = 0.0;
    for (int i = 0; i < numValidas; i++) {
        sumaDesviaciones += pow(edades[i] - promedio, 2);
    }
    return sqrt(sumaDesviaciones / numValidas);
}
