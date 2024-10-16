// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 15/10/2024
// Número de ejercicio: 7
// Problema planteado: Escribe un programa que cuente la frecuencia de cada carácter en una cadena.

#include <iostream>
using namespace std;

void contarCaracteres(string cadena) {
    int frecuencia[26] = {0};
    for (int i = 0; i < cadena.length(); i++) {
        frecuencia[cadena[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (frecuencia[i] > 0) {
            cout << (char)('a' + i) << ": " << frecuencia[i] << endl; // Imprime el carácter y su frecuencia
        }
    }
}
int main() {

    string cadena;
    cout << "Escribe una cadena: ";
    cin >> cadena;
    contarCaracteres(cadena);

    return 0;

}