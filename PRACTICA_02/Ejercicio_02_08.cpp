// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 04/09/2024
// Número de ejercicio: 8
// Problema planteado:  Imprimir N números en la secuencia de Fibonacci.

#include <iostream>
using namespace std;

int fibonacci(int num);
int main(){
    
    int num;
    cout << "Introduce un número: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}
int fibonacci(int num){
    if ( num <= 1) {
        return num;
    }else {
        return fibonacci(num-1) + fibonacci(num-2);
    }
}


