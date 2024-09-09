// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/09/2024
// Número de ejercicio: 9
// Problema planteado: Generar secuencia 

/*
        1 0 1 0 1
        0 1 0 1 0
        1 0 1 0 1
        0 1 0 1 0
        1 0 1 0 1
*/

#include <iostream>
using namespace std;

void secuencia(int n);

int main(){

    int n;
    cout << "Introduce el número de terminos: ";
    cin >> n;
    cout << "\nLa secuencia es: \n";
    cout << endl;

    secuencia(n);
    
    return 0;
}

void secuencia(int n){
    for (int i = 0; i < n; i++){ // Bucle para las filas
        for (int j = 0; j < n; j++){ // Bucle para las columnas
            if ((i + j) % 2 == 0){ // si la suma de i y j es par 
                cout << 1 << " ";
            }else{
                cout << 0 << " ";
            }
        } 
        cout << endl;
    }              
}