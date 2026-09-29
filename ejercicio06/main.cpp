#include <iostream>
#include <vector>
#include <iomanip>
#include "Algoritmos.h"
#include "HybridSort.h"

using namespace std;

void mostrarFecha(const Fecha& fecha) {
    cout << setfill('0') << setw(2) << fecha.dia << "/"
         << setw(2) << fecha.mes << "/" << setw(4) << fecha.anio
         << setfill(' ');
}

void mostrarPelicula(const Pelicula& pelicula) {
    cout << left << setw(25) << pelicula.titulo;
    mostrarFecha(pelicula.estreno);
    cout << "   Rating: " << fixed << setprecision(1)
         << pelicula.rating << endl;
}

void mostrarLista(const vector<Pelicula>& peliculas) {
    for (const Pelicula& pelicula : peliculas)
        mostrarPelicula(pelicula);
}

int main() {
    vector<Pelicula> peliculas = {
        {"Titanic", {19, 12, 1997}, 7.9},
        {"Matrix", {31, 3, 1999}, 8.7},
        {"El Senor de los Anillos", {19, 12, 2001}, 8.8},
        {"Avatar", {18, 12, 2009}, 7.8},
        {"Inception", {16, 7, 2010}, 8.8},
        {"Interstellar", {7, 11, 2014}, 8.7},
        {"Avengers Endgame", {26, 4, 2019}, 8.4},
        {"Joker", {4, 10, 2019}, 8.4},
        {"Dune", {22, 10, 2021}, 8.0},
        {"Batman", {4, 3, 2022}, 7.5},
        {"Oppenheimer", {21, 7, 2023}, 8.6},
        {"Dune Parte Dos", {1, 3, 2024}, 8.5}
    };

    cout << "       CATALOGO DE PELICULAS\n";
    cout << "Antes del ordenamiento:\n\n";
    mostrarLista(peliculas);

    stats = Estadisticas();
    hybridMovieSort(peliculas);

    cout << "\n\n       DESPUES DEL ORDENAMIENTO\n";

    mostrarLista(peliculas);

    cout << "\n\n           ESTADISTICAS\n";
    cout << "Comparaciones: " << stats.comparaciones << endl;
    cout << "Movimientos: " << stats.movimientos << endl;
    cout << "Particiones Quick Sort: " << stats.particiones << endl;
    cout << "Fusiones Merge Sort: " << stats.fusiones << endl;

    cout << "\nOrden correcto: ";
    cout << (estaOrdenado(peliculas) ? "SI\n" : "NO\n");

    return 0;
}