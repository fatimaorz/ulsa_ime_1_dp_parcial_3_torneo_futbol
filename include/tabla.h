#pragma once

// =====================================================
// MODULO 3: TABLA DE POSICIONES
// Responsable: Andres Galindo Davila (26113)
//
// Calcula las estadisticas de cada equipo (PJ, PG, PE, PP,
// GF, GC y PTS) a partir de los resultados de los partidos.
// No imprime nada: solo calcula. El reporte lo muestra el
// modulo 4.
//
// Temas: funciones y paso por referencia.
// =====================================================

#include "torneo.h"

// Pone en cero las estadisticas de un equipo.
// No toca el nombre.
//
// Recibe: el equipo, por referencia, porque se modifica.
// Devuelve: nada.
inline void reiniciarEstadisticas(Equipo& equipo) {
    equipo.jugados = 0;
    equipo.ganados = 0;
    equipo.empatados = 0;
    equipo.perdidos = 0;
    equipo.golesFavor = 0;
    equipo.golesContra = 0;
    equipo.puntos = 0;
}

// Registra en un equipo el resultado de un partido que jugo:
// suma el partido jugado, los goles y los puntos que le tocan.
//
// Recibe: el equipo, por referencia, porque se modifica;
//         los goles que anoto y los goles que recibio, por valor.
// Devuelve: nada.
inline void registrarResultado(Equipo& equipo, int golesFavor, int golesContra) {
    equipo.jugados++;
    equipo.golesFavor += golesFavor;
    equipo.golesContra += golesContra;

    if (golesFavor > golesContra) {
        equipo.ganados++;
        equipo.puntos += PUNTOS_VICTORIA;
    } else if (golesFavor == golesContra) {
        equipo.empatados++;
        equipo.puntos += PUNTOS_EMPATE;
    } else {
        equipo.perdidos++;
        equipo.puntos += PUNTOS_DERROTA;
    }
}

// Aplica un partido a los dos equipos que lo jugaron.
// Cada equipo ve el marcador desde su lado: los goles a favor
// del local son los goles en contra del visitante.
//
// Recibe: el partido, por referencia constante (solo se lee);
//         el equipo local y el visitante, por referencia,
//         porque se modifican.
// Devuelve: nada.
inline void aplicarPartido(const Partido& partido, Equipo& local, Equipo& visitante) {
    registrarResultado(local, partido.golesLocal, partido.golesVisitante);
    registrarResultado(visitante, partido.golesVisitante, partido.golesLocal);
}

// Calcula la tabla de posiciones completa.
// Primero pone en cero a todos los equipos y despues recorre
// los partidos, aplicando cada uno a sus dos equipos.
// Los equipos conservan el orden de registro.
//
// Recibe: el arreglo de equipos (se modifica) y cuantos hay;
//         el arreglo de partidos (solo se lee) y cuantos hay.
// Devuelve: nada.
inline void calcularTabla(Equipo equipos[], int totalEquipos,
                          const Partido partidos[], int totalPartidos) {
    for (int i = 0; i < totalEquipos; i++) {
        reiniciarEstadisticas(equipos[i]);
    }

    for (int i = 0; i < totalPartidos; i++) {
        const Partido& partido = partidos[i];
        aplicarPartido(partido, equipos[partido.local], equipos[partido.visitante]);
    }
}
