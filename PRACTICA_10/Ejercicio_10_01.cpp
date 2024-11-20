// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 18/11/2024
// Número de ejercicio: 1
// Problema planteado: Registro de una biblioteca. Define una estructura llamada Libro con los siguientes campos: titulo (cadena de caracteres)
//          autor (cadena de caracteres)
//          anio_publicacion (entero)
//          disponible (booleano, que indica si el libro está disponible o no)


#include <iostream>
#include <string>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio_publicacion;
    bool disponible;
};

// Prototipos de funciones

void agregarLibro(Libro &libro);
void mostrarLibro(const Libro &libro);
void seleccionarMenu(Libro &libro); 
void MenuPrincipal();

int main() {
    Libro libro; 
    seleccionarMenu(libro); 
    return 0;
}

void MenuPrincipal() {
    cout << "\nMenu Principal" << endl;
    cout << "-----------------" << endl;
    cout << "1. Agregar libro" << endl;
    cout << "2. Mostrar libro" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
}

void seleccionarMenu(Libro &libro) { 
    int opcion = 0;

    do {
        MenuPrincipal();
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                agregarLibro(libro); 
                system("pause");
                break;
            case 2:
                mostrarLibro(libro); /
                system("pause");
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
}

void agregarLibro(Libro &libro) {
    cout << "\nAgregar un nuevo libro:" << endl;
    cout << "Titulo: ";
    getline(cin, libro.titulo);
    cout << "Autor: ";
    getline(cin, libro.autor);
    cout << "Anio de publicacion: ";
    cin >> libro.anio_publicacion;
    cout << "Esta disponible? (1 = Si, 0 = No): ";
    cin >> libro.disponible;
    cin.ignore(); 
    cout << "Libro agregado exitosamente." << endl;
}

void mostrarLibro(const Libro &libro) {
    cout << "\nDetalles del libro:" << endl;
    cout << "Titulo: " << libro.titulo << endl;
    cout << "Autor: " << libro.autor << endl;
    cout << "Anio de publicacion: " << libro.anio_publicacion << endl;
    cout << "Disponible: " << (libro.disponible ? "Si" : "No") << endl;
}

