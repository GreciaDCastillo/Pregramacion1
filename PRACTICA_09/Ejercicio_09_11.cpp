// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali
// Fecha creación: 08/11/2024
// Número de ejercicio: 11
// Problema planteado: Realizar un algoritmo recursivo para el siguiente problema: 
/*
        Un  granjero hacomprado una pareja  de  conejos para criarlos y luego 
        venderlos.  Si la pareja de conejos produce una nueva pareja cada mes
        y la nueva pareja tarda un mes más en ser también productiva, ¿cuántos 
        pares de conejos podrá poner a la venta el granjero al cabo de un año?

*/ 

#include <iostream>
using namespace std;

int calcularConejos(int meses);

int main(){
    int meses = 12;
    int conejosporAnIo = calcularConejos(meses);

    cout << "Al cabo de un año, el granjero podrá poner a la venta " << conejosporAnIo << " pares de conejos." << endl;
    return 0;
}

int calcularConejos(int meses){ //funcion para calcular la cantidad de pares de conejos.
    if(meses == 1 || meses == 2){
        return 1;
    }
    else{
        return calcularConejos(meses - 1) + calcularConejos(meses - 2); //llamada recursiva para calcular la cantidad de pares de conejos
    }
}