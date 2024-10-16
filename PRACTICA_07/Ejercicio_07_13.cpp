// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 16/10/2024
// Número de ejercicio: 13
// Problema planteado: Escribe un programa que invierta el orden de las palabras en una oración
//                     sin cambiar el orden de los caracteres dentro de cada palabra

#include <iostream>
using namespace std;

void invertirPalabras(string oracion) {
    string palabra = "";
    
    for (int i = oracion.length() - 1; i >= 0; i--) {
        if (oracion[i] == ' ') {
            // Cuando encontramos un espacio, imprimimos la palabra
            cout << palabra << " ";
            palabra = "";  // Reiniciamos la palabra
        } else {
            palabra = oracion[i] + palabra;
        }
    }
    cout << palabra << endl;
}

int main() {
    string oracion;
    cout << "Ingresa una oración: ";
    getline(cin, oracion);
    
    cout << "La oración con las palabras invertidas es: ";
    invertirPalabras(oracion);
    
    return 0;
}
