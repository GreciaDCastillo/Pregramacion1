// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 16/09/2024
// Número de ejercicio: 1
// Problema planteado: Arreglos de diferentes dimensiones.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void VoltajeArray(int nvolt, double voltaje[]);
void TemperaturaArray(int ntemp, double temperatura[]);
void CaracteresArray(int ncaract, char caracteres[]);
void AniosArray(int nanio, int ainos[]);
void VelocidadArray(int nvel, double velocidad[]);
void DistanciaArray(int ndistancia, double distancia[]);
void Digitos6Array(int num, int digitos6[]);


int main() {
    srand(time(NULL));
    
    // Lista de voltajes de precisión doble
    int nvolt = 100;
    double voltaje[nvolt];
    cout << "\nLista de voltajes: \n";
    cout << endl;
    VoltajeArray(nvolt, voltaje);

    // Lista de temperaturas de precisión doble
    int ntemp = 50;
    double temperatura[ntemp];
    cout << "\nLista de temperatura: \n";
    cout << endl;
    TemperaturaArray(ntemp, temperatura);

    // Lista de caracteres
    int ncaract = 30;
    char caracteres[ncaract];
    cout << "\nLista de caracteres: \n";
    cout << endl;
    CaracteresArray(ncaract, caracteres);

    // Lista de años en número entero
    int nanio = 100;
    int ainos[nanio];
    cout << "\nLista de años: \n";
    cout << endl;
    AniosArray(nanio, ainos);

    // Lista de velocidades de precisión doble
    int nvel = 32;
    double velocidad[nvel];
    cout << "\nLista de velocidades: \n";
    cout << endl;
    VelocidadArray(nvel, velocidad);

    // Lista de distancias de precisión doble
    int ndistancia = 1000;
    double distancia[ndistancia];
    cout << "\nLista de distancias: \n";
    cout << endl;
    DistanciaArray(ndistancia, distancia);

    // Lista de 6 números de código enteros
    int num = 6;
    int digitos6[num];
    cout << "\nLista de 6 dígitos: \n";
    cout << endl;
    Digitos6Array(num, digitos6);

    return 0;
}

void VoltajeArray(int nvolt, double voltaje[]) {
    for (int i = 0; i < nvolt; i++) {
        voltaje[i] = rand() % (240 - 120 + 1) + 120;
        cout << voltaje[i] << "V - ";
        if ((i + 1) % 10 == 0) 
            cout << endl;
    }
}

void TemperaturaArray(int ntemp, double temperatura[]) {
    for (int i = 0; i < ntemp; i++) {
        temperatura[i] = rand() % (100 - 0 + 1) + 0;
        cout << temperatura[i] << "C - ";
        if ((i + 1) % 10 == 0) 
            cout << endl;
    }
}

void CaracteresArray(int ncaract, char caracteres[]) {
    for (int i = 0; i < ncaract; i++) {
        int caracter = rand() % (122 - 97 + 1) + 97; // random entre 97 y 122 que son las letras del alfabeto (minusculas) en ascii
        caracteres[i] = (char)caracter;
        cout << "caracter " << i + 1 << ": " << caracteres[i] << " - " << "(ASCII: " << (int)caracteres[i] << ")\t";
        if ((i + 1) % 3 == 0) 
            cout << endl;
    }
}

void AniosArray(int nanio, int ainos[]) {
    for (int i = 0; i < nanio; i++) {
        ainos[i] = rand() % (98 - 0 + 1) + 0;
        cout << ainos[i] << " - ";
        if ((i + 1) % 10 == 0) 
            cout << endl;
    }
}

void VelocidadArray(int nvel, double velocidad[]) {
    for (int i = 0; i < nvel; i++) {
        velocidad[i] = rand() % (120 - 10 + 1) + 10;
        cout << velocidad[i] << " - ";
        if ((i + 1) % 8 == 0) 
            cout << endl;
    }
}

void DistanciaArray(int ndistancia, double distancia[]) {
    for (int i = 0; i < ndistancia; i++) {
        distancia[i] = rand() % (100 - 0 + 1) + 0;
        cout << distancia[i] << " - ";
        if ((i + 1) % 10 == 0) 
            cout << endl;
    }
}

void Digitos6Array(int num, int digitos6[]) {
    for (int i = 0; i < num; i++) {
        digitos6[i] = rand() % (999999 - 100000 + 1) + 100000;
        cout << digitos6[i] << " - ";
        if ((i + 1) % 6 == 0) 
            cout << endl;
    }
}
