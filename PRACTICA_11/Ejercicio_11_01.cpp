// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 20/11/2024
// Número de ejercicio: 1
// Problema planteado: Escritura y lectura básica de archivos
/*
        Descripción: Escribe un programa que pida al usuario ingresar una lista de
        nombres y guarde cada nombre en un archivo de texto llamado
        nombres.txt. Después, el programa debe leer el archivo y mostrar todos los
        nombres en la consola.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void escribirNombres(const string& nombreArchivo);
void leerArchivo(const string& nombreArchivo);

int main() {
    string nombreArchivo = "nombres.txt";

    escribirNombres(nombreArchivo);
    leerArchivo(nombreArchivo);

    return 0;
}

void escribirNombres(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.fail()) {
        cout << "No se pudo crear el archivo." << endl;
        return;
    }

    cout << "Ingrese nombres (uno por linea), escriba '0' para terminar:" << endl;
    string nombre;
    while (true) {
        getline(cin, nombre);
        if (nombre == "0") break; 
        archivo << nombre << endl;
    }

    archivo.close();
    cout << "\nNombres guardados en " << nombreArchivo << "." << endl;
}

void leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.fail()) {
        cout << "No se pudo leer el archivo." << endl;
        return;
    }

    cout << "\nNombres guardados en el archivo:" << endl;
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}
