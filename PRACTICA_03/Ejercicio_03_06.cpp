// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/09/2024
// Número de ejercicio: 6
// Problema planteado: Algoritmo para adivinar un número aleatorio.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void jugarAdivinar( int numeroSecreto );

int main() {
    srand(time(0)); // Inicializa la semilla para números aleatorios

    cout << "\nBienvenido al juego de adivinar un numero" << endl;
    cout << "Adivina el numero entre 1 y 50: " << endl;
    int numeroSecreto =  rand() % 50 + 1;

    jugarAdivinar(numeroSecreto);

    return 0;
}

void jugarAdivinar( int numeroSecreto ) {
    
    int minimo = 0;
    int maximo = 50;
    int numero_Usuario;
    
    for ( int i = 1; i <= 5; i++ ) { // Intenta adivinar 5 veces
        cout << "\nIntento " << i << endl;
        cout << "\nIngresa un número: ";
        cin >> numero_Usuario;

        if ( numero_Usuario == numeroSecreto ) { 
            cout << "Felicitaciones, adivinaste el número!" << endl;
            return;

        } else {
            if ( numero_Usuario < numeroSecreto ) {
                minimo = numero_Usuario;
                cout << "\nEl número esta entre " << minimo << " y " << maximo<< endl;
            } else {
                maximo = numero_Usuario;
                cout << "\nEl número esta entre " << minimo << " y " << maximo << endl;
            }
        }
    }
    cout << "\nLo siento, no adivinaste el número. El número era " << numeroSecreto << endl;
}