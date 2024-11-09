// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/11/2024
// Número de ejercicio: 12
// Problema planteado: Realizar un algoritmo recursivo que nos diga si una cadena de caracteres es simétrica.

#include <iostream>
using namespace std;

bool esPalindromo(string);

int main() {
    string cadena;
    cout << "Escribe una cadena: ";
    cin >> cadena;
    if (esPalindromo(cadena)) {
        cout << "La cadena es palindromo" << endl;
    } else {
        cout << "La cadena no es palindromo" << endl;
    }
    return 0;
}

bool esPalindromo(string cadena) {
    if (cadena.length() <= 1) { // Caso base
        return true;
    }
    if (cadena[0] != cadena[cadena.length() - 1]) { // Caso recursivo para verificar si la cadena es palíndromo
        return false;
    }
    return esPalindromo(cadena.substr(1, cadena.length() - 2)); // Llamada recursiva para verificar el resto de la cadena
}
