// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 03/09/2024
// Número de ejercicio: 6
// Problema planteado:  Leer una hora y determinar si es de madrugada, mañada, de dia, etc.

#include <iostream>
using namespace std;

string horaDia(int hora);
int main() {
    int hora;
    cout << "Introduzca una hora: ";
    cin >> hora;
    
    string resultado = horaDia(hora);
    cout << resultado << endl;
    
    return 0;
}
string horaDia(int hora) {
    // 1 <= hora < 24
    if (hora >= 0 && hora < 6) {
        return "La hora es de madrugada";
    } else if (hora >= 6 && hora < 12) {
        return "La hora es de mañana";
    } else if (hora >= 12 && hora < 18) {
        return "La hora es de tarde";
    } else if (hora >= 18 && hora < 24) {
        return "La hora es de noche";
    } else {
        return "La hora no es valida";
    }
}