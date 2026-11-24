#pragma once

#include "torneo.h"
#include <iostream>
#include <iomanip>

// Muestra los goles anotados por cada equipo contra los demas.
// Las celdas diagonales quedan vacias porque un equipo no juega contra si mismo.
inline void mostrarMatriz(const Equipo equipos[], const Partido partidos[]) {
    int goles[MAX_EQUIPOS][MAX_EQUIPOS] = {};
    bool hayPartido[MAX_EQUIPOS][MAX_EQUIPOS] = {};

    for (int i = 0; i < TOTAL_PARTIDOS; i++) {
        const Partido& partido = partidos[i];
        goles[partido.local][partido.visitante] = partido.golesLocal;
        goles[partido.visitante][partido.local] = partido.golesVisitante;
        hayPartido[partido.local][partido.visitante] = true;
        hayPartido[partido.visitante][partido.local] = true;
    }

    std::cout << "\n--- MATRIZ: GOLES DEL EQUIPO DE LA FILA ---\n"
              << std::left << std::setw(17) << "EQUIPO";
    for (int i = 0; i < MAX_EQUIPOS; i++) {
        std::cout << std::right << std::setw(5) << i + 1;
    }
    std::cout << '\n';

    for (int fila = 0; fila < MAX_EQUIPOS; fila++) {
        std::cout << std::left << std::setw(17) << equipos[fila].nombre;
        for (int columna = 0; columna < MAX_EQUIPOS; columna++) {
            if (hayPartido[fila][columna]) {
                std::cout << std::right << std::setw(5) << goles[fila][columna];
            } else {
                std::cout << std::right << std::setw(5) << "-";
            }
        }
        std::cout << '\n';
    }

    int masGoles = equipos[0].golesFavor;
    int menosGolesRecibidos = equipos[0].golesContra;
    for (int i = 1; i < MAX_EQUIPOS; i++) {
        if (equipos[i].golesFavor > masGoles) {
            masGoles = equipos[i].golesFavor;
        }
        if (equipos[i].golesContra < menosGolesRecibidos) {
            menosGolesRecibidos = equipos[i].golesContra;
        }
    }

    std::cout << "Mejor ataque (" << masGoles << " goles): ";
    bool primero = true;
    for (int i = 0; i < MAX_EQUIPOS; i++) {
        if (equipos[i].golesFavor == masGoles) {
            std::cout << (primero ? "" : ", ") << equipos[i].nombre;
            primero = false;
        }
    }

    std::cout << "\nMejor defensa (" << menosGolesRecibidos
              << " goles recibidos): ";
    primero = true;
    for (int i = 0; i < MAX_EQUIPOS; i++) {
        if (equipos[i].golesContra == menosGolesRecibidos) {
            std::cout << (primero ? "" : ", ") << equipos[i].nombre;
            primero = false;
        }
    }
    std::cout << '\n';
}