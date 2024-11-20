// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/11/2024
// Número de ejercicio: 2
// Problema planteado: Crea una estructura llamada Atleta que contenga los siguientes campos:
//          nombre (cadena de caracteres)
//          pais (cadena de caracteres)
//          edad (entero)
//          mejor_tiempo (entero, en segundos)


#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Atleta {
    int id;
    string nombre;
    string pais;
    int edad;
    int mejor_tiempo;
};
// Prototipos de funciones

void seleccionarMenu(vector<Atleta> &registros);
void MenuPrincipal();
void agregarAtleta(vector<Atleta> &registros);
void mostrarAtletas(const vector<Atleta> &registros);
void mejorTiempo(const vector<Atleta> &registros);

int main() {
    vector<Atleta> registros; 
    seleccionarMenu(registros);
    return 0;
}

void MenuPrincipal() {
    cout << "\nMenu Principal" << endl;
    cout << "-----------------" << endl;
    cout << "1. Agregar atleta" << endl;
    cout << "2. Mostrar todos los atletas" << endl;
    cout << "3. Mostrar atleta con mejor tiempo" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
}

void seleccionarMenu(vector<Atleta> &registros) {
    int opcion = 0;
    do {
        MenuPrincipal();
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                agregarAtleta(registros);
                break;
            case 2:
                mostrarAtletas(registros);
                break;
            case 3:
                mejorTiempo(registros);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 4);
}

void agregarAtleta(vector<Atleta> &registros) {
    Atleta nuevoAtleta;
    nuevoAtleta.id = registros.size() + 1; // Asignar un ID único

    cout << "\nAgregar un nuevo atleta:" << endl;
    cout << "Nombre: ";
    getline(cin, nuevoAtleta.nombre);
    cout << "Pais: ";
    getline(cin, nuevoAtleta.pais);
    cout << "Edad: ";
    cin >> nuevoAtleta.edad;
    cout << "Mejor Tiempo: ";
    cin >> nuevoAtleta.mejor_tiempo;
    cin.ignore(); 

    registros.push_back(nuevoAtleta); // Añadir el atleta al vector
    cout << "\nAtleta agregado exitosamente" << endl;
}

void mostrarAtletas(const vector<Atleta> &registros) {
    cout << "\nDetalles de los atletas:" << endl;
    cout << "-----------------" << endl;

    for (const auto &atleta : registros) {
        cout << "ID: " << atleta.id << endl;
        cout << "Nombre: " << atleta.nombre << endl;
        cout << "Pais: " << atleta.pais << endl;
        cout << "Edad: " << atleta.edad << endl;
        cout << "Mejor Tiempo: " << atleta.mejor_tiempo << " segundos" << endl;
        cout << "-----------------" << endl;
    }
}


void mejorTiempo(const vector<Atleta> &registros) {

    int mejorIndice = 0; // Suponemos que el primero tiene el mejor tiempo
    for (size_t i = 1; i < registros.size(); i++) {
        if (registros[i].mejor_tiempo < registros[mejorIndice].mejor_tiempo) {
            mejorIndice = i;
        }
    }

    cout << "\nAtleta con el mejor tiempo:" << endl;
    cout << "ID: " << registros[mejorIndice].id << endl;
    cout << "Nombre: " << registros[mejorIndice].nombre << endl;
    cout << "Pais: " << registros[mejorIndice].pais << endl;
    cout << "Mejor Tiempo: " << registros[mejorIndice].mejor_tiempo << " segundos" << endl;
}
