// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 19/11/2024
// Número de ejercicio: 7
// Problema planteado:  
/*
    Descripción: Define una estructura llamada Producto con los siguientes campos:

        • nombre (cadena de caracteres)
        • codigo (cadena de caracteres)
        • precio (decimal)
        • cantidad_en_inventario (entero)
        • observaciones (cadena de caracteres)

    Luego, escribe un programa que permita:

        • Registrar N productos en el inventario.
        • Mostrar el producto más caro en el inventario.
        • Mostrar la cantidad total de productos en inventario.
        • Si un producto se encuentra con cantidad_en_inventario menor a 5, en el
          campo observaciones debe tener un mensaje de advertencia “PRUDUCTO
          CON BAJA CANTIDAD DE INVENTARIO”.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Producto {
    int id;
    string nombre;
    string codigo;
    double precio;
    int cantidad_en_inventario;
    string observaciones;
};

void seleccionarMenu (vector<Producto> &registros);
void menu();
void agregarProducto(vector<Producto> &registros);
void mostrarProductoMasCaro(const vector<Producto> registros);
void mostrarTotalProductos(const vector<Producto> registros);
void mostrarProductosBajoStock(const vector<Producto> registros);

int main() {
    vector<Producto> registros; 
    seleccionarMenu(registros);
    return 0;
};

void menu () {
    cout << "\nMenu Principal" << endl;
    cout << "-----------------" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Mostrar producto mas caro" << endl;
    cout << "3. Mostrar total de productos" << endl;
    cout << "4. Mostrar productos bajo stock" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
}

void seleccionarMenu(vector<Producto> &registros) {
    int opcion = 0;
    do {
        menu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarProducto(registros);
                break;
            case 2:
                mostrarProductoMasCaro(registros);
                break;
            case 3:
                mostrarTotalProductos(registros);
                break;
            case 4:
                mostrarProductosBajoStock(registros);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 5);
}

void agregarProducto(vector<Producto> &registros) {
    Producto nuevoProducto;
    nuevoProducto.id = registros.size() + 1;

    cout << "\nAgregar un nuevo producto:" << endl;
    cout << "-----------------" << endl;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nuevoProducto.nombre);
    cout << "Codigo: ";
    getline(cin, nuevoProducto.codigo);
    cout << "Precio: ";
    cin >> nuevoProducto.precio;
    cout << "Cantidad en inventario: ";
    cin >> nuevoProducto.cantidad_en_inventario;
    cout << "Observaciones: ";
    cin.ignore();
    getline(cin, nuevoProducto.observaciones);

    registros.push_back(nuevoProducto);
    cout << "\nProducto agregado exitosamente." << endl;
}

void mostrarProductoMasCaro(const vector<Producto> registros) {
    double precioMasCaro = 0.0;
    int idMasCaro = 0;
    for (const auto &producto : registros) {
        if (producto.precio > precioMasCaro) {
            precioMasCaro = producto.precio;
            idMasCaro = producto.id;
        }
    }

    cout << "\nProducto mas caro:" << endl;
    cout << "-----------------" << endl;
    cout << "ID: " << idMasCaro << endl;
    cout << "Nombre: " << registros[idMasCaro - 1].nombre << endl;
    cout << "Precio: " << registros[idMasCaro - 1].precio << endl;
    cout << "-----------------" << endl;
}

void mostrarTotalProductos(const vector<Producto> registros) {
    int totalProductos = registros.size();
    cout << "\nTotal de productos: " << totalProductos << endl;
}

void mostrarProductosBajoStock(const vector<Producto> registros) {
    if (registros.empty()) {
        cout << "\nNo hay productos en el inventario." << endl;
        return;
    }
    cout << "\nProductos bajo stock:" << endl;
    cout << "-----------------" << endl;
    for (const auto &producto : registros) {
        if (producto.cantidad_en_inventario < 5) {
            cout << "ID: " << producto.id << endl;
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Cantidad en inventario: " << producto.cantidad_en_inventario << endl;
            cout << "Observaciones: " << producto.observaciones << endl;
            cout << "-----------------" << endl;
        }
        else { 
            cout << "No hay productos bajo stock." << endl;
        }
    }
}