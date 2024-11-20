// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 19/11/2024
// Número de ejercicio: 6
// Problema planteado:  
/*
        Descripción: Define una estructura llamada Empleado que contenga los siguientes campos:

        • nombre (cadena de caracteres)
        • id (entero)
        • sueldo (decimal)
        • antiguedad (entero, en años)

    Escribe un programa que permita:

        • Ingresar los datos de N empleados.
        • Crear una función que reciba un arreglo de empleados y un valor de sueldo y
            devuelva cuántos empleados tienen un sueldo mayor a ese valor.
        • Crear otra función que reciba el arreglo y calcule el promedio de antigüedad
            de todos los empleados
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Empleado {
    string nombre;
    int id;
    double sueldo;
    int antiguedad;
};

void seleccionarMenu(vector<Empleado> &empleados);
void menu();
void agregarEmpleado(vector<Empleado> &empleados);
void mostrarSalarios(const vector<Empleado> &empleados);
void promedioAntiguedad(const vector<Empleado> &empleados);

int main() {
    vector<Empleado> empleados;
    seleccionarMenu(empleados);
    return 0;
}

void menu() {
    cout << "\nMenu Principal" << endl;
    cout << "-----------------" << endl;
    cout << "1. Agregar empleado" << endl;
    cout << "2. Mostrar empleados con salarios mayores a un valor" << endl;
    cout << "3. Mostrar el promedio de antiguedad de los empleados" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
}

void seleccionarMenu(vector<Empleado> &empleados) {
    int opcion = 0;

    do {
        menu();
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                agregarEmpleado(empleados);
                break;
            case 2:
                mostrarSalarios(empleados);
                break;
            case 3:
                promedioAntiguedad(empleados);
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

void agregarEmpleado(vector<Empleado> &empleados) {
    Empleado DatosdeEmpleado;
    DatosdeEmpleado.id = empleados.size() + 1;

    cout << "\nIngrese los datos del empleado:" << endl;
    cout << "---------------" << endl;

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, DatosdeEmpleado.nombre);
    cout << "Sueldo: ";
    cin >> DatosdeEmpleado.sueldo;
    cout << "Antiguedad: ";
    cin >> DatosdeEmpleado.antiguedad;

    empleados.push_back(DatosdeEmpleado);
    cout << "Empleado agregado exitosamente." << endl;
}

void mostrarSalarios(const vector<Empleado> &empleados) {


    cout << "\nEmpleados con salarios mayores a un valor:" << endl;
    cout << "----------------------------------------" << endl;

    cout << "Ingrese un salario: ";
    double salario;
    cin >> salario;

    int contador = 0;
    for (const auto &empleado : empleados) {
        if (empleado.sueldo > salario) {
            contador++;
            cout << "Empleado " << contador << ":" << endl;
            cout << "ID: " << empleado.id << endl;
            cout << "Nombre: " << empleado.nombre << endl;
            cout << "Sueldo: " << empleado.sueldo << endl;
            cout << "Antiguedad: " << empleado.antiguedad << " años" << endl;
            cout << "----------------------------------------" << endl;
        }
    }

    if (contador == 0) {
        cout << "No hay empleados con salarios mayores a " << salario << "." << endl;
    }
}

void promedioAntiguedad(const vector<Empleado> &empleados) {

    double promedio = 0;
    for (const auto &empleado : empleados) {
        promedio += empleado.antiguedad;
    }
    promedio /= empleados.size();

    cout << "El promedio de antiguedad de los empleados es: " << promedio << " años." << endl;
}

