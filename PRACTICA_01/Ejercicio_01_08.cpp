// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/08/2024
// Número de ejercicio: 8
// Problema planteado: Ingreso de letras.

#include <iostream>
using namespace std;

int main() {
    char letra;
    cout << "Introduce una letra: ";
    cin >> letra; // Le pedimos al usuario que ingrese una letra
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
        cout << "La letra es una vocal." << endl;
    } else if (letra >= 'a' && letra <= 'z') { // Definimos si la letra es una consonante.
        cout << "La letra es una consonante." << endl;
    } else { 
        cout << "La letra no es una vocal ni una consonante." << endl;
    }
    return 0;
}