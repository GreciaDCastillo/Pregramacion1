// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 22/11/2024
// Número de ejercicio: 4
// Problema planteado: Búsqueda de texto en un archivo
/*
        Descripción: Escribe un programa que lea un archivo de texto llamado
        datos.txt y permita al usuario buscar una palabra o frase específica. El
        programa debe contar y mostrar cuántas veces aparece esa palabra o frase
        en el archivo.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int buscarTexto(const string& nombreArchivo, const string& textoBuscado);

int main() {
    string nombreArchivo = "datos.txt";
    string textoBuscado;

    cout << "Ingrese la palabra o frase que desea buscar: ";
    getline(cin, textoBuscado);

    int veces = buscarTexto(nombreArchivo, textoBuscado);

    if (veces >= 0) {
        cout << "La palabra o frase \"" << textoBuscado << "\" aparece " << veces << " veces en el archivo." << endl;
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << "." << endl;
    }

    return 0;
}

int buscarTexto(const string& nombreArchivo, const string& textoBuscado) {
    ifstream archivo(nombreArchivo); // Abrir archivo en modo lectura
    if (!archivo.is_open()) {
        return -1; // No se pudo abrir el archivo
    }

    string linea;
    int contador = 0;

    // Leer el archivo línea por línea
    while (getline(archivo, linea)) {
        size_t pos = linea.find(textoBuscado); // Buscar texto en la línea
        while (pos != string::npos) {         // Mientras se encuentre el texto
            contador++;
            pos = linea.find(textoBuscado, pos + textoBuscado.length()); // Buscar siguiente ocurrencia
        }
    }

    archivo.close(); 
    return contador;
}


