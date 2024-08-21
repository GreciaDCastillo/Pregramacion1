// Materia: Programación I, Paralelo 4
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 20/08/2024
// Número de ejercicio: 17
// Problema planteado: Transformar decimal a binario.

#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;
 
    int binarioInvertido = 0; // Almacena el binario invertido
    int factor = 1; //Ajusta la posición de los digitos 

    while (numero > 0) {
        int digito = numero % 2; // Obtener el dígito binario
        binarioInvertido += digito * factor; 
        factor *= 10;
        numero /= 2;
    }
    cout << "El binario de " << numero << " es: " << binarioInvertido << endl;

    return 0;
}