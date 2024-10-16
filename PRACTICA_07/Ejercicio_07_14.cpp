// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 16/10/2024
// Número de ejercicio: 14s
// Problema planteado: Escribe un programa que encuentre y muestre la palabra más larga en una oración.

#include <iostream>
using namespace std;

void palabraMasLarga(string oracion) {
    string palabraMasLarga = "";
    string palabra = "";
    for (int i = 0; i < oracion.length(); i++) {
        if (oracion[i] == ' ') {
            if (palabra.length() > palabraMasLarga.length()) {
                palabraMasLarga = palabra;
            }
            palabra = "";
        } else {
            palabra += oracion[i];
        }
    }
    if (palabra.length() > palabraMasLarga.length()) {
        palabraMasLarga = palabra;
    }
    cout << "La palabra más larga es: " << palabraMasLarga << endl;
}

int main() {
    string oracion;
    cout << "Ingresa una oración: ";
    getline(cin, oracion);
    palabraMasLarga(oracion);    
    return 0;
}