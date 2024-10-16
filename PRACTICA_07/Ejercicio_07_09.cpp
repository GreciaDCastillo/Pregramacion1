// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 16/10/2024
// Número de ejercicio: 9
// Problema planteado: Escribe un programa que agrupe caracteres consecutivos y cuente su frecuencia.

#include <iostream>
using namespace std;

void agruparCaracteres(string cadena) {
    int contador = 1; // Empezamos contando el primer carácter
    for (int i = 0; i < cadena.length(); i++) {
        if (i < cadena.length() - 1 && cadena[i] == cadena[i + 1]) {
            contador++;
        } else {
            cout << cadena[i] << contador; // Imprimir el carácter y su cuenta
            contador = 1; // Reiniciar el contador
        }
    }
    cout << endl;
}

int main() {
    string cadena;
    cout << "Introduce una cadena: ";
    getline(cin, cadena);
    agruparCaracteres(cadena);
    return 0;
}
