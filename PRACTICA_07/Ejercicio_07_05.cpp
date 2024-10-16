// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 15/10/2024
// Número de ejercicio: 5
// Problema planteado: Escribir un programa que cuente cuántas palabras hay en una oración. (Considera que las palabras están separadas por un espacio.)

#include <iostream>
using namespace std;

void contarPalabras(string oracion, int palabras) {
     for (int i = 0; i < oracion.length(); i++) {
         if (oracion[i] == ' ') {
             palabras++;
         }
    }  
    cout << "\nHay " << palabras << " palabras en la oración." << endl;
}
int main() {
    string oracion;
    int palabras = 1;
    cout << "Escriba una oración: ";
    getline(cin, oracion);

    contarPalabras(oracion, palabras);

    return 0;
}