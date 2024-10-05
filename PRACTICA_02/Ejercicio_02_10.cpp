// Materia: Programación I, Paralelo 1
// Autor: Grecia Deniela Castillo Ali
// Fecha creación: 04/09/2024
// Número de ejercicio: 10
// Problema planteado:  Leer un númedo de 4 dígitos y ver si al menos 2 son iguales.

#include <iostream>
using namespace std;

int digitosIguales(int num);
int main(){

    int numero;
    cout << "Introduce un número de 4 dígitos: ";
    cin >> numero;

    if (numero < 1000 || numero > 9999){
        cout << "El número debe ser de 4 dígitos." << endl;
        return 1;
    }

    int resultado = digitosIguales(numero);
    if (resultado == 1){
        cout << "Al menos 2 dígitos son iguales." << endl;
    } else {
        cout << "Todos los dígitos son diferentes." << endl;
    }


    return 0;
}

int digitosIguales(int num){

    //Extraer los dígitos
    int d1 = num / 1000;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    if(d1 == d2 || d1 == d3 || d1 == d4 || d2 == d3 || d2 == d4 || d3 == d4){
        return 1;
    }else{
        return 0;
    }
}