// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/11/2024
// Número de ejercicio: 10
// Problema planteado:  Realizar un algoritmo recursivo que genere la siguiente formula:
//                     Q(n) = 1^2 + 2^2 + 3^2 + 4^2 + ... + n^2 

#include <iostream>
using namespace std;

int sumatoria(int num);

int main() {
    int num;
    cout << "Ingrese el valor de n: ";
    cin >> num; 

    cout << "Q(" << num << ") = ";
    for (int i = 1; i <= num; i++) {
        cout << i  << "^2";
        if (i < num) {
            cout << " + ";
        }
    }
    cout << " = " << sumatoria(num) << endl;  

    return 0;
}

int sumatoria(int num) { 
    if (num == 1) {
        return 1;
    }
    else {
        return num * num + sumatoria(num - 1); // Llamada recursiva para calcular la sumatoria 
    }
}