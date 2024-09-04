// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 03/09/2024
// Número de ejercicio: 5
// Problema planteado:  Leer u año y un mes y determinar si es bisiesto.

#include <iostream>
using namespace std;

int esBisiesto(int anio);
int diasMes(int mes, int anio);
int main() {
    int anio, mes;
    cout << "Introduce el año: ";
    cin >> anio;
    cout << "Introduce el mes (1-12); ";
    cin >> mes;

    int dias = diasMes(mes, anio);
    if (dias != 0) {
        cout << "El mes " << mes <<" del año "<< anio << " tiene " << dias << " dias." << endl;
    } else {
        cout << "El mes es incorrecto." << endl;
    }
}

int esBisiesto(int anio) {
    return (anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0); // Verifica si el año es bisiesto, si es divisible por 400 o 4 y no por 100
}


int diasMes(int mes, int anio) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (esBisiesto(anio)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 0; // Valor incorrecto
    }                                                                                               
}