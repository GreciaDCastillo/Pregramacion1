// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 16/10/2024
// Número de ejercicio: 15
// Problema planteado: Escribe un programa que que valide si una expresión matemática tiene los
//                     paréntesis balanceados correctamente. La expresión puede contener los
//                     siguientes tipos de paréntesis: (), {}, [].

#include <iostream>
using namespace std;

bool esBalanceada(const string& expresion) {
    int contador = 0;  // Contador para paréntesis balanceados


    for (char c : expresion) { // Recorrer la expresión carácter por carácter
        if (c == '(' || c == '{' || c == '[') {
            contador++;  
        } else if (c == ')' || c == '}' || c == ']') {
            contador--;  
        }

        if (contador < 0) {
            return false;  // No balanceada
        }
    }

    return contador == 0;
}

int main() {
    string expresion;
    cout << "Escribe una expresión: ";
    getline(cin, expresion);  

    // Verificar si la expresión tiene paréntesis balanceados
    if (esBalanceada(expresion)) {
        cout << "La expresión tiene los paréntesis balanceados correctamente." << endl;
    } else {
        cout << "La expresión no tiene los paréntesis balanceados correctamente." << endl;
    }

    return 0;
}
