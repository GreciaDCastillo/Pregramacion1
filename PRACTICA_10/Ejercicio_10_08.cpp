// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 20/11/2024
// Número de ejercicio: 8
// Problema planteado:   El viceministerio de deportes hace una olimpiada a nivel nacional de los siguientes deportes:
/*
            • Tiro con arco
            • Atletismo
            • Boxeo
            • Ciclismo
            • Natación
            • Esgrima

    También se registra los nombres de los atletas y que departamento representa y que deporte practica.
    Realizar un programa en C++ que simule y registre cuantas medallas ha ganado un atleta y que me muestre el 
    medallero final por departamento.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Atleta {
    string nombre;
    string departamento;
    string deporte;
    int medallas;
};

// Funciones del programa
void menu();
void registrarAtleta(vector<Atleta> &atletas);
void registrarMedallas(vector<Atleta> &atletas);
void mostrarMedallero(const vector<Atleta> &atletas);

int main() {
    vector<Atleta> atletas;
    int opcion;

    do {
        menu();
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                registrarAtleta(atletas);
                break;
            case 2:
                registrarMedallas(atletas);
                break;
            case 3:
                mostrarMedallero(atletas);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}

void menu() {
    cout << "\n--- Olimpiada Nacional ---" << endl;
    cout << "1. Registrar Atleta" << endl;
    cout << "2. Registrar Medallas" << endl;
    cout << "3. Mostrar Medallero Final" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void registrarAtleta(vector<Atleta> &atletas) {
    Atleta nuevoAtleta;
    cout << "\n--- Registro de Atleta ---" << endl;
    cout << "Nombre del atleta: ";
    getline(cin, nuevoAtleta.nombre);
    cout << "Departamento que representa: ";
    getline(cin, nuevoAtleta.departamento);
    cout << "Deporte que practica (Tiro con arco, Atletismo, Boxeo, Ciclismo, Natacion, Esgrima): ";
    getline(cin, nuevoAtleta.deporte);
    nuevoAtleta.medallas = 0; // Inicializa el contador de medallas en 0
    atletas.push_back(nuevoAtleta);
    cout << "Atleta registrado exitosamente." << endl;
}

void registrarMedallas(vector<Atleta> &atletas) {
    if (atletas.empty()) {
        cout << "No hay atletas registrados. Registre al menos un atleta primero." << endl;
        return;
    }

    string nombre;
    cout << "\n--- Registrar Medallas ---" << endl;
    cout << "Ingrese el nombre del atleta: ";
    getline(cin, nombre);

    bool encontrado = false;
    for (auto &atleta : atletas) {
        if (atleta.nombre == nombre) {
            int medallasGanadas;
            cout << "Cuantas medallas ha ganado " << atleta.nombre << "? ";
            cin >> medallasGanadas;
            cin.ignore(); 
            atleta.medallas += medallasGanadas;
            cout << "Medallas registradas exitosamente." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Atleta no encontrado. Intente nuevamente." << endl;
    }
}

void mostrarMedallero(const vector<Atleta> &atletas) {

    map<string, int> medalleroPorDepartamento;

    for (const auto &atleta : atletas) {
        medalleroPorDepartamento[atleta.departamento] += atleta.medallas;
    }
    cout << "\n--- Medallero Final por Departamento ---" << endl;
    for (const auto &item : medalleroPorDepartamento) {
        cout << "Departamento: " << item.first << " - Medallas: " << item.second << endl;
    }
}

