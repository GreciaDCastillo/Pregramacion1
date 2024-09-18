// Materia: Programación I, Paralelo 1
// Autor: Grecia Daniela Castillo Ali.
// Fecha creación: 18/09/2024
// Número de ejercicio: 10
// Problema planteado: 
/*
        Un arreglo contiene las calificaciones de un examen dado por un grupo de
        estudiantes, otro arreglo contiene los nombres de los mismos y un tercer arreglo contiene
        la sigla de la carrera. Escribir un programa que permita obtener el nombre del alumno que
        obtuvo la mayor y el nombre del alumno que obtuvo la nota menor, además mostrar que
        carrera tuvo un desempeño mayor con relación al promedio del curso.
*/

#include <iostream>
#include <string>
using namespace std;

void obtenerMayorYMenorCalificacion(const string nombres[], const double calificaciones[], int numEstudiantes, string &nombreMayor, double &calificacionMayor, string &nombreMenor, double &calificacionMenor);
double calcularPromedioCurso(const double calificaciones[], int numEstudiantes);
void carreraConMejorDesempeno(const string carreras[], const double calificaciones[], int numEstudiantes, double promedioCurso);

int main() {
    const int numEstudiantes = 5;  // Número de estudiantes
    string nombres[numEstudiantes];
    double calificaciones[numEstudiantes];
    string carreras[numEstudiantes];

    cout << "Introduce los nombres, calificaciones y carreras de los estudiantes:" << endl;
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> nombres[i];
        cout << "Calificación: ";
        cin >> calificaciones[i];
        cout << "Carrera (sigla): ";
        cin >> carreras[i];
    }

    string nombreMayor, nombreMenor;
    double calificacionMayor = 0, calificacionMenor = 0;

    obtenerMayorYMenorCalificacion(nombres, calificaciones, numEstudiantes, nombreMayor, calificacionMayor, nombreMenor, calificacionMenor);

    cout << "\nEstudiante con la mayor calificación: " << nombreMayor << " (Calificación: " << calificacionMayor << ")" << endl;
    cout << "Estudiante con la menor calificación: " << nombreMenor << " (Calificación: " << calificacionMenor << ")" << endl;
    
    double promedioCurso = calcularPromedioCurso(calificaciones, numEstudiantes);
    cout << "\nPromedio del curso: " << promedioCurso << endl;

    carreraConMejorDesempeno(carreras, calificaciones, numEstudiantes, promedioCurso);

    return 0;
}

void obtenerMayorYMenorCalificacion(const string nombres[], const double calificaciones[], int numEstudiantes, string &nombreMayor, double &calificacionMayor, string &nombreMenor, double &calificacionMenor) {
    calificacionMayor = calificaciones[0];
    calificacionMenor = calificaciones[0];
    nombreMayor = nombres[0];
    nombreMenor = nombres[0];

    for (int i = 1; i < numEstudiantes; i++) {
        if (calificaciones[i] > calificacionMayor) {
            calificacionMayor = calificaciones[i];
            nombreMayor = nombres[i];
        }
        if (calificaciones[i] < calificacionMenor) {
            calificacionMenor = calificaciones[i];
            nombreMenor = nombres[i];
        }
    }
}

double calcularPromedioCurso(const double calificaciones[], int numEstudiantes) {
    double suma = 0.0;
    for (int i = 0; i < numEstudiantes; i++) {
        suma += calificaciones[i];
    }
    return suma / numEstudiantes;
}


void carreraConMejorDesempeno(const string carreras[], const double calificaciones[], int numEstudiantes, double promedioCurso) {
    string carreraMejor;
    double sumaCarrera = 0.0;
    int conteoCarrera = 0;

    for (int i = 0; i < numEstudiantes; i++) {
        if (calificaciones[i] > promedioCurso) {
            carreraMejor = carreras[i];
            sumaCarrera += calificaciones[i];
            conteoCarrera++;
        }
    }

    if (conteoCarrera > 0) {
        cout << "Carrera con mejor desempeño en relación al promedio del curso: " << carreraMejor << endl;
    } else {
        cout << "Ninguna carrera tuvo un desempeño mejor que el promedio del curso." << endl;
    }
}
