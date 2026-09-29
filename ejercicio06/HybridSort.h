#ifndef HYBRIDSORT_H
#define HYBRIDSORT_H

#include <vector>
#include "Algoritmos.h"

// Algoritmo híbrido principal
void hybridMovieSort(
    std::vector<Pelicula>& peliculas
);

// Verifica si el resultado está ordenado.
bool estaOrdenado(
    const std::vector<Pelicula>& peliculas
);

#endif