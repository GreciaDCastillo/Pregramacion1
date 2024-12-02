#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Electrodomestico {
    int codigo;
    string nombre;
    string categoria;
    double precio;
    int stock;
};

struct Venta {
    int codigoProducto;
    int cantidadVenta;
    double total;
};

struct Cliente {
    string nombre;
    string contacto;
};

// Funciones para el menú
void mostrarMenu();
void seleccionarOpcion(vector<Electrodomestico> &catalogo, vector<Venta> &ventas, vector<Cliente> &clientes);

// Funciones relacionadas con electrodomésticos
void adicionarElectrodomestico(vector<Electrodomestico> &catalogo);
void listarElectrodomesticos(const vector<Electrodomestico> &catalogo);
void modificarPrecio(vector<Electrodomestico> &catalogo);
void eliminarElectrodomestico(vector<Electrodomestico> &catalogo);
void buscarElectrodomestico(const vector<Electrodomestico> &catalogo);

// Funciones relacionadas con ventas
void registrarVenta(vector<Electrodomestico> &catalogo, vector<Venta> &ventas);
void consultarVentas(const vector<Venta> &ventas);

// Funciones relacionadas con clientes
void registrarCliente(vector<Cliente> &clientes);
void listarClientes(const vector<Cliente> &clientes);

int main() {
    vector<Electrodomestico> catalogo;
    vector<Venta> ventas;
    vector<Cliente> clientes;

    seleccionarOpcion(catalogo, ventas, clientes);

    return 0;
}

void mostrarMenu() {
    cout << "\nMENU PRINCIPAL" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Adicionar Electrodoméstico" << endl;
    cout << "2. Listar Electrodomésticos" << endl;
    cout << "3. Modificar Precio" << endl;
    cout << "4. Eliminar Electrodoméstico" << endl;
    cout << "5. Buscar Electrodoméstico" << endl;
    cout << "6. Registrar Venta" << endl;
    cout << "7. Consultar Ventas" << endl;
    cout << "8. Registrar Cliente" << endl;
    cout << "9. Listar Clientes" << endl;
    cout << "10. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void seleccionarOpcion(vector<Electrodomestico> &catalogo, vector<Venta> &ventas, vector<Cliente> &clientes) {
    int opcion = 0;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                adicionarElectrodomestico(catalogo);
                break;
            case 2:
                listarElectrodomesticos(catalogo);
                break;
            case 3:
                modificarPrecio(catalogo);
                break;
            case 4:
                eliminarElectrodomestico(catalogo);
                break;
            case 5:
                buscarElectrodomestico(catalogo);
                break;
            case 6:
                registrarVenta(catalogo, ventas);
                break;
            case 7:
                consultarVentas(ventas);
                break;
            case 8:
                registrarCliente(clientes);
                break;
            case 9:
                listarClientes(clientes);
                break;
            case 10:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
        }
    } while (opcion != 10);
}

// Electrodomésticos
void adicionarElectrodomestico(vector<Electrodomestico> &catalogo) {
    Electrodomestico nuevo;

    cout << "\nAdicionar Electrodoméstico" << endl;
    cout << "Código: ";
    cin >> nuevo.codigo;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nuevo.nombre);
    cout << "Categoría: ";
    getline(cin, nuevo.categoria);
    cout << "Precio: ";
    cin >> nuevo.precio;
    cout << "Stock: ";
    cin >> nuevo.stock;

    catalogo.push_back(nuevo);
    cout << "Electrodoméstico añadido exitosamente.\n";
}

void listarElectrodomesticos(const vector<Electrodomestico> &catalogo) {
    cout << "\nLista de Electrodomésticos:" << endl;
    for (const auto &e : catalogo) {
        cout << "Código: " << e.codigo << ", Nombre: " << e.nombre
             << ", Categoría: " << e.categoria << ", Precio: " << e.precio
             << ", Stock: " << e.stock << "\n";
    }
}

void modificarPrecio(vector<Electrodomestico> &catalogo) {
    int codigo;
    cout << "\nIngrese el código del Electrodoméstico: ";
    cin >> codigo;

    for (auto &e : catalogo) {
        if (e.codigo == codigo) {
            cout << "Precio actual: " << e.precio << "\n";
            cout << "Ingrese el nuevo precio: ";
            cin >> e.precio;
            cout << "Precio actualizado exitosamente.\n";
            return;
        }
    }
    cout << "Electrodoméstico no encontrado.\n";
}

void eliminarElectrodomestico(vector<Electrodomestico> &catalogo) {
    int codigo;
    cout << "\nIngrese el código del Electrodoméstico a eliminar: ";
    cin >> codigo;

    for (size_t i = 0; i < catalogo.size(); i++) {
        if (catalogo[i].codigo == codigo) {
            catalogo.erase(catalogo.begin() + i);
            cout << "Electrodoméstico eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Electrodoméstico no encontrado.\n";
}

void buscarElectrodomestico(const vector<Electrodomestico> &catalogo) {
    string nombre;
    cout << "\nIngrese el nombre del Electrodoméstico: ";
    cin.ignore();
    getline(cin, nombre);

    for (const auto &e : catalogo) {
        if (e.nombre == nombre) {
            cout << "Código: " << e.codigo << ", Nombre: " << e.nombre
                 << ", Categoría: " << e.categoria << ", Precio: " << e.precio
                 << ", Stock: " << e.stock << "\n";
            return;
        }
    }
    cout << "Electrodoméstico no encontrado.\n";
}

// Ventas
void registrarVenta(vector<Electrodomestico> &catalogo, vector<Venta> &ventas) {
    int codigo, cantidad;
    cout << "\nIngrese el código del Electrodoméstico: ";
    cin >> codigo;

    for (auto &e : catalogo) {
        if (e.codigo == codigo) {
            cout << "Stock disponible: " << e.stock << "\n";
            cout << "Ingrese la cantidad a vender: ";
            cin >> cantidad;

            if (cantidad <= e.stock) {
                e.stock -= cantidad;
                Venta venta = {codigo, cantidad, cantidad * e.precio};
                ventas.push_back(venta);
                cout << "Venta registrada exitosamente. Total: $" << venta.total << "\n";
            } else {
                cout << "Stock insuficiente.\n";
            }
            return;
        }
    }
    cout << "Electrodoméstico no encontrado.\n";
}

void consultarVentas(const vector<Venta> &ventas) {
    cout << "\nVentas realizadas:\n";
    for (const auto &v : ventas) {
        cout << "Código Producto: " << v.codigoProducto
             << ", Cantidad: " << v.cantidadVenta
             << ", Total: $" << v.total << "\n";
    }
}

// Clientes
void registrarCliente(vector<Cliente> &clientes) {
    Cliente nuevo;
    cout << "\nIngrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, nuevo.nombre);
    cout << "Ingrese el contacto del cliente: ";
    getline(cin, nuevo.contacto);

    clientes.push_back(nuevo);
    cout << "Cliente registrado exitosamente.\n";
}

void listarClientes(const vector<Cliente> &clientes) {
    cout << "\nLista de Clientes:\n";
    for (const auto &c : clientes) {
        cout << "Nombre: " << c.nombre << ", Contacto: " << c.contacto << "\n";
    }
}
