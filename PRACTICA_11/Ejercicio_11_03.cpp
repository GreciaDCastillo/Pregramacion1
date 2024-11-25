// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 22/11/2024
// Número de ejercicio: 3
// Problema planteado: Almacenamiento de registros de estudiantes
/*
        Descripción: Escribe un programa que permita registrar la información de
        varios estudiantes en un archivo de texto llamado estudiantes.txt. Cada
        estudiante debe tener un nombre, una edad y un promedio de
        calificaciones. Luego, el programa debe poder leer el archivo y mostrar toda
        la información de los estudiantes en un formato organizado.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registrarEstudiantes(const string& nombreArchivo);
void mostrarEstudiantes(const string& nombreArchivo);

int main() {
    string nombreArchivo = "estudiantes.txt";

    registrarEstudiantes(nombreArchivo);
    mostrarEstudiantes(nombreArchivo);

    return 0;
}

void registrarEstudiantes(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::app); // Abrir archivo en modo agregar
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para escribir." << endl;
        return;
    }

    string nombre;
    int edad;
    float promedio;
    int numEstudiantes = 0;
    cout << "Ingrese el numero de estudiantes: ";
    cin >> numEstudiantes;
    cin.ignore();

    for (int i = 0; i < numEstudiantes; i++) {

        cout << "Ingrese la información del estudiante " << i + 1 << ":" << endl;

        cout << "Nombre: ";
        getline(cin, nombre);

        cout << "Edad: ";
        cin >> edad;

        cout << "Promedio: ";
        cin >> promedio;
        cin.ignore(); 

        // Guardar la información en el archivo
        archivo << nombre << "," << edad << "," << promedio << endl;
        
    }
    archivo.close();
    cout << "Información de los estudiantes guardada en " << nombreArchivo << "." << endl;
}


void mostrarEstudiantes(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo); // Abrir archivo en modo lectura
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    string nombre;
    int edad;
    float promedio;
    char separador;

    cout << "Información de los estudiantes:" << endl;
    cout << string(40, '-') << endl;

    while (archivo.good()) {
        getline(archivo, nombre, ','); // Leer hasta la coma
        if (nombre.empty()) break;    
        archivo >> edad >> separador >> promedio;
        archivo.ignore();  // Ignorar el salto de línea

        cout << "\nNombre: " <<  nombre << endl; 
        cout << "Edad: "  << edad << endl; 
        cout << "Promedio: " << promedio << endl;
    }

    archivo.close();
}
