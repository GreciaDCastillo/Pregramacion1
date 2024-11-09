// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/11/2024
// Número de ejercicio: 7
// Problema planteado: Funcion recursiva para generar una secuencia:  1, 1, 2, 4, 8, 16, 23, 28, 38,49,..., para n términos.

#include <iostream>
using namespace std;

int generarSecuenciaRecursiva(int n, int terminoActual, int indice);
int sumaDigitosRecursiva(int numero);

int main() {

    int n;
    cout << "Ingrese el número de términos de la secuencia: ";
    cin >> n;

    cout << "Secuencia generada: ";
    generarSecuenciaRecursiva(n, 1, 1); // Inicializamos con el primer término y el índice en 1

    cout << endl;
    return 0;
}

int sumaDigitosRecursiva(int numero) { // Función recursiva para sumar los dígitos de un número
    if (numero == 0) {
        return 0;
    }
    return (numero % 10) + sumaDigitosRecursiva(numero / 10);
}

int generarSecuenciaRecursiva(int n, int terminoActual, int indice) {

    if (indice >= n) {
        return 0;
    }

    cout << terminoActual << " ";


    int suma = (terminoActual < 10) ? terminoActual : sumaDigitosRecursiva(terminoActual);
    int siguienteTermino = terminoActual + suma;


    return generarSecuenciaRecursiva(n, siguienteTermino, indice + 1);     // Llamada recursiva al siguiente término
}