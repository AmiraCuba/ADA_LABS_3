#include "HybridSort.h"
#include "Algoritmos.h"
using namespace std;

// =================== HYBRID MOVIE SORT ===================

void hybridMovieSort(vector<Pelicula>& peliculas) {
    int n = peliculas.size();

    if (n <= 1)
        return;

    // ETAPA 1 - QUICK SORT
    // Ordenamos todo el catálogo por AÑO.
    quickSortAnio(peliculas, 0, n - 1);

    // ETAPA 2 - MERGE SORT
    // Ahora los años ya están agrupados.
    // Dentro de cada año utilizamos MERGE SORT para ordenar por MES.
    int inicioAnio = 0;

    while (inicioAnio < n) {
        int finAnio = inicioAnio;

        // Encontramos dónde termina el grupo del mismo año.
        while (finAnio + 1 < n && peliculas[finAnio + 1].estreno.anio == 
            peliculas[inicioAnio].estreno.anio) {

            finAnio++;
        }

        // MERGE SORT POR MES
        if (finAnio > inicioAnio) {
            mergeSortMes(peliculas, inicioAnio, finAnio);
        }

        // ETAPA 3 - DECISIÓN DINÁMICA
        // Dentro de cada grupo AÑO + MES se elege dinámicamente:
        // INSERTION SORT o MERGE SORT
        int inicioMes = inicioAnio;
        while (inicioMes <= finAnio) {
            int finMes = inicioMes;

            // Encontramos el grupo del mismo año y mes.
            while (finMes + 1 <= finAnio && peliculas[finMes + 1].estreno.mes ==
                peliculas[inicioMes].estreno.mes) {

                finMes++;
            }

            int tamanio = finMes - inicioMes + 1;

            // DECISIÓN DINÁMICA
            if (tamanio <= 20) {
                insertionSortDia(peliculas, inicioMes, finMes);
            }
            else {
                double desorden = porcentajeDesordenDias(peliculas, inicioMes, finMes);

                if (desorden <= 15.0) {
                    insertionSortDia(peliculas, inicioMes, finMes);
                }
                else {
                    mergeSortDia(peliculas, inicioMes, finMes);
                }
            }

            inicioMes = finMes + 1;
        }

        inicioAnio = finAnio + 1;
    }
}

// VERIFICAR ORDEN FINAL
bool estaOrdenado(const vector<Pelicula>& peliculas) {
    for (size_t i = 1; i < peliculas.size(); i++) {
        const Fecha& anterior = peliculas[i - 1].estreno;
        const Fecha& actual = peliculas[i].estreno;

        // Año
        if (actual.anio < anterior.anio) {
            return false;
        }

        if (actual.anio == anterior.anio) {
            // Mes
            if (actual.mes < anterior.mes) {
                return false;
            }

            if (actual.mes == anterior.mes) {
                // Día
                if (actual.dia < anterior.dia) {
                    return false;
                }
            }
        }
    }

    return true;
}