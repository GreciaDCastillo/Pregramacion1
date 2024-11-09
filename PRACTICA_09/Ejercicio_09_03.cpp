// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 06/11/2024
// Número de ejercicio: 3
// Problema planteado: Funcion recursiva que reciba una cadena y devuelva la misma cadena invertida.

#include <iostream>
using namespace std;
string invertirCadena(string cadena);

int main () {
    string cadena;
    cout << "Ingrese una cadena: "; 
    getline(cin, cadena);

    cout << "Cadena invertida: " << invertirCadena(cadena) << endl;

    return 0;
}

string invertirCadena(string cadena) {
    if (cadena.length() == 1) {
        return cadena;
    } else {
        return invertirCadena(cadena.substr(1)) + cadena[0]; // Recursividad para invertir la cadena
    }
}