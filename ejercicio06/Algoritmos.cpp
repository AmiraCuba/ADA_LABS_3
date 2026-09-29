#include "Algoritmos.h"
#include <algorithm>
using namespace std;

// =================== ESTADÍSTICAS ===================
Estadisticas stats;

// Intercambios
static void intercambiar(Pelicula& a, Pelicula& b) {
    swap(a, b);
    stats.movimientos++;
}

// =================== QUICK SORT - AÑO ===================
static int particionAnio(vector<Pelicula>& peliculas, int inicio, int fin) {
    stats.particiones++;

    int medio = inicio + (fin - inicio) / 2;
    intercambiar(peliculas[medio], peliculas[fin]);

    int pivote = peliculas[fin].estreno.anio;
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        stats.comparaciones++;

        if (peliculas[j].estreno.anio <= pivote) {
            i++;
            if (i != j) {
                intercambiar(
                    peliculas[i],
                    peliculas[j]
                );
            }
        }
    }

    intercambiar(peliculas[i + 1], peliculas[fin]);

    return i + 1;
}

void quickSortAnio(vector<Pelicula>& peliculas, int inicio, int fin) {
    if (inicio >= fin)
        return;

    int pivote = particionAnio(peliculas, inicio, fin);
    quickSortAnio(peliculas, inicio, pivote - 1);
    quickSortAnio(peliculas, pivote + 1, fin);
}

// =================== MERGE SORT - MES ===================
static void mergeMes(vector<Pelicula>& peliculas, int inicio, int medio, int fin) {
    stats.fusiones++;

    vector<Pelicula> izquierda(peliculas.begin() + inicio, peliculas.begin() + medio + 1);
    vector<Pelicula> derecha(peliculas.begin() + medio + 1, peliculas.begin() + fin + 1);

    int i = 0, j = 0, k = inicio;

    while (i < (int)izquierda.size() && j < (int)derecha.size()) {
        stats.comparaciones++;

        if (izquierda[i].estreno.mes <= derecha[j].estreno.mes) {
            peliculas[k++] = izquierda[i++];
        } else {
            peliculas[k++] = derecha[j++];
        }

        stats.movimientos++;
    }

    while (i < (int)izquierda.size()) {
        peliculas[k++] = izquierda[i++];

        stats.movimientos++;
    }

    while (j < (int)derecha.size()) {
        peliculas[k++] = derecha[j++];

        stats.movimientos++;
    }
}

void mergeSortMes(vector<Pelicula>& peliculas, int inicio, int fin) {
    if (inicio >= fin)
        return;

    int medio = inicio + (fin - inicio) / 2;
    mergeSortMes(peliculas, inicio, medio);
    mergeSortMes(peliculas, medio + 1, fin);

    mergeMes(peliculas, inicio, medio, fin);
}

// =================== INSERTION SORT - DÍA ===================
void insertionSortDia(vector<Pelicula>& peliculas, int inicio, int fin) {
    for (int i = inicio + 1; i <= fin; i++) {
        Pelicula clave = peliculas[i];
        int j = i - 1;

        while (j >= inicio) {
            stats.comparaciones++;

            if (peliculas[j].estreno.dia <= clave.estreno.dia) {
                break;
            }
            peliculas[j + 1] = peliculas[j];

            stats.movimientos++;

            j--;
        }
        peliculas[j + 1] = clave;

        stats.movimientos++;
    }
}

// =================== MERGE SORT - DÍA ===================
static void mergeDia(vector<Pelicula>& peliculas, int inicio, int medio, int fin) {
    stats.fusiones++;

    vector<Pelicula> izquierda(peliculas.begin() + inicio, peliculas.begin() + medio + 1);
    vector<Pelicula> derecha(peliculas.begin() + medio + 1, peliculas.begin() + fin + 1);

    int i = 0, j = 0, k = inicio;

    while (i < (int)izquierda.size() && j < (int)derecha.size()) {
        stats.comparaciones++;

        if (izquierda[i].estreno.dia <= derecha[j].estreno.dia) {
            peliculas[k++] = izquierda[i++];
        } else {
            peliculas[k++] = derecha[j++];
        }

        stats.movimientos++;
    }

    while (i < (int)izquierda.size()) {
        peliculas[k++] = izquierda[i++];

        stats.movimientos++;
    }

    while (j < (int)derecha.size()) {
        peliculas[k++] = derecha[j++];

        stats.movimientos++;
    }
}

void mergeSortDia(vector<Pelicula>& peliculas, int inicio, int fin) {
    if (inicio >= fin)
        return;

    int medio = inicio + (fin - inicio) / 2;

    mergeSortDia(peliculas, inicio, medio);
    mergeSortDia(peliculas, medio + 1, fin);

    mergeDia(peliculas, inicio, medio, fin);
}

// =================== PORCENTAJE DE DESORDEN ===================
double porcentajeDesordenDias(const vector<Pelicula>& peliculas, int inicio, int fin) {
    if (fin <= inicio)
        return 0.0;

    int desorden = 0;
    int total = 0;

    for (int i = inicio; i < fin; i++) {
        total++;

        if (peliculas[i].estreno.dia > peliculas[i + 1].estreno.dia) {
            desorden++;
        }
    }

    if (total == 0)
        return 0.0;

    return ((double)desorden / (double)total) * 100.0;
}