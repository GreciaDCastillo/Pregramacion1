#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Pizza {
    int codigo;
    string nombre;
    string tipo;
    string tamanio;
    double precio;
    int cantidad = 0;
    double total = 0.0;
};

struct Venta {
    string idCliente;
    int codPizza;
    string tamanio;
    int cantidadVendidas;
};

void seleccionarmenu(vector<Pizza> &pizzas, vector<Venta> &ventas);
void mostrarMenu();
void adicionarPizza(vector<Pizza> &pizzas);
void listarPizzas(vector<Pizza> pizzas);
void modificarPrecio(vector<Pizza> &pizzas);
void eliminarPizza(vector<Pizza> &pizzas);
void adicionarVenta(vector<Pizza> &pizzas, vector<Venta> &ventas);
void cargarPizzas(vector<Pizza> &pizzas);
void guardarPizzas(vector<Pizza> &pizzas);

int main() {

    vector<Pizza> pizzas;
    vector<Venta> ventas;

    cargarPizzas(pizzas);
    seleccionarmenu (pizzas , ventas);

    return 0;
}

void adicionarPizza(vector<Pizza> &pizzas){

    Pizza nuevaPizza;

    cout << "Adiccionar Pizza\n";
    cout << "---------------------------\n"<<endl;
    cout << "Ingrese el codigo de la Pizza: ";
    cin >> nuevaPizza.codigo;
    cout << "Ingrese el nombre de la Pizza: ";
    cin.ignore();
    getline (cin, nuevaPizza.nombre);
    cout << "Ingrese el tipo de la Pizza (Tradicional = T, Especial = E): ";
    getline (cin, nuevaPizza.tipo);
    cout << "Ingrese el tamanio de la Pizza (xs, Medium, Large, Familiar, Interminable) : ";
    getline (cin, nuevaPizza.tamanio);
    cout << "Ingrese el precio de la Pizza: ";
    cin >> nuevaPizza.precio;

    if (nuevaPizza.tipo == "E") {
        nuevaPizza.precio *= 1.1; // Aplicar un aumento del 50% para pizzas especiales
    }

    pizzas.push_back(nuevaPizza); // Agregar la nueva pizza al vector
    guardarPizzas( pizzas);

    cout << "\nPizza agregada\n";
    
}

void listarPizzas(vector<Pizza> pizzas){

    cout << "\nListado de Pizzas\n";
    cout << "---------------------------\n"<<endl;
    cout << "Codigo" << setw(10) << "Nombre" << setw(20) << "Tipo" << setw(10) << "Tamanio" << setw(15) << "Precio" << endl;
    for (int i = 0; i < pizzas.size(); i++) {
        cout << pizzas[i].codigo << setw(10) << pizzas[i].nombre << setw(20) << pizzas[i].tipo << setw(10) << pizzas[i].tamanio << setw(15) << pizzas[i].precio << endl;
    }
}

void modificarPrecio(vector<Pizza> &pizzas) {
    int codigo;

    cout << "\nModificar precio de una Pizza\n";
    cout << "---------------------------\n"<<endl;
    cout << "Ingrese el codigo de la Pizza: ";
    cin >> codigo;
    for (int i = 0; i < pizzas.size(); i++) {
        if (pizzas[i].codigo == codigo) {
            cout << "Ingrese el nuevo precio: ";
            cin >> pizzas[i].precio;
            guardarPizzas(pizzas);
            cout << "\nPrecio modificado\n";
            return;
        }
    }
    cout << "Pizza no encontrada\n";
}

void eliminarPizza(vector<Pizza> &pizzas) {
    int codigo;

    cout << "\nEliminar una Pizza\n";
    cout << "---------------------------\n"<<endl;
    cout << "Ingrese el codigo de la Pizza: ";
    cin >> codigo;
    for (int i = 0; i < pizzas.size(); i++) {
        if (pizzas[i].codigo == codigo) {
            pizzas.erase(pizzas.begin() + i);
            guardarPizzas(pizzas);
            cout << "\nPizza eliminada\n";
            return;
        }
    }
    cout << "Pizza no encontrada\n";
}

