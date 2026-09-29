#ifndef ALGORITMOS_H
#define ALGORITMOS_H
using namespace std;
#include <vector>
#include <string>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Pelicula {
    string titulo;
    Fecha estreno;
    double rating;
};

struct Estadisticas {
    long long comparaciones = 0;
    long long movimientos = 0;
    long long particiones = 0;
    long long fusiones = 0;
};

extern Estadisticas stats;

void quickSortAnio(vector<Pelicula>& peliculas, int inicio, int fin);
void mergeSortMes(vector<Pelicula>& peliculas, int inicio, int fin);
void insertionSortDia(vector<Pelicula>& peliculas, int inicio, int fin);
void mergeSortDia(vector<Pelicula>& peliculas, int inicio, int fin);

double porcentajeDesordenDias(
    const vector<Pelicula>& peliculas,
    int inicio,
    int fin
);

#endif