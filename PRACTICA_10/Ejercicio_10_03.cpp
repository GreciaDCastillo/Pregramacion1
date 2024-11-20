// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/11/2024
// Número de ejercicio: 3
// Problema planteado: Descripción: Desarrolle una estructura que guarde los datos de los n alumnos de
// la materia Programación I y los muestres por pantalla, la estructura debe tener los siguientes datos:

//          cedula (entero)
//          nombre (cadena de caracteres)
//          apellido (cadena de caracteres)
//          edad (entero)
//          profesión (cadena de caracteres)
//          lugar_nacimiento (cadena de caracteres)
//          dirección (cadena de caracteres)
//          teléfono (entero)


#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Alumno {
    int id;
    int cedula;
    string nombre;
    string apellido;
    int edad;
    string profesion;
    string lugar_nacimiento;
    string direccion;
    int telefono;
};
// Prototipos de funciones
void seleccionarMenu(vector<Alumno> &lista);
void menu();
void agregarAlumno(vector<Alumno> &lista);
void mostrarAlumno(const vector<Alumno> &lista);

int main() {
    vector<Alumno> lista; // Contenedor dinámico para almacenar múltiples alumnos
    seleccionarMenu(lista);
    return 0;
}

void menu() {
    cout << "\nMenu de opciones: " << endl;
    cout << "-----------------" << endl;
    cout << "1. Agregar alumno" << endl;
    cout << "2. Mostrar alumnos" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
}

void seleccionarMenu(vector<Alumno> &lista) {
    int opcion = 0;

    do {
        menu();
        cin >> opcion;
        cin.ignore(); // Limpia el buffer de entrada

        switch (opcion) {
            case 1:
                agregarAlumno(lista);
                break;
            case 2:
                mostrarAlumno(lista);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 3);
}

void agregarAlumno(vector<Alumno> &lista) {
    Alumno nuevoAlumno;
    nuevoAlumno.id = lista.size() + 1; // Asignar un ID único

    cout << "\nAgregar un nuevo alumno:" << endl;
    cout << "----------------------" << endl;

    cout << "Cedula: ";
    cin >> nuevoAlumno.cedula;
    cin.ignore(); 
    cout << "Nombre: ";
    getline(cin, nuevoAlumno.nombre);
    cout << "Apellido: ";
    getline(cin, nuevoAlumno.apellido);
    cout << "Edad: ";
    cin >> nuevoAlumno.edad;
    cin.ignore();
    cout << "Profesion: ";
    getline(cin, nuevoAlumno.profesion);
    cout << "Lugar de nacimiento: ";
    getline(cin, nuevoAlumno.lugar_nacimiento);
    cout << "Direccion: ";
    getline(cin, nuevoAlumno.direccion);
    cout << "Telefono: ";
    cin >> nuevoAlumno.telefono;

    lista.push_back(nuevoAlumno); 
    cout << "Alumno agregado exitosamente con ID: " << nuevoAlumno.id << endl;
}

void mostrarAlumno(const vector<Alumno> &lista) {
    cout << "\nLista de alumnos:" << endl;
    cout << "===========================" << endl;

    for (const auto &alumno : lista) {
        cout << "ID: " << alumno.id << endl;
        cout << "Cedula: " << alumno.cedula << endl;
        cout << "Nombre: " << alumno.nombre << endl;
        cout << "Apellido: " << alumno.apellido << endl;
        cout << "Edad: " << alumno.edad << endl;
        cout << "Profesion: " << alumno.profesion << endl;
        cout << "Lugar de nacimiento: " << alumno.lugar_nacimiento << endl;
        cout << "Direccion: " << alumno.direccion << endl;
        cout << "Telefono: " << alumno.telefono << endl;
        cout << "-----------------" << endl;
    }
}