void cargarPizzas(vector<Pizza> &pizzas) {
    ifstream archivo("pizzas.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            Pizza pizza;
            string temp;

            getline(ss, temp, ',');
            pizza.codigo = stoi(temp);
            getline(ss, pizza.nombre, ',');
            getline(ss, pizza.tipo, ',');
            getline(ss, pizza.tamanio, ',');
            getline(ss, temp, ',');
            pizza.precio = stod(temp);
            getline(ss, temp, ',');
            pizza.cantidad = stoi(temp);
            getline(ss, temp, ',');
            pizza.total = stod(temp);

            pizzas.push_back(pizza);
        }
        archivo.close();
    }
}

void guardarPizzas(vector<Pizza> &pizzas) {
    ofstream archivo("pizzas.txt", ios::out);
    if (archivo.is_open()) {
        for (const auto &pizza : pizzas) {
            archivo << pizza.codigo << "," << pizza.nombre << "," << pizza.tipo << "," 
                    << pizza.tamanio << "," << pizza.precio << "," << pizza.cantidad 
                    << "," << pizza.total << endl;
        }
        archivo.close();
    }
}

void adicionarVenta(vector<Pizza> &pizzas, vector<Venta> &ventas) {
    Venta nuevaVenta;

    cout << "\nAdicionar Venta de Pizzas\n";
    cout << "---------------------------\n"<<endl;
    cout << "Ingrese el Codigo de la Pizza: ";
    cin >> nuevaVenta.idCliente;
    cout << "Ingrese el Codigo de la Pizza: ";
    cin >> nuevaVenta.codPizza;
    cout << "Ingrese el tamanio de la Pizza: ";
    cin >> nuevaVenta.tamanio;
    cout << "Ingrese la cantidad de pizzas: ";
    cin >> nuevaVenta.cantidadVendidas;

    for (int i = 0; i < pizzas.size(); i++) {
        if (pizzas[i].codigo == nuevaVenta.codPizza || pizzas[i].tamanio == nuevaVenta.tamanio) {
            pizzas[i].cantidad += nuevaVenta.cantidadVendidas;
            pizzas[i].total +=  pizzas[i].precio * nuevaVenta.cantidadVendidas;

            ventas.push_back(nuevaVenta);

            ofstream archivo("ventas.txt", ios::app); // Abrir archivo en modo escritura
            if (archivo.is_open()) {
                archivo << nuevaVenta.idCliente << "," << nuevaVenta.codPizza << "," << nuevaVenta.tamanio << "," << nuevaVenta.cantidadVendidas << endl;
                archivo.close();
            }

            guardarPizzas(pizzas);

            cout << "\nVenta realizada\n";
            return;
            
        }
    }
    cout << "Pizza no encontrada\n";
}


void mostrarMenu(){
    cout << "\nMENU PRINCIPAL PIZZERIA\n"<<endl;
    cout << "---------------------------\n"<<endl;
    cout << "1. Adicionar Pizza\n";
    cout << "2. Listado de Pizzas\n";
    cout << "3. Modificar Precio de Pizza\n";
    cout << "4. Eliminar una Pizza\n";
    cout << "5. Adicionar Venta de Pizzas\n";
    cout << "6. Salir\n";
    cout << "---------------------------\n"<<endl;
    cout << "Seleccione una opcion: ";    

}
void seleccionarmenu( vector<Pizza> &pizzas, vector<Venta> &ventas){
    int opcion = 0;

    do { 
        mostrarMenu();
        cin >> opcion; 
        switch(opcion){ 
            case 1: 
                adicionarPizza(pizzas); 
                break; 
            case 2: 
                listarPizzas(pizzas); 
                break; 
            case 3: 
                modificarPrecio(pizzas); 
                break; 
            case 4: 
                eliminarPizza(pizzas); 
                break; 
            case 5: 
                adicionarVenta(pizzas, ventas); 
                break; 
            case 6: 
                cout << "Saliendo del programa...."; 
                break; 
            default: 
                cout << "Opcion no valida";
        } 
    }while(opcion != 6);


}
