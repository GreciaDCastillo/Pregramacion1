#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Vehiculo {
    string placa;
    string marca;
    string modelo;
    int anio;
    double precio;
    int stock;
};
struct Venta {
    string placa;
    int cantidad;
    double total;
};

void mostrarMenu();
void seleccionarOpcion(vector<Vehiculo> &vehiculos, vector<Venta> &ventas);
void adicionarVehiculo(vector<Vehiculo> &vehiculos);
void listarVehiculos(vector<Vehiculo> vehiculos);
void modificarPresio(vector<Vehiculo> &vehiculos);
void eliminarVehiculo(vector<Vehiculo> &vehiculos);
void registrarVenta(vector<Vehiculo> &vehiculos, vector<Venta> &ventas);
void cargarVehiculos(vector<Vehiculo> &vehiculos);
void guardarVehiculos(vector<Vehiculo> &vehiculos);


int main() {
    vector<Vehiculo> vehiculos;
    vector<Venta> ventas;

    seleccionarOpcion(vehiculos, ventas);

    return 0;
}

void adicionarVehiculo(vector<Vehiculo> &vehiculos) {
    Vehiculo vehiculo;  
    cout << "\nAdicionar Vehiculo\n";
    cout << "---------------------------\n";

    cout << "Ingrese la placa del vehiculo: ";
    cin.ignore();
    getline(cin, vehiculo.placa);
    cout << "Ingrese la marca del vehiculo: ";
    getline(cin, vehiculo.marca);
    cout << "Ingrese el modelo del vehiculo: ";
    getline(cin, vehiculo.modelo);
    cout << "Ingrese el anio del vehiculo: ";
    cin >> vehiculo.anio;
    cout << "Ingrese el precio del vehiculo: ";
    cin >> vehiculo.precio;

    vehiculos.push_back(vehiculo);
    guardarVehiculos(vehiculos);
    cout << "Vehiculo Adicionado Exitosamente\n";
}

void listarVehiculos(vector<Vehiculo> vehiculos) {
    cout << "Listar Vehiculos\n";   
    cout << "---------------------------\n";

    cout << "Placa\tMarca\t\tModelo\tAnio\tPrecio\n";

    for (int i = 0; i < vehiculos.size(); i++) {
        cout << vehiculos[i].placa << "\t";
        cout << vehiculos[i].marca << "\t\t";
        cout << vehiculos[i].modelo << "\t";
        cout << vehiculos[i].anio << "\t";
        cout << vehiculos[i].precio << "\n";
    }
}

void modificarPresio(vector<Vehiculo> &vehiculos) {
    string placa;

    cout << "\nModificar Precio de Vehiculo\n";
    cout << "---------------------------\n";
    cout << "Ingrese la placa del vehiculo: ";
    cin.ignore();
    getline(cin, placa);

    for (int i = 0; i < vehiculos.size(); i++) {
        if (vehiculos[i].placa == placa) {
            cout << "Ingrese el nuevo precio: ";
            cin >> vehiculos[i].precio;
            guardarVehiculos(vehiculos);
            cout << "Precio Modificado Exitosamente\n";
            return;
        }
    }
   
    cout << "Vehiculo no encontrado\n";
}

void eliminarVehiculo(vector<Vehiculo> &vehiculos) {
    string placa;

    cout << "\nEliminar Vehiculo\n";
    cout << "---------------------------\n";
    cout << "Ingrese la placa del vehiculo: ";
    cin.ignore();
    getline(cin, placa);

    for (int i = 0; i < vehiculos.size(); i++) {
        if (vehiculos[i].placa == placa) {
            vehiculos.erase(vehiculos.begin() + i);
            guardarVehiculos(vehiculos);

            cout << "Vehiculo Eliminado Exitosamente\n";

            return;
        }
    }
    cout << "Vehiculo no encontrado\n";
}

void cargarVehiculos(vector<Vehiculo> &vehiculos) {
    ifstream archivo("vehiculos.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream ss(linea);
            Vehiculo vehiculo;
            string temp;

            getline(ss, vehiculo.placa, ';');
            getline(ss, vehiculo.marca, ';');
            getline(ss, vehiculo.modelo, ';');
            getline(ss, temp, ';');
            vehiculo.anio = stoi(temp);
            getline(ss, temp, ';');
            vehiculo.precio = stod(temp);
            getline(ss, temp, ';');
            vehiculo.stock = stoi(temp);

            vehiculos.push_back(vehiculo);

        }
        archivo.close();
    }
}

void guardarVehiculos(vector<Vehiculo> &vehiculos) {
    ofstream archivo("vehiculos.txt" , ios::out);
    if (archivo.is_open()) {
        for (int i = 0; i < vehiculos.size(); i++) {
            archivo << vehiculos[i].placa << ";";
            archivo << vehiculos[i].marca << ";";
            archivo << vehiculos[i].modelo << ";";
            archivo << vehiculos[i].anio << ";";
            archivo << vehiculos[i].precio << ";";
            archivo << vehiculos[i].stock << endl;
        }
        archivo.close();
    }
}

void registrarVenta(vector<Vehiculo> &vehiculos, vector<Venta> &ventas) {
    Venta nuevaVenta;

    cout << "\nRegistrar Venta de Vehiculos\n";
    cout << "---------------------------\n";
    cout << "Ingrese la placa del vehiculo: ";
    cin.ignore();
    getline(cin, nuevaVenta.placa);

    for (int i = 0; i < vehiculos.size(); i++) {
        if (vehiculos[i].placa == nuevaVenta.placa) {
            cout << "Ingrese la cantidad a vender: ";
            cin >> nuevaVenta.cantidad;

            if (vehiculos[i].stock >= nuevaVenta.cantidad) {
                // Cálculo del total de la venta
                nuevaVenta.total = vehiculos[i].precio * nuevaVenta.cantidad;
                ventas.push_back(nuevaVenta);

                // Actualización del stock
                vehiculos[i].stock -= nuevaVenta.cantidad;

                // Guardar los cambios en el archivo de vehículos
                guardarVehiculos(vehiculos);

                // Registrar la venta en el archivo de ventas
                ofstream archivo("ventas.txt", ios::app);
                if (archivo.is_open()) {
                    archivo << nuevaVenta.placa << ";";
                    archivo << nuevaVenta.cantidad << ";";
                    archivo << nuevaVenta.total << endl;
                    archivo.close();
                }

                cout << "Venta registrada exitosamente.\n";
                return;
            } else {
                cout << "Stock insuficiente. Solo hay " << vehiculos[i].stock << " unidades disponibles.\n";
                return;
            }
        }
    }
    cout << "Vehiculo no encontrado en el inventario.\n";
}


void mostrarMenu() {
    cout << "\nMENU PRINCIPAL\n";
    cout << "---------------------------\n";
    cout << "1. Adicionar Vehiculo\n";
    cout << "2. Listar Vehiculos\n";
    cout << "3. Modificar Precio de Vehiculo\n";
    cout << "4. Eliminar un Vehiculo\n";
    cout << "5. Registrar Venta de Vehiculos\n";
    cout << "6. Salir\n";
    cout << "---------------------------\n";
    cout << "Seleccione una opcion: ";
}

void seleccionarOpcion( vector<Vehiculo> &vehiculos, vector<Venta> &ventas) {

   int opcion = 0;
   
   do {

    mostrarMenu ();
    cin >> opcion;

    switch (opcion) {
        case 1:
            adicionarVehiculo(vehiculos);
            break;
        case 2:
            listarVehiculos(vehiculos);
            break;
        case 3:
            modificarPresio(vehiculos);
            break;
        case 4:
            eliminarVehiculo(vehiculos);
            break;
        case 5:
            registrarVenta(vehiculos, ventas);
            break;
        case 6:
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
    }
   } while (opcion != 6);
}

