#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "torneo.h"
#include "utilerias.h"
#include "escenario_prueba.h"

const int COL_LOCAL = 0;
const int COL_VISITANTE = 1;
const int OPCION_ALEATORIO = 1;
const int OPCION_PRUEBA = 2;
const int ANCHO_NUM = 4;
const int ANCHO_EQUIPO = 17;
const int ANCHO_MARCADOR = 10;

inline void generarPartidos(Partido partidos[], int totalEquipos) {
    int k = 0;
    for (int i = 0; i < totalEquipos; i++) {
        for (int j = i + 1; j < totalEquipos; j++) {
            partidos[k].local = i;
            partidos[k].visitante = j;
            partidos[k].golesLocal = 0;
            partidos[k].golesVisitante = 0;
            k++;
        }
    }
}


inline void asignarMarcadores(Partido partidos[], int totalPartidos, bool modoPrueba) {
    for (int k = 0; k < totalPartidos; k++) {
        if (modoPrueba) {
            partidos[k].golesLocal = GOLES_PRUEBA[k][COL_LOCAL];
            partidos[k].golesVisitante = GOLES_PRUEBA[k][COL_VISITANTE];
        } else {
            partidos[k].golesLocal = numeroAleatorio();
            partidos[k].golesVisitante = numeroAleatorio();
        }
    }
}


inline bool pedirModoSimulacion() {
    while (true) {
        int opcion = leerEntero("Modo de simulacion (1 = aleatorio, 2 = prueba): ");
        if (opcion == OPCION_ALEATORIO) return false;
        if (opcion == OPCION_PRUEBA) return true;
        std::cout << "Opcion no valida. Elige 1 o 2.\n";
    }
}

inline void simularPartidos(int totalEquipos, Partido partidos[], int& totalPartidos) {
    if (totalEquipos < MAX_EQUIPOS) {
        std::cout << "Faltan equipos para simular el torneo.\n";
        return;
    }
    if (totalPartidos > 0) {
        std::cout << "El torneo ya fue simulado.\n";
        return;
    }
    bool modoPrueba = pedirModoSimulacion();
    generarPartidos(partidos, totalEquipos);
    totalPartidos = TOTAL_PARTIDOS;
    asignarMarcadores(partidos, totalPartidos, modoPrueba);
    std::cout << "Torneo simulado correctamente.\n";
}


inline void mostrarResultados(const Equipo equipos[], const Partido partidos[], int totalPartidos) {
    if (totalPartidos == 0) {
        std::cout << "Primero simula el torneo.\n";
        return;
    }