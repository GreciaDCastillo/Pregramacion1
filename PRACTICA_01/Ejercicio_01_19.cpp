// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 20/08/2024
// Número de ejercicio: 19
// Problema planteado: Dias, horas, minutos y segundos a segundos.

#include <iostream>
using namespace std;

int main() {
    int dias, horas, minutos, segundos;
    int opcion;

    cout << "Selecciona la unidad de tiempo que deseas convertir a segundos:" << endl;
    cout << "1. Días" << endl;
    cout << "2. Horas" << endl;
    cout << "3. Minutos" << endl;
    cout << "4. Segundos" << endl;
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Introduce el tiempo en días: ";
            cin >> dias;
            segundos = dias * 86400; // 1 día = 86400 segundos
            break;
        case 2:
            cout << "Introduce el tiempo en horas: ";
            cin >> horas;
            segundos = horas * 3600; // 1 hora = 3600 segundos
            break;
        case 3:
            cout << "Introduce el tiempo en minutos: ";
            cin >> minutos;
            segundos = minutos * 60; 
            break;
        case 4:
            cout << "Introduce el tiempo en segundos: ";
            cin >> segundos;
            break;
        default:
            cout << "Opción no válida." << endl;
            return 1; 
    }

    cout << "El tiempo en segundos es: " << segundos << endl;
    return 0;
}
