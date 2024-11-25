// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 20/11/2024
// Número de ejercicio: 2
// Problema planteado: Contador de palabras en un archivo
/*
        Descripción: Escribe un programa que lea un archivo de texto llamado
        texto.txt y cuente cuántas palabras contiene. Una "palabra" se define como
        cualquier secuencia de caracteres separada por espacios o saltos de línea.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int contarPalabras(const string& nombreArchivo);

int main() {
    string nombreArchivo = "texto.txt";

  
    int totalPalabras = contarPalabras(nombreArchivo);

    if (totalPalabras >= 0) {
        cout << "El archivo contiene " << totalPalabras << " palabras." << endl;
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }

    return 0;
}

// Función para contar palabras en un archivo
int contarPalabras(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo); // Abrir archivo en modo lectura
    if (!archivo.is_open()) {
        return -1; // Error: No se pudo abrir el archivo
    }

    int contadorPalabras = 0;
    string palabra;

    // Leer cada palabra del archivo
    while (archivo >> palabra) {
        contadorPalabras++; // Incrementar el contador por cada palabra
    }

    archivo.close(); // Cerrar archivo
    return contadorPalabras; // Retornar el número total de palabras
}



