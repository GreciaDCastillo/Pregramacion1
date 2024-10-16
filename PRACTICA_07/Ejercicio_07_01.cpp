// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 15/10/2024
// Número de ejercicio: 1
// Problema planteado: Escribir un programa que tome una cadena y la devuelva al reves.

#include <iostream>
using namespace std;

void invertirCadena(string cadena) {
    for (int i = cadena.size() - 1; i >= 0; i--) { // Recorre la cadena desde el final hasta el principio
        cout << cadena[i];
    }
}

int main() {
    string cadena;

    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    
    cout << "\nCadena invertida: ";
    invertirCadena(cadena);


    return 0;
}

