// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 15/10/2024
// Número de ejercicio: 3
// Problema planteado: Escribir un programa que elimine todos los espacios de una cadena.

#include <iostream>
using namespace std;

void eliminarEspacios(string cadena) {
    string nuevaCadena = ""; // Cadena sin espacios
    for (int i = 0; i < cadena.length(); i++) {
        if (cadena[i] != ' ') {
            nuevaCadena += cadena[i]; // Agrega cada caracter a la nueva cadena sin espacios
        }
    }
    cout << nuevaCadena << endl;
}
int main() {
    
    string cadena;
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    cout << "\nCadena sin espacios: ";
    eliminarEspacios(cadena);

    return 0;
}