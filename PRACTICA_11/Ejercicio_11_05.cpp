// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 22/11/2024
// Número de ejercicio: 5
// Problema planteado: Actualizar datos en un archivo
/*
       Descripción: Escribe un programa que permita actualizar un archivo de
        texto llamado productos.txt, el cual contiene una lista de productos y sus
        precios. Cada línea del archivo tiene el formato Producto Precio (por
        ejemplo, Manzana 1.50). El programa debe permitir al usuario ingresar el
        nombre de un producto y el nuevo precio, y actualizar ese precio en el
        archivo. Si el producto no se encuentra, debe indicar que no existe.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


void actualizarPrecio(const string& nombreArchivo, const string& productoBuscado, float nuevoPrecio);

int main() {
    string nombreArchivo = "productos.txt";
    string producto;
    float nuevoPrecio;

    cout << "Ingrese el nombre del producto a actualizar: ";
    getline(cin, producto);

    cout << "Ingrese el nuevo precio: ";
    cin >> nuevoPrecio;

    actualizarPrecio(nombreArchivo, producto, nuevoPrecio);

    return 0;
}


void actualizarPrecio(const string& nombreArchivo, const string& productoBuscado, float nuevoPrecio) { // Función para actualizar el precio de un producto en el archivo
    ifstream archivoEntrada(nombreArchivo); // Abrir archivo en modo lectura
    if (!archivoEntrada.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << " para lectura." << endl;
        return;
    }

    vector<string> lineas; // Almacenar las líneas del archivo
    string linea;
    bool productoEncontrado = false;

    // Leer las líneas del archivo
    while (getline(archivoEntrada, linea)) {
        stringstream ss(linea);
        string producto;
        float precio;

        ss >> producto >> precio; // Leer producto y precio

        if (producto == productoBuscado) {
            productoEncontrado = true;
            stringstream nuevaLinea;
            nuevaLinea << producto << " " << nuevoPrecio; // Actualizar la línea
            lineas.push_back(nuevaLinea.str());
        } else {
            lineas.push_back(linea); // Conservar la línea original
        }
    }

    archivoEntrada.close(); // Cerrar archivo de lectura

    if (!productoEncontrado) {
        cout << "El producto \"" << productoBuscado << "\" no existe en el archivo." << endl;
        return;
    }

    // Reescribir el archivo con las líneas actualizadas
    ofstream archivoSalida(nombreArchivo); // Abrir archivo en modo escritura
    if (!archivoSalida.is_open()) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << " para escritura." << endl;
        return;
    }

    for (const string& linea : lineas) {
        archivoSalida << linea << endl;
    }

    archivoSalida.close();
    cout << "El precio del producto \"" << productoBuscado << "\" ha sido actualizado a " << nuevoPrecio << "." << endl;
}
