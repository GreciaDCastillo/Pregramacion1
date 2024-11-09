// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 06/11/2024
// Número de ejercicio: 1
// Problema planteado: Funcion recursiva de un numero dado y la suma de sus digitos.

#include <iostream>
using namespace std;
int suma_digitos(int);
int main() {
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;
    cout << "La suma de sus digitos es: " << suma_digitos(num) << endl;
    return 0;
}
int suma_digitos(int num) {
    if (num == 0) {
        return 0;
    } else {
        return (num % 10) + suma_digitos(num / 10);  // separacion del ultimo digito y la suma de los digitos
    }
}