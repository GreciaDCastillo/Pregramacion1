// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 06/11/2024
// Número de ejercicio: 4
// Problema planteado: Funcion recursiva y verificar si un numero se encuentra en una cadena dada.

#include <iostream> 
using namespace std;

bool buscar(int vector[10], int num, int i);

int main(){ 
    int vector[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num;
    cout << "Ingrese el numero a buscar: ";
    cin >> num;

    if(buscar(vector, num, 0)){
        cout << "El numero se encuentra en la cadena" << endl;
    }else{
        cout << "El numero no se encuentra en la cadena" << endl;
    }

    return 0;
}

bool buscar(int vector[10], int num, int i){ 
    if(i == 10){
        return false;
    }
    if(vector[i] == num){
        return true;
    }
    return buscar(vector, num, i + 1); // Llamada recursiva que recorre el vector
}
