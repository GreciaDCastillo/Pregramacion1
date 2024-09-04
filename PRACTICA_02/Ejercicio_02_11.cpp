// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 04/09/2024
// Número de ejercicio: 11
// Problema planteado:  Generar secuendia de N terminos. Secuencia: 1, 1, 2, 4, 8, 16, 23, 28, 38, 49....

#include <iostream>
using namespace std;

// Función para sumar las cifras de un número
int sumaDeCifras(int num) {
    int suma = 0;
    while (num > 0) {
        suma += num % 10;
        num /= 10;
    }
    return suma;
}

void generarSecuencia(int n) {
    int actual = 1;     // Primer número de la secuencia
    int acumulado = 2;  // Suma de cifras de todos los números anteriores (1+1)

    cout << 1 << ", " << 1;

    for (int i = 3; i <= n; i++) {
        actual = acumulado; // El siguiente número es la suma acumulada
        cout << ", " << actual;

        acumulado += sumaDeCifras(actual);
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Introduce el número de términos que deseas generar: ";
    cin >> n;

    generarSecuencia(n);

    return 0;
}



