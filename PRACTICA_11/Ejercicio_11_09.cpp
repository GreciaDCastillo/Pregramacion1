// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 25/11/2024
// Número de ejercicio: 9
// Problema planteado: Cifrado de un archivo de texto (Cifrado César)
/*
        Descripción: Escribe un programa que lea un archivo mensaje.txt, realice
        un cifrado César con un desplazamiento de 3 sobre el texto y guarde el
        resultado en un archivo mensaje_cifrado.txt. El cifrado César desplaza cada
        letra por un número fijo de posiciones en el alfabeto (por ejemplo, A se
        convierte en D, B en E, etc.).


*/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void cifrarArchivo(const string& archivoEntrada, const string& archivoSalida, int desplazamiento);
char cifrarCaracter(char c, int desplazamiento);
void mostrarArchivo(const string& archivoSalida);

int main() {
    string archivoEntrada = "mensaje.txt";
    string archivoSalida = "mensaje_cifrado.txt";
    int desplazamiento = 3;

    cifrarArchivo(archivoEntrada, archivoSalida, desplazamiento);

    cout << "El archivo \"" << archivoSalida << "\" se ha generado con el texto cifrado." << endl;

    mostrarArchivo(archivoSalida);

    return 0;
}

void cifrarArchivo(const string& archivoEntrada, const string& archivoSalida, int desplazamiento) {
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

    char caracter;

    while (entrada.get(caracter)) {

        char cifrado = cifrarCaracter(caracter, desplazamiento);
        salida.put(cifrado);
    }

    entrada.close();
    salida.close();
}

char cifrarCaracter(char c, int desplazamiento) {
    if (isalpha(c)) { // Verificar si es una letra
        char base = islower(c) ? 'a' : 'A'; // Determinar si es minúscula o mayúscula
        return (c - base + desplazamiento) % 26 + base;
    }
    return c; // Devolver el carácter sin modificar si no es letra
}

void mostrarArchivo(const string& archivoSalida) {
    ifstream entrada(archivoSalida); // Abrir archivo de entrada

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo de salida: " << archivoSalida << endl;
        return;
    }

    char caracter;

    while (entrada.get(caracter)) {
        cout << caracter;
    }

    entrada.close();
}
