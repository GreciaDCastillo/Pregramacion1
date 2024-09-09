// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/09/2024
// Número de ejercicio: 10
// Problema:  En una guardería hay N niños de 1, 2 y 3 años. Calcular la cantidad de pañales consumen.


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void cantidadInfantes(int num, int &anio1, int &anio2, int &anio3);
int cantidadPanales(int anio1, int anio2, int anio3);


int main(){

    int n, anio1, anio2, anio3;
    cout << "Ingrese la cantidad de infantes: ";
    cin >> n;

    srand(time(NULL));

    cout << "Los niños de 1 año consumen 6 pañales" << endl;
    cout << "Los años de 2 años consumen 3 pañales" << endl;
    cout << "Los años de 3 años consumen 2 pañales" << endl;

    cantidadInfantes(n, anio1, anio2, anio3); 

    int total = cantidadPanales(anio1, anio2, anio3);

    cout << "La cantidad de pañales consumen es: " << total << endl;

    return 0;
}

void cantidadInfantes(int num, int &anio1, int &anio2, int &anio3){
    anio1 =  anio2 = anio3 = 0;
    for (int i = 0; i < num; i++){
        int infantesEdad = 1 + rand() % 3; // random entre 1 y 3
        cout  << infantesEdad << " ";
        if (infantesEdad == 1){
            anio1++;
        } else if (infantesEdad == 2){
            anio2++;
        } else if (infantesEdad == 3){
            anio3++;
        }
    }
    cout << endl;
    cout << "niños de 1: " << anio1 << endl;
    cout << "niños de 2: " << anio2 << endl;
    cout << "niños de 3: " << anio3 << endl;
}

int cantidadPanales(int anio1, int anio2, int anio3){
    return (anio1 * 6) + (anio2 * 3) + (anio3 * 2); 
}