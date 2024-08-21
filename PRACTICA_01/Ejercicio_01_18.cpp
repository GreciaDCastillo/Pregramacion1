// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 20/08/2024
// Número de ejercicio: 18
// Problema planteado: Calrcular número de Armtrong.

#include <iostream>
using namespace std;

int main() {
    int numero, original, suma = 0;
    cout << "Introduce un número: ";
    cin >> numero;

    original = numero;

    //Contar el número de digitos
    int aux = numero;
    int numDigitos = 0;

    while (aux > 0) {
        numDigitos++;
        aux /= 10;
    }
    // Calcular la suma de los dígitos elevados a la potencia del número de dígitos
    while (numero > 0) {
        int digito = numero % 10;
        int potencia = 1;
        
        for (int i = 0; i < numDigitos; i++) {
            potencia *= digito;
        }

        suma += potencia;
        numero /= 10;
    }

    if (suma == original) {
        cout << original << " es un número de Armstrong." << endl;
    } else {
        cout << original << " no es un número de Armstrong." << endl;
    }

    return 0;
}
