// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 25/11/2024
// Número de ejercicio: 7
// Problema planteado: Promedio de calificaciones por estudiante
/*
        Descripción: Escribe un programa que lea un archivo calificaciones.txt,
        donde cada línea contiene el nombre de un estudiante seguido de varias
        calificaciones. El programa debe calcular el promedio de cada estudiante y
        escribirlo en un archivo promedios.txt en el formato Nombre Promedio.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void calcularPromedios(const string& archivoEntrada, const string& archivoSalida);
void mostrarPromedios(const string& archivoSalida);

int main() {
    string archivoEntrada = "calificaciones.txt";
    string archivoSalida = "promedios.txt";

    calcularPromedios(archivoEntrada, archivoSalida);

    cout << "El archivo \"" << archivoSalida << "\" se ha generado con los promedios de los estudiantes." << endl;

    mostrarPromedios(archivoSalida);

    return 0;
}

void calcularPromedios(const string& archivoEntrada, const string& archivoSalida) {
    ifstream entrada(archivoEntrada); // Abrir archivo de entrada
    ofstream salida(archivoSalida);  // Abrir archivo de salida

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo de entrada: " << archivoEntrada << endl;
        return;
    }

    if (!salida.is_open()) {
        cout << "No se pudo abrir el archivo de salida: " << archivoSalida << endl;
        return;
    }

    string linea;

    while (getline(entrada, linea)) {
        stringstream ss(linea);
        string nombre;
        vector<float> calificaciones;
        float calificacion;
        float suma = 0.0;

        // Extraer el nombre del estudiante
        ss >> nombre;

        // Leer las calificaciones restantes en la línea
        while (ss >> calificacion) {
            calificaciones.push_back(calificacion);
            suma += calificacion;
        }

        // Calcular el promedio
        float promedio = calificaciones.empty() ? 0 : suma / calificaciones.size();

        // Escribir el resultado en el archivo de salida
        salida << nombre << " " << promedio << endl;
    }

    entrada.close();
    salida.close();
}

void mostrarPromedios(const string& archivoSalida) {
    ifstream entrada(archivoSalida); 

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo de salida: " << archivoSalida << endl;
        return;
    }

    string linea;

    while (getline(entrada, linea)) {
        cout << linea << endl;
    }

    entrada.close();
}
