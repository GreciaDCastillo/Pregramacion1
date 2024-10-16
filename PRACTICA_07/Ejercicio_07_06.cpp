// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 15/10/2024
// Número de ejercicio: 6
// Problema planteado: Escribir un programa que determine si una cadena es un palíndromo.
// (se lee gual de izquierda a derecha que de derecha a izquierda).

#include <iostream>
using namespace std;

string invertirCadena(string cadena) {
    string invertida = "";
    for (int i = cadena.length() - 1; i >= 0; i--) { // Recorre la cadena desde el final hasta el principio
        invertida += cadena[i];
    }
    return invertida;
}

void esPalindromo(string cadena) {
    string cadenaInvertida = invertirCadena(cadena); // Invierte la cadena
    
    if (cadena == cadenaInvertida) {
        cout << "Es un palindromo" << endl;
    } else {
        cout << "No es un palindromo" << endl;
    }
    
}

int main() {
    string cadena;
    cout << "Escribe una cadena: ";
    cin >> cadena;

    esPalindromo(cadena);
    
    return 0;
}
