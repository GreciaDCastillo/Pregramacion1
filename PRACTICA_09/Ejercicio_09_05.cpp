// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 06/11/2024
// Número de ejercicio: 5
// Problema planteado: Funcion recursiva que devuelva el enésimo número en la secuencia de Fibonacci.


#include <iostream> 
using namespace std;

int fibonacci(int n);

int main() {
    int n;
    cout << "Introduce el numero de terminos: ";
    cin >> n;
    cout << "El enésimo numero en la secuencia de Fibonacci es: " << fibonacci(n) << endl;
    return 0;
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);  // Llamada recursiva para calcular el enésimo número
    }
}