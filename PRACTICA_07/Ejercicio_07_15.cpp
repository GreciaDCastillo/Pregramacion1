// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 16/10/2024
// Número de ejercicio: 15
// Problema planteado: Escribe un programa que valide si una cadena ingresada cumple con el formato básico de una dirección de correo electrónico

#include <iostream>
using namespace std;

void esEmail(string email) {
    int arrobaPos = -1;
    int puntoPos = -1;

    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            arrobaPos = i;
        } else if (email[i] == '.') {
            puntoPos = i;
        }
    }

    if (arrobaPos == -1 || puntoPos == -1) {
        cout << "La cadena no es un correo electrónico" << endl;
    } else if (arrobaPos > puntoPos) {
        cout << "La cadena no es un correo electrónico" << endl;
    } else {
        cout << "La cadena es un correo electrónico" << endl;
    }
}

int main() {
    string email;
    cout << "Escribe tu correo electrónico: ";
    cin >> email;

    esEmail(email);
    return 0;
}