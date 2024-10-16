// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 15/10/2024
// Número de ejercicio: 8
// Problema planteado: Escribe un programa que  alterne entre mayúsculas y minúsculas en una cadena.

#include <iostream>
using namespace std;

int main() {
    string cadena;
    cout << "Introduce una cadena: ";
    getline(cin, cadena);
    for (int i = 0; i < cadena.length(); i++) {
        if (cadena[i] % 2 == 0) { // Cambia entre mayúsculas y minúsculas
            cadena[i] = tolower(cadena[i]); 
        } else {
            cadena[i] = toupper(cadena[i]);
        }
    }
    cout << "Cadena alterada: " << cadena << endl;
    return 0;
}

