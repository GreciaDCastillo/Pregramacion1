// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 18/09/2024
// Número de ejercicio: 8
// Problema planteado: 
/*
        Un arreglo constante contiene la producción en toneladas métricas de 6 minerales, y
        otro contiene los nombres de estos minerales, para obtener:
        - Buscar por nombre de mineral y desplegar la producción
        - Ordenar del mayor al menor
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Declaración de funciones
void buscarMineral(const string minerales[], const double produccion[], int tamano, const string& nombre);
void ordenarPorProduccion(string minerales[], double produccion[], int tamano);
void mostrarMinerales(const string minerales[], const double produccion[], int tamano);

int main() {
    const int tamano = 6;  // Número de minerales

    // Arreglos constantes
    string minerales[tamano] = {"SN", "SB", "AU", "PT", "AG", "CU"};
    double produccion[tamano] = {998.000, 876.500, 786.670, 636.143, 135.567, 109.412};

    // Buscar por nombre de mineral
    string nombreMineral;
    cout << "Introduce el nombre del mineral para buscar su producción: ";
    cin >> nombreMineral;
    buscarMineral(minerales, produccion, tamano, nombreMineral);

    // Ordenar por producción y mostrar el resultado
    cout << "\nMinerales ordenados por producción (de mayor a menor):" << endl;
    ordenarPorProduccion(minerales, produccion, tamano);
    mostrarMinerales(minerales, produccion, tamano);

    return 0;
}


void buscarMineral(const string minerales[], const double produccion[], int tamano, const string& nombre) {
    bool encontrado = false;
    for (int i = 0; i < tamano; i++) {
        if (minerales[i] == nombre) {
            cout << "Producción del mineral " << nombre << ": " << fixed << setprecision(3) << produccion[i] << " TM" << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Mineral no encontrado." << endl;
    }
}


void ordenarPorProduccion(string minerales[], double produccion[], int tamano) {
    for (int i = 0; i < tamano - 1; i++) {
        for (int j = 0; j < tamano - i - 1; j++) {
            if (produccion[j] < produccion[j + 1]) {
                // Intercambiar las producciones
                swap(produccion[j], produccion[j + 1]);
                // Intercambiar los nombres de los minerales correspondientes
                swap(minerales[j], minerales[j + 1]);
            }
        }
    }
}


void mostrarMinerales(const string minerales[], const double produccion[], int tamano) {
    cout << "Mineral    Producción (TM)" << endl;
    for (int i = 0; i < tamano; i++) {
        cout << minerales[i] << setw(12) << fixed << setprecision(3) << produccion[i] << endl;
    }
}
