// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 19/11/2024
// Número de ejercicio: 4
// Problema planteado:  Se tiene una lista de empleados de la UCB y esta se almacena en
// una variable tipo struct llamada “empleado”. La información con la que se cuenta es:

//      • nombre (cadena de caracteres)
//      • genero (cadena de caracteres)
//      • salario (decimal)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Empleado {
    string nombre;
    string genero;
    double salario;
};

// Prototipos de funciones
void menu();
void agregarEmpleado(vector<Empleado> &empleados);
void mostrarExtremosSalario(const vector<Empleado> &empleados);

int main() {
    vector<Empleado> empleados;
    int opcion;

    do {
        menu();
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                agregarEmpleado(empleados);
                break;
            case 2:
                mostrarExtremosSalario(empleados);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while (opcion != 3);

    return 0;
}

void menu() {
    cout << "\n--- Menu de Opciones ---" << endl;
    cout << "1. Agregar empleado" << endl;
    cout << "2. Mostrar empleados con menor y mayor salario" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void agregarEmpleado(vector<Empleado> &empleados) {
    Empleado empleado;
    cout << "\nIngrese los datos del empleado:" << endl;
    cout << "Nombre: ";
    getline(cin, empleado.nombre);
    cout << "Genero: ";
    getline(cin, empleado.genero);
    cout << "Salario: ";
    cin >> empleado.salario;
    cin.ignore(); // Limpia el buffer de entrada
    empleados.push_back(empleado);
    cout << "Empleado agregado exitosamente." << endl;
}

void mostrarExtremosSalario(const vector<Empleado> &empleados) {

    Empleado menorSalario = empleados[0];
    Empleado mayorSalario = empleados[0];

    for (const auto &empleado : empleados) {
        if (empleado.salario < menorSalario.salario) {
            menorSalario = empleado;
        }
        if (empleado.salario > mayorSalario.salario) {
            mayorSalario = empleado;
        }
    }

    cout << "\nEmpleado con el menor salario:" << endl;
    cout << "Nombre: " << menorSalario.nombre << endl;
    cout << "Genero: " << menorSalario.genero << endl;
    cout << "Salario: " << menorSalario.salario << endl;

    cout << "\nEmpleado con el mayor salario:" << endl;
    cout << "Nombre: " << mayorSalario.nombre << endl;
    cout << "Genero: " << mayorSalario.genero << endl;
    cout << "Salario: " << mayorSalario.salario << endl;
}
