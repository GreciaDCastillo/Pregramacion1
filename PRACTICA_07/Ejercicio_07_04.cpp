// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 15/10/2024
// Número de ejercicio: 4
// Problema planteado: Escribir un programa u comparar si eran iguales o no, sin importar mayúsculas o minúsculas.

#include <iostream>
using namespace std;

string convertirMinusculas(string cadena) { // Función para convertir una cadena a minúsculas

    for (int i = 0; i < cadena.length(); i++) {
        cadena[i] = tolower(cadena[i]);
    }
    return cadena;
}

void compararCadenas(string cad1, string cad2) {
    
    cad1 = convertirMinusculas(cad1);
    cad2 = convertirMinusculas(cad2);
    
    if (cad1 == cad2) {
        cout << "Las cadenas son iguales." << endl;
    } else {
        cout << "Las cadenas son diferentes." << endl;
    }
}

int main() {
    string cad1, cad2;
    cout << "Escriba una cadena: ";
    cin >> cad1;
    cout << "Escriba otra cadena: ";
    cin >> cad2;

    compararCadenas(cad1, cad2);
    return 0;
}
