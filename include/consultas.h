

#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "torneo.h"
#include "utilerias.h"
#include "registros.h"
#include "matriz.h"


using namespace std;

const int ANCHO_RIVAL = 17;
const int ANCHO_MARCADOR = 10;

// Regresa la direccion del equipo, o nullptr si no existe
const Equipo* buscarEquipo(const Equipo equipos[], string nombreBuscado) {
    for (int i = 0; i < MAX_EQUIPOS; i++) {
        const Equipo* p = equipos + i;   // igual que &equipos[i]
        if (aMinusculas(p->nombre) == aMinusculas(nombreBuscado)) {
            return p;
        }
    }
    return nullptr;
}

// Pide el nombre y muestra la ficha del equipo (o que no existe)
void consultarEquipo(const Equipo equipos[], const Partido partidos[]) {
    string nombreBuscado = leerCadena("Nombre del equipo: ");
    const Equipo* equipoEncontrado = buscarEquipo(equipos, nombreBuscado);

    cout << "--- FICHA DE EQUIPO ---\n";

    if (equipoEncontrado == nullptr) {
        cout << "Equipo no encontrado: " << nombreBuscado << "\n";
        return;
    }

    cout << "Equipo: " << equipoEncontrado->nombre << "\n";
    cout << "Jugados: " << equipoEncontrado->jugados << "\n";
    cout << "Ganados: " << equipoEncontrado->ganados << "\n";
    cout << "Empatados: " << equipoEncontrado->empatados << "\n";
    cout << "Perdidos: " << equipoEncontrado->perdidos << "\n";
    cout << "Goles a favor: " << equipoEncontrado->golesFavor << "\n";
    cout << "Goles en contra: " << equipoEncontrado->golesContra << "\n";
    cout << "Puntos: " << equipoEncontrado->puntos << "\n\n";

    int fila = equipoEncontrado - equipos;   // posicion del equipo en el arreglo

    cout << left << setw(ANCHO_RIVAL) << "RIVAL"
         << setw(ANCHO_MARCADOR) << "MARCADOR"
         << "RESULTADO" << "\n";

    for (int i = 0; i < TOTAL_PARTIDOS; i++) {
        const Partido* p = partidos + i;   // igual que &partidos[i]
        int rival = 0;
        int golesEquipo = 0;
        int golesContrario = 0;

        if (p->local == fila) {
            rival = p->visitante;
            golesEquipo = p->golesLocal;
            golesContrario = p->golesVisitante;
        } else if (p->visitante == fila) {
            rival = p->local;
            golesEquipo = p->golesVisitante;
            golesContrario = p->golesLocal;
        } else {
            continue;   // este partido no es del equipo
        }

        Equipo equipoRival = *(equipos + rival);   // igual que equipos[rival]

        string resultado;
        if (golesEquipo > golesContrario) {
            resultado = "Ganado";
        } else if (golesEquipo < golesContrario) {
            resultado = "Perdido";
        } else {
            resultado = "Empatado";
        }

        string marcador = to_string(golesEquipo) + " - " + to_string(golesContrario);
        cout << left << setw(ANCHO_RIVAL) << equipoRival.nombre
             << setw(ANCHO_MARCADOR) << marcador
             << resultado << "\n";
    }
}