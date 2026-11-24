#pragma once

// =====================================================
// MODULO 4: CLASIFICACION Y CAMPEON
//
// Ordena la tabla por puntos, la muestra, detecta empates
// en el primer lugar y deja que el usuario elija al campeon
// entre los equipos empatados.
//
// Temas: ordenamiento, intercambio de registros, apuntadores.
// =====================================================

#include <iostream>
#include <iomanip>
#include <limits>

#include "torneo.h"

// Intercambia el contenido de dos equipos.
//
// Recibe: apuntadores a los dos equipos (se modifican).
// Devuelve: nada.
inline void intercambiar(Equipo* a, Equipo* b) {
    Equipo temporal = *a;
    *a = *b;
    *b = temporal;
}

// Ordena los equipos de mayor a menor puntos (burbuja).
// Solo se intercambia cuando el de la derecha tiene MAS puntos,
// asi los equipos empatados conservan su orden de registro.
//
// Recibe: el arreglo de equipos (se modifica) y cuantos hay.
// Devuelve: nada.
inline void ordenarTabla(Equipo equipos[], int totalEquipos) {
    for (int i = 0; i < totalEquipos - 1; i++) {
        for (int j = 0; j < totalEquipos - 1 - i; j++) {
            if (equipos[j].puntos < equipos[j + 1].puntos) {
                intercambiar(&equipos[j], &equipos[j + 1]);
            }
        }
    }
}

// Muestra la tabla de posiciones (se espera ya ordenada).
//
// Recibe: el arreglo de equipos (solo se lee) y cuantos hay.
// Devuelve: nada.
inline void mostrarTabla(const Equipo equipos[], int totalEquipos) {
    std::cout << "\n" << std::left
              << std::setw(4)  << "#"
              << std::setw(20) << "Equipo"
              << std::right
              << std::setw(5) << "PJ"
              << std::setw(5) << "PG"
              << std::setw(5) << "PE"
              << std::setw(5) << "PP"
              << std::setw(5) << "GF"
              << std::setw(5) << "GC"
              << std::setw(6) << "PTS" << "\n";
    std::cout << std::string(55, '-') << "\n";

    for (int i = 0; i < totalEquipos; i++) {
        std::cout << std::left
                  << std::setw(4)  << (i + 1)
                  << std::setw(20) << equipos[i].nombre
                  << std::right
                  << std::setw(5) << equipos[i].jugados
                  << std::setw(5) << equipos[i].ganados
                  << std::setw(5) << equipos[i].empatados
                  << std::setw(5) << equipos[i].perdidos
                  << std::setw(5) << equipos[i].golesFavor
                  << std::setw(5) << equipos[i].golesContra
                  << std::setw(6) << equipos[i].puntos << "\n";
    }
    std::cout << "\n";
}

// Cuenta cuantos equipos comparten el primer lugar (mismos puntos
// que el lider). Como la tabla esta ordenada, son los primeros.
//
// Recibe: el arreglo ordenado (solo se lee) y cuantos hay.
// Devuelve: cuantos equipos estan empatados en el primer lugar
//           (1 si no hay empate, 0 si no hay equipos).
inline int contarEmpatadosPrimero(const Equipo equipos[], int totalEquipos) {
    if (totalEquipos <= 0) {
        return 0;
    }

    int cantidad = 1;
    while (cantidad < totalEquipos &&
           equipos[cantidad].puntos == equipos[0].puntos) {
        cantidad++;
    }
    return cantidad;
}

// Pide al usuario que elija al campeon entre los empatados.
// Repite la pregunta hasta recibir una opcion valida.
//
// Recibe: el arreglo ordenado (solo se lee) y cuantos empatados hay.
// Devuelve: la posicion (indice) del equipo elegido.
inline int elegirCampeon(const Equipo equipos[], int empatados) {
    std::cout << "Hay " << empatados << " equipos empatados en el primer lugar:\n";
    for (int i = 0; i < empatados; i++) {
        std::cout << "  " << (i + 1) << ". " << equipos[i].nombre << "\n";
    }

    int opcion = 0;
    while (true) {
        std::cout << "Elige al campeon (1-" << empatados << "): ";
        if (std::cin >> opcion && opcion >= 1 && opcion <= empatados) {
            return opcion - 1;
        }
        std::cout << "Opcion no valida.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Flujo completo del modulo: ordena, muestra, detecta empate
// y anuncia al campeon.
//
// Recibe: el arreglo de equipos (se modifica al ordenarse) y cuantos hay.
// Devuelve: nada.
inline void mostrarClasificacion(Equipo equipos[], int totalEquipos) {
    if (totalEquipos <= 0) {
        std::cout << "No hay equipos registrados.\n";
        return;
    }

    ordenarTabla(equipos, totalEquipos);
    mostrarTabla(equipos, totalEquipos);

    int empatados = contarEmpatadosPrimero(equipos, totalEquipos);
    int campeon = 0;

    if (empatados > 1) {
        campeon = elegirCampeon(equipos, empatados);
    }

    std::cout << "\nEl campeon es: " << equipos[campeon].nombre
              << " con " << equipos[campeon].puntos << " puntos.\n";
}