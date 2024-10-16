// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 16/10/2024
// Número de ejercicio: 10
// Problema planteado: Escribe un programa que, dado el formato comprimido, expanda la cadena al formato original.

#include <iostream>
using namespace std;

void descomprimirCadena(string comprimida) {
    string descomprimida = "";
    for (int i = 0; i < comprimida.length(); i++) {
        char caracter = comprimida[i];
        i++;
        int contador = comprimida[i] - '0'; // Convertir el carácter numérico a su valor entero
        for (int j = 0; j < contador; j++) {
            descomprimida += caracter;
        }
    }
    cout << "Cadena descomprimida: " << descomprimida << endl;
}

int main() {
    string cadenaComprimida;
    cout << "Introduce una cadena comprimida (ejemplo a2b3c2): ";
    getline(cin, cadenaComprimida);
    descomprimirCadena(cadenaComprimida);
    return 0;
}
