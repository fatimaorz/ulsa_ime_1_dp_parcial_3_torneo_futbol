#pragma once

#include "torneo.h"

inline void reiniciarEstadisticas(Equipo& equipo) {
    equipo.jugados = 0;
    equipo.ganados = 0;
    equipo.empatados = 0;
    equipo.perdidos = 0;
    equipo.golesFavor = 0;
    equipo.golesContra = 0;
    equipo.puntos = 0;
}


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


inline void aplicarPartido(const Partido& partido, Equipo& local, Equipo& visitante) {
    registrarResultado(local, partido.golesLocal, partido.golesVisitante);
    registrarResultado(visitante, partido.golesVisitante, partido.golesLocal);
}


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
