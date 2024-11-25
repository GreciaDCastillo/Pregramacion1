// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 25/11/2024
// Número de ejercicio: 6
// Problema planteado: Filtrado de registros de temperatura
/*
        Descripción: Escribe un programa que lea un archivo de texto llamado
        temperaturas.txt, donde cada línea contiene el nombre de una ciudad
        seguido de su temperatura promedio del día. El programa debe generar un
        archivo altas_temperaturas.txt que solo incluya las ciudades con
        temperaturas superiores a N°C.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


void filtrarTemperaturas(const string& archivoEntrada, const string& archivoSalida, float temperaturaUmbral);
void mostrarCiudades(const string& archivoSalida);

int main() {
    string archivoEntrada = "temperaturas.txt";
    string archivoSalida = "altas_temperaturas.txt";
    float temperaturaUmbral;

    cout << "Ingrese la temperatura umbral: ";
    cin >> temperaturaUmbral;

    filtrarTemperaturas(archivoEntrada, archivoSalida, temperaturaUmbral);

    cout << "El archivo \"" << archivoSalida << "\" se ha generado con las ciudades que tienen temperaturas superiores a " << temperaturaUmbral << "°C." << endl;
    mostrarCiudades(archivoSalida);
    
    return 0;
}


void filtrarTemperaturas(const string& archivoEntrada, const string& archivoSalida, float temperaturaUmbral) {
    ifstream entrada(archivoEntrada); // Abrir archivo de entrada
    ofstream salida(archivoSalida);  // Abrir archivo de salida

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo de entrada: " << archivoEntrada << endl;
        return;
    }

    if (!salida.is_open()) {
        cout << "No se pudo abrir el archivo de salida: " << archivoSalida << endl;
        return;
    }

    string linea;
    // Leer línea por línea el archivo de entrada
    while (getline(entrada, linea)) {
        stringstream ss(linea);
        string ciudad;
        float temperatura;

        ss >> ciudad >> temperatura;

        if (temperatura > temperaturaUmbral) {
            salida << ciudad << " " << temperatura << endl; // Escribir en el archivo de salida
        }
    }

    entrada.close();
    salida.close();
}


void mostrarCiudades(const string& archivoSalida) {
    ifstream salida(archivoSalida);

    if (!salida.is_open()) {
        cout << "No se pudo abrir el archivo de salida: " << archivoSalida << endl;
        return;
    }

    string linea;
    while (getline(salida, linea)) {
        cout << linea << endl;
    }

    salida.close();
}
