// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 25/11/2024
// Número de ejercicio: 8
// Problema planteado: Contador de líneas, palabras y caracteres
/*
        Descripción: Escribe un programa que lea un archivo de texto llamado
        documento.txt y cuente el número total de líneas, palabras y caracteres. Al
        final, el programa debe mostrar estos totales en la consola.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void contarLineasPalabrasCaracteres(const string& archivoEntrada);

int main() {
    string archivoEntrada = "documento.txt";

    contarLineasPalabrasCaracteres(archivoEntrada);

    return 0;
}

void contarLineasPalabrasCaracteres(const string& archivoEntrada) {
    ifstream entrada(archivoEntrada); // Abrir archivo de entrada

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo: " << archivoEntrada << endl;
        return;
    }

    string linea;
    int totalLineas = 0, totalPalabras = 0, totalCaracteres = 0;

    // Leer el archivo línea por línea
    while (getline(entrada, linea)) {
        totalLineas++; // Incrementar el contador de líneas
        totalCaracteres += linea.size(); // Contar los caracteres de la línea

        stringstream ss(linea);
        string palabra;

        while (ss >> palabra) {
            totalPalabras++;
        }

        totalCaracteres++;
    }

    entrada.close();

    cout << "Total de líneas: " << totalLineas << endl;
    cout << "Total de palabras: " << totalPalabras << endl;
    cout << "Total de caracteres: " << totalCaracteres << endl;
}
