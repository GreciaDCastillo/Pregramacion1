// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 02/09/2024
// Número de ejercicio: 1
// Problema planteado: Leer una cantidad de segundos y realizar una función para
// convertirla a horas, minutos y segundos.

#include <iostream>
using namespace std;

int tiempoH(int segundos, int horas) ;

int tiempoM(int segundos, int minutos) ;

int tiempoS(int segundos) ;

int main() {
    int segundos, horas, minutos;

    cout << "Introduce los segundos: ";
    cin >> segundos;

    cout << "Son: " << tiempoH(segundos, horas) << " horas, " << tiempoM(segundos, minutos) << " minutos y " << tiempoS(segundos) << " segundos." << endl;

    return 0;
}

int tiempoH(int segundos, int horas) {
    horas = segundos / 3600; // 1 hora = 3600 segundos
    return horas;
}

int tiempoM(int segundos, int minutos) {
    minutos = segundos / 60; // 1 minuto = 60 segundos
    return minutos;
}

int tiempoS(int segundos) {
    return segundos;
}