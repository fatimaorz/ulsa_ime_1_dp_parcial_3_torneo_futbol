
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "torneo.h"

// 1. Construir la matriz de enfrentamientos
inline void construirMatriz(
    int matriz[][MAX_EQUIPOS],
    const Partido partidos[],
    int totalPartidos)
{
    for (int i = 0; i < totalPartidos; i++)
    {
        const Partido& partido = partidos[i];

        matriz[partido.local][partido.visitante] = partido.golesLocal;

        matriz[partido.visitante][partido.local] = partido.golesVisitante;
    }
}

// 2. Mostrar la matriz de enfrentamientos
inline void mostrarMatriz(
    const Equipo equipos[],
    const Partido partidos[])
{
    int matriz[MAX_EQUIPOS][MAX_EQUIPOS] = {};

    construirMatriz(matriz, partidos, TOTAL_PARTIDOS);

    std::cout << "\n--- MATRIZ DE ENFRENTAMIENTOS ---\n";

    // Mostrar encabezados de las columnas
    std::cout << std::left << std::setw(17) << "";

    for (int j = 0; j < MAX_EQUIPOS; j++)
    {
        std::string abreviatura =
            equipos[j].nombre.substr(0, CARACTERES_ABREVIATURA);

        for (int k = 0; k < static_cast<int>(abreviatura.length()); k++)
        {
            abreviatura[k] = static_cast<char>(
                std::toupper(static_cast<unsigned char>(abreviatura[k]))
            );
        }

        std::cout << std::right << std::setw(6) << abreviatura;
    }

    std::cout << '\n';

    // Recorrer las filas de la matriz
    for (int i = 0; i < MAX_EQUIPOS; i++)
    {
        std::cout << std::left << std::setw(17) << equipos[i].nombre;

        for (int j = 0; j < MAX_EQUIPOS; j++)
        {
            if (i == j)
            {
                std::cout << std::right << std::setw(6) << "---";
            }
            else
            {
                std::string marcador =
                    std::to_string(matriz[i][j]) + "-" +
                    std::to_string(matriz[j][i]);

                std::cout << std::right << std::setw(6) << marcador;
            }
        }

        std::cout << '\n';
    }
}
