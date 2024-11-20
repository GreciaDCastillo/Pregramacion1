// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 19/11/2024
// Número de ejercicio: 5
// Problema planteado:  Define una estructura llamada Pelicula con los siguientes campos:
/*
        • titulo (cadena de caracteres)
        • director (cadena de caracteres)
        • duracion (entero, en minutos)
        • anio_estreno (entero)
        • genero (cadena de caracteres)

   Escribe un programa que permita al usuario registrar N películas en un arreglo de
   estructuras y luego realice lo siguiente:

        • Mostrar todas las películas de un género específico introducido por el usuario.
        • Mostrar todas las películas dirigidas por un director específico introducido por el usuario.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pelicula {
    string titulo;
    string director;
    int duracion;       // En minutos
    int anio_estreno;
    string genero;
};

// Prototipos de funciones
void menu();
void agregarPelicula(vector<Pelicula> &peliculas);
void mostrarPeliculasPorGenero(const vector<Pelicula> &peliculas);
void mostrarPeliculasPorDirector(const vector<Pelicula> &peliculas);

int main() {
    vector<Pelicula> peliculas;
    int opcion;

    do {
        menu();
        cin >> opcion;
        cin.ignore(); // Limpia el buffer de entrada

        switch (opcion) {
            case 1:
                agregarPelicula(peliculas);
                break;
            case 2:
                mostrarPeliculasPorGenero(peliculas);
                break;
            case 3:
                mostrarPeliculasPorDirector(peliculas);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);

    return 0;
}

void menu() {
    cout << "\n--- Menu de Opciones ---" << endl;
    cout << "1. Agregar pelicula" << endl;
    cout << "2. Mostrar peliculas por genero" << endl;
    cout << "3. Mostrar peliculas por director" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void agregarPelicula(vector<Pelicula> &peliculas) {
    Pelicula pelicula;
    cout << "\nIngrese los datos de la pelicula:" << endl;
    cout << "Titulo: ";
    getline(cin, pelicula.titulo);
    cout << "Director: ";
    getline(cin, pelicula.director);
    cout << "Duracion (en minutos): ";
    cin >> pelicula.duracion;
    cin.ignore(); // Limpia el buffer
    cout << "Anio de estreno: ";
    cin >> pelicula.anio_estreno;
    cin.ignore(); // Limpia el buffer
    cout << "Genero: ";
    getline(cin, pelicula.genero);

    peliculas.push_back(pelicula);
    cout << "Pelicula agregada exitosamente." << endl;
}

void mostrarPeliculasPorGenero(const vector<Pelicula> &peliculas) {

    string generoBuscado;
    cout << "\nIngrese el genero que desea buscar: ";
    getline(cin, generoBuscado);

    cout << "\nPeliculas del genero '" << generoBuscado << "':" << endl;
    bool encontrada = false;
    for (const auto &pelicula : peliculas) {
        if (pelicula.genero == generoBuscado) {
            cout << "Titulo: " << pelicula.titulo << endl;
            cout << "Director: " << pelicula.director << endl;
            cout << "Duracion: " << pelicula.duracion << " minutos" << endl;
            cout << "Anio de estreno: " << pelicula.anio_estreno << endl;
            cout << "Genero: " << pelicula.genero << endl;
            cout << "--------------------------" << endl;
            encontrada = true;
        }
    }

    if (!encontrada) {
        cout << "No se encontraron peliculas de este genero." << endl;
    }
}

void mostrarPeliculasPorDirector(const vector<Pelicula> &peliculas) {

    string directorBuscado;
    cout << "\nIngrese el nombre del director que desea buscar: ";
    getline(cin, directorBuscado);

    cout << "\nPeliculas dirigidas por '" << directorBuscado << "':" << endl;
    bool encontrada = false;
    for (const auto &pelicula : peliculas) {
        if (pelicula.director == directorBuscado) {
            cout << "Titulo: " << pelicula.titulo << endl;
            cout << "Director: " << pelicula.director << endl;
            cout << "Duracion: " << pelicula.duracion << " minutos" << endl;
            cout << "Anio de estreno: " << pelicula.anio_estreno << endl;
            cout << "Genero: " << pelicula.genero << endl;
            cout << "--------------------------" << endl;
            encontrada = true;
        }
    }

    if (!encontrada) {
        cout << "No se encontraron peliculas dirigidas por este director." << endl;
    }
}
