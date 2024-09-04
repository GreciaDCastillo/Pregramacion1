// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 04/09/2024
// Número de ejercicio: 15
// Problema planteado:  Generar un numero aleatorio, no mayor a dos dígitos y mostrar su numero litral.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void convertirUnidad(int num);
void convertirDecena(int num);
void convertirEspecial(int num);

int main() {
    srand(time(NULL));
    int num = rand() % 99 + 1; // Generar un número aleatorio entre 1 y 99

    cout << "Numero aleatorio: " << num << endl;
    cout << "Numero literal: ";

    if (num < 10) {
        convertirUnidad(num);
    } else if (num < 20) {
        convertirEspecial(num);
    } else {
        convertirDecena(num / 10);
        if (num % 10 != 0) {
            cout << " y ";
            convertirUnidad(num % 10);
        }
    }

    cout << endl;
    return 0;
}

void convertirUnidad(int num) {
    if (num == 1)
        cout << "uno";
    else if (num == 2)
        cout << "dos";
    else if (num == 3)
        cout << "tres";
    else if (num == 4)
        cout << "cuatro";
    else if (num == 5)
        cout << "cinco";
    else if (num == 6)
        cout << "seis";
    else if (num == 7)
        cout << "siete";
    else if (num == 8)
        cout << "ocho";
    else if (num == 9)
        cout << "nueve";
}

void convertirEspecial(int num) {
    if (num == 10)
        cout << "diez";
    else if (num == 11)
        cout << "once";
    else if (num == 12)
        cout << "doce";
    else if (num == 13)
        cout << "trece";
    else if (num == 14)
        cout << "catorce";
    else if (num == 15)
        cout << "quince";
    else if (num == 16)
        cout << "dieciséis";
    else if (num == 17)
        cout << "diecisiete";
    else if (num == 18)
        cout << "dieciocho";
    else if (num == 19)
        cout << "diecinueve";
    else if (num == 20)
        cout << "veinte";
}

void convertirDecena(int decena) {
    if (decena == 2)
        cout << "veinti";
    else if (decena == 3)
        cout << "treinta";
    else if (decena == 4)
        cout << "cuarenta";
    else if (decena == 5)
        cout << "cincuenta";
    else if (decena == 6)
        cout << "sesenta";
    else if (decena == 7)
        cout << "setenta";
    else if (decena == 8)
        cout << "ochenta";
    else if (decena == 9)
        cout << "noventa";
}

 
