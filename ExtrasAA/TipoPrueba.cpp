#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> //AAAAAAAAAA

using namespace std;

struct cuantaBanco{
    int numCuenta;
    string nombre;
    double saldo;
    string fechaApertura;
};

void SeleccionarMenu(vector <cuantaBanco> cuentasBancarias);
void AdicionarCuentasBancarias(vector <cuantaBanco> &cuentasBancarias);
void ListarCuentasBancarias(vector <cuantaBanco> cuentasBancarias);
void modificarCuenta(vector <cuantaBanco> &cuentasBancarias);
void eliminarCuenta(vector <cuantaBanco> &cuentasBancarias);
void adicionarTransaccion(vector <cuantaBanco> &cuentasBancarias);

int main (){

    vector <cuantaBanco> cuentasBancarias; 

    SeleccionarMenu(cuentasBancarias);
    
    return 0;
}

void AdicionarCuentasBancarias(vector <cuantaBanco> &cuentasBancarias){

    cuantaBanco nuevasCuentas;
    
    cout << "Agregar cuentas bancarias\n";
    cout << "-------------------------------\n";
    cout << "Ingrese el numero de cuenta: ";
    cin >> nuevasCuentas.numCuenta;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline (cin, nuevasCuentas.nombre);
    cout << "Ingrese el saldo: ";
    cin >> nuevasCuentas.saldo;
    cout << "Ingrese la fecha de apertura: ";
    cin.ignore();
    getline (cin, nuevasCuentas.fechaApertura);
    
    cuentasBancarias.push_back(nuevasCuentas);
    cout << "Cuenta agregada\n";
}
void ListarCuentasBancarias( vector <cuantaBanco> cuentasBancarias){
    cout << "Listar cuentas bancarias\n";
    cout << "-------------------------------\n";
    cout <<endl;
    for (int i = 0; i < cuentasBancarias.size(); i++){
        cout << cuentasBancarias[i].numCuenta << "\t";
        cout << cuentasBancarias[i].nombre << "\t";
        cout << cuentasBancarias[i].saldo << "\t";
        cout << cuentasBancarias[i].fechaApertura << "\n";
    }
} 
void modificarCuenta(vector <cuantaBanco> &cuentasBancarias){
    cout << "\nModificar una cuenta\n";
    cout << "-------------------------------\n";
    
    int numCuenta;
    cout << "Ingrese el numero de cuenta: ";
    cin >> numCuenta;

    for (int i = 0; i < cuentasBancarias.size(); i++){
        if (cuentasBancarias[i].numCuenta == numCuenta){
            cout << "Ingrese el nombre: ";
            cin.ignore();
            getline (cin, cuentasBancarias[i].nombre);
            cout << "Ingrese el nuevo numero de cuenta: ";
            cin >> cuentasBancarias[i].numCuenta;
            cout << "\nCuenta modificada\n";
            return;
        }
    }
    cout << "Cuenta no encontrada\n";
}

void eliminarCuenta(vector <cuantaBanco> &cuentasBancarias){
    cout << "\nEliminar una cuenta\n";
    cout << "-------------------------------\n";
    
    int numCuenta;
    cout << "Ingrese el numero de cuenta: ";
    cin >> numCuenta;

    for (int i = 0; i < cuentasBancarias.size(); i++){
        if (cuentasBancarias[i].numCuenta == numCuenta){
            cuentasBancarias.erase(cuentasBancarias.begin() + i);
            cout << "\nCuenta eliminada\n";
            return;
        }
    }
    cout << "Cuenta no encontrada\n";
}

void adicionarTransaccion(vector <cuantaBanco> &cuentasBancarias){
    ofstream archivo("transacciones.txt" , ios::out | ios::app); // Agregar al final del archivo en modo escritura
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        return;
    }

    int numCuenta;
    string TipoTransaccion;
    double monto;

    // Solicitar los datos de la transacción

    cout << "Ingrese el numero de cuenta: ";
    cin >> numCuenta;

    auto it = find_if(cuentasBancarias.begin(), cuentasBancarias.end(), [numCuenta](const cuantaBanco &cuenta) {
        return cuenta.numCuenta == numCuenta;
    });

    if (it == cuentasBancarias.end()) {
        cout << "Cuenta no encontrada" << endl;
        return;
    }

    cout << "Ingrese el tipo de transaccion: ";
    cin.ignore();
    getline(cin, TipoTransaccion);

    cout << "Ingrese el monto: ";
    cin >> monto;

    archivo << numCuenta << "," << TipoTransaccion << "," << monto << endl;

    archivo.close();

    if (TipoTransaccion == "Deposito") {
        it->saldo += monto;
    } else if (TipoTransaccion == "Retiro") {
        it->saldo -= monto;
    }

    cout << "Transaccion realizada\n";
}

void menu (){
    cout << "\n--- Menu ---\n";
    cout <<"-------------------------------\n";
    cout << "1. Agregar cuenta\n";
    cout << "2. Listar cuentas bancarias\n";
    cout << "3. Modificar una cuenta\n";
    cout << "4. Eliminar una cuenta\n";
    cout << "5. Adicionar una transacción\n";
    cout << "6. Salir\n";
    cout << "Ingrese una opción: ";

}

void SeleccionarMenu(vector <cuantaBanco> cuentasBancarias){
    int opcion = 0;

    do{ 
        menu();
        cin >> opcion;

        switch(opcion){
            case 1:
                //cout << "Agregar cuenta\n";
                AdicionarCuentasBancarias(cuentasBancarias);
                break;
            case 2:
                //cout << "Listar cuentas bancarias\n";
                ListarCuentasBancarias(cuentasBancarias);
                break;
            case 3:
                //cout << "Modificar una cuenta\n";
                modificarCuenta(cuentasBancarias);
                break;
            case 4:
                //cout << "Eliminar una cuenta\n";
                eliminarCuenta(cuentasBancarias);
                break;  
            case 5:
                //cout << "Procesar transacción\r\n";
                adicionarTransaccion(cuentasBancarias);
                break;
            case 6:
                cout << "Salir\n";
                break;
            default:
                cout << "Opciòn incorrecta\n";
                break;
        }
    }while(opcion != 6);
}