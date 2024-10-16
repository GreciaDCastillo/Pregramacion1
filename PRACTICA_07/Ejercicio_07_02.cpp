// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 15/10/2024
// Número de ejercicio: 2
// Problema planteado: Escribir un programa que cuente el número de vocales de una cadena dada.

#include <iostream>
using namespace std;

void cadenaVocales(string cadena) {

    int vocales = 0;
    for (int i = 0; i < cadena.length(); i++) { // Recorre la cadena en busca de vocales
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u') {
            vocales++;
        }
    }
    cout << "\nLa cadena tiene " << vocales << " vocales" << endl;

}


int main() {
    
    string cadena;
    cout << "Escriba una cadena de texto: ";
    cin.ignore();
    getline(cin, cadena);
    cadenaVocales(cadena);

    return 0;
}