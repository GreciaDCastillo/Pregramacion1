// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/09/2024
// Número de ejercicio: 3
// Problema planteado: Convertir un número en base n a base 10.

#include <iostream>
#include <math.h>
using namespace std;

int base10(int numero, int base);

int main(){

    int numero, base;
    cout << "Introduce un número: ";
    cin >> numero;
    cout << "Introduce la base: ";
    cin >> base;

    cout << "\nEl número " << numero << " en base " << base << " es: " << base10(numero, base) << " en base 10" << endl;

    return 0;
}

int base10(int numero, int base){
    
    int base10 = 0;
    int posicion = 0;

    while (numero > 0){
        int digito = numero % 10; // Obtiene el ultimo dígito
        base10 += digito * pow(base, posicion); 
        numero /= 10; // Quita el ultimo dígito
        posicion++;
    }
    return base10;
}
