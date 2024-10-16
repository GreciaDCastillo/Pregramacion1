// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 16/10/2024
// Número de ejercicio: 12
// Problema planteado: Escribe un programa que divida una cadena en tokens (subcadenas) separadas por un delimitador.

#include <iostream>
using namespace std;

void dividirCadena(string cadena, char delimitador) {
    int inicio = 0;
    int index = 0;
    
    while (index < cadena.length()) {
        if (cadena[index] == delimitador) {  // Verifica si el caracter es el delimitador
            cout << cadena.substr(inicio, index - inicio) << endl; // Imprime la subcadena
            inicio = index + 1;
        }
        index++;
    }
    cout << cadena.substr(inicio, index - inicio) << endl;
}

int main() {
    string cadena;
    char delimitador;

    cout << "Introduce una cadena: ";
    getline(cin, cadena);
    cout << "Introduce el delimitador: ";
    cin >> delimitador;

    dividirCadena(cadena, delimitador);

    return 0;
}