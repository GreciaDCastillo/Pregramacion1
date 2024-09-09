// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 06/09/2024
// Número de ejercicio: 1
// Problema planteado: Obtener secuencia de la serie 4, 6, 9, 13, 19, 28, 42.... de n terminos.


#include <iostream>
#include <math.h>
using namespace std;

int secuencia(int n);
int suma(int n);

int main() {
    int n;
    cout << "Introduce el número de terminos: ";
    cin >> n;
    cout << "\nsLa secuencia es: ";
    for (int i = 1; i <= n; i++) {
        cout << secuencia(i);
        if (i < n) {
            cout << " + ";
        }
    }

    cout << "\nLa suma es: " << suma(n) << endl;
    
    return 0;
}

int secuencia(int n) {
    int a = 4; 

    for (int i = 1; i < n; i++) {
        a = floor(a * 3 / 2); // formula: 	a(n) = floor(a(n-1)*3/2) con a(1) = 4   //   floor = redondear
    }
    return a;
}

int suma(int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += secuencia(i);
    }
    return suma;
}
