// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/09/2024
// Número de ejercicio: 4
// Problema planteado: Obtener la serie: 1 - 4 + 9 - 16 + 25 - 36 + ... Para n términos.

#include <iostream>
using namespace std;

int serie(int n) {
    int suma = 0;

    for (int i = 1; i <= n; i++) {
        int termino = i * i; // Calcula el cuadrado del número

        if (i % 2 == 0) {
            cout << "- " << termino;
            suma -= termino; // Resta el término si es par
        } else {
            if (i > 1) {
                cout << " + "; // Agrega "+" solo si no es el primer término
            }
            cout << termino;
            suma += termino; // Suma el término si es impar
        }
    }
    
    cout << endl;
    return suma;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de términos: ";
    cin >> n;

    int resultado = serie(n);
    cout << "La suma de la serie es: " << resultado << endl;
    
    return 0;
}
