// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 18/09/2024
// Número de ejercicio: 11
// Problema planteado:  De un arreglo de ventas de 12 meses, obtener el més con ventas más altas y el total de ventas.

#include <iostream>
#include <string>
using namespace std;

void leerVentas(double ventas[], int tam);
double obtenerVentasMaximas(const double ventas[], int tam);
void obtenerMesesVentasMaximas(const double ventas[], const string meses[], int tam, double ventasMaximas);
double obtenerTotalVentas(const double ventas[], int tam);

int main() {
    const int tam = 12;
    string meses[tam] = {"Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};
    double ventas[tam];

    leerVentas(ventas, tam);

    double ventasMaximas = obtenerVentasMaximas(ventas, tam);
    cout << "\nVentas máximas: " << ventasMaximas << endl;

    cout << "Mes(es) con ventas máximas: ";
    obtenerMesesVentasMaximas(ventas, meses, tam, ventasMaximas);

    double totalVentas = obtenerTotalVentas(ventas, tam);
    cout << "\nTotal de ventas: " << totalVentas << endl;

    return 0;
}

void leerVentas(double ventas[], int tam) {
    cout << "Introduce las ventas para cada mes: " << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Ventas en el mes " << i + 1 << ": ";
        cin >> ventas[i];
    }
}

double obtenerVentasMaximas(const double ventas[], int tam) {
    double max = ventas[0];
    for (int i = 1; i < tam; i++) {
        if (ventas[i] > max) {
            max = ventas[i];
        }
    }
    return max;
}

void obtenerMesesVentasMaximas(const double ventas[], const string meses[], int tam, double ventasMaximas) {
    for (int i = 0; i < tam; i++) {
        if (ventas[i] == ventasMaximas) { // El elemento de la posición i es igual al elemento de la posición ventasMaximas
            cout << meses[i] << " ";
        }
    }
    cout << endl;
}

double obtenerTotalVentas(const double ventas[], int tam) {
    double total = 0;
    for (int i = 0; i < tam; i++) {
        total += ventas[i];
    }
    return total;
}
