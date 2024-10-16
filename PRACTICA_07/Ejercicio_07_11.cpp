// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 16/10/2024
// Número de ejercicio: 11
// Problema planteado: Escribe un programa que elimine todos los dígitos de una cadena. 

#include <iostream>
using namespace std;

void eliminarDigitos(string cadena) {
        for (int i = 0; i < cadena.length(); i++) { // Recorre la cadena
        if (cadena[i] >= '0' && cadena[i] <= '9') { // Verifica si el caracter es un dígito
            cadena.erase(i, 1); // Elimina el dígito
            i--;
        }
    }
    cout << "Cadena sin dígitos: " << endl << cadena << endl;
}

int main() {
    string cadena;
    cout << "Introduce una cadena: ";
    getline(cin, cadena);
    eliminarDigitos(cadena);
    return 0;    
}