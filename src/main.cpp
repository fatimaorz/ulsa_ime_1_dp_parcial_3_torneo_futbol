// Proyecto Parcial 3: Sistema de Gestion de un Torneo de Futbol
//
// Compilar desde la carpeta del proyecto:
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo

#include <iomanip>
#include <iostream>

#include "escenario_prueba.h"
#include "registros.h"
#include "tabla.h"
#include "torneo.h"
#include "utilerias.h"
#include "torneo.h"
#include "tabla.h"    

const int OPC_REGISTRAR = 1;
const int OPC_MOSTRAR_EQUIPOS = 2;
const int OPC_SIMULAR = 3;
const int OPC_RESULTADOS = 4;
const int OPC_TABLA = 5;
const int OPC_CAMPEON = 6;
const int OPC_CONSULTAR = 7;
const int OPC_MATRIZ = 8;
const int OPC_SALIR = 9;

const int MODO_ALEATORIO = 1;
const int MODO_PRUEBA = 2;

void mostrarMenu() {
    std::cout << "\n1. Registrar equipo\n"
              << "2. Mostrar equipos\n"
              << "3. Simular torneo\n"
              << "4. Mostrar resultados\n"
              << "5. Mostrar tabla de posiciones\n"
              << "6. Mostrar campeon\n"
              << "7. Consultar equipo\n"
              << "8. Mostrar matriz de enfrentamientos\n"
              << "9. Salir\n";
}

void simularPartidos(Partido partidos[], int modo) {
    int indicePartido = 0;

    for (int local = 0; local < MAX_EQUIPOS; local++) {
        for (int visitante = local + 1; visitante < MAX_EQUIPOS; visitante++) {
            Partido& partido = partidos[indicePartido];
            partido.local = local;
            partido.visitante = visitante;

            if (modo == MODO_PRUEBA) {
                partido.golesLocal = GOLES_PRUEBA[indicePartido][0];
                partido.golesVisitante = GOLES_PRUEBA[indicePartido][1];
            } else {
                partido.golesLocal = numeroAleatorio();
                partido.golesVisitante = numeroAleatorio();
            }

            indicePartido++;
        }
    }
}

void mostrarResultados(const Equipo equipos[], const Partido partidos[]) {
    std::cout << "\n--- RESULTADOS ---\n";
    for (int i = 0; i < TOTAL_PARTIDOS; i++) {
        const Partido& partido = partidos[i];
        std::cout << equipos[partido.local].nombre << " "
                  << partido.golesLocal << " - "
                  << partido.golesVisitante << " "
                  << equipos[partido.visitante].nombre << '\n';
    }
}

void mostrarTabla(const Equipo equipos[]) {
    Equipo ordenados[MAX_EQUIPOS];
    for (int i = 0; i < MAX_EQUIPOS; i++) {
        ordenados[i] = equipos[i];
    }

    for (int i = 0; i < MAX_EQUIPOS - 1; i++) {
        for (int j = 0; j < MAX_EQUIPOS - i - 1; j++) {
            if (ordenados[j].puntos < ordenados[j + 1].puntos) {
                Equipo temporal = ordenados[j];
                ordenados[j] = ordenados[j + 1];
                ordenados[j + 1] = temporal;
            }
        }
    }

    std::cout << "\n--- TABLA DE POSICIONES ---\n"
              << std::left << std::setw(4) << "#"
              << std::setw(17) << "EQUIPO"
              << std::right << std::setw(4) << "PJ"
              << std::setw(4) << "PG"
              << std::setw(4) << "PE"
              << std::setw(4) << "PP"
              << std::setw(5) << "GF"
              << std::setw(5) << "GC"
              << std::setw(6) << "PTS" << '\n';

    for (int i = 0; i < MAX_EQUIPOS; i++) {
        const Equipo& equipo = ordenados[i];
        std::cout << std::left << std::setw(4) << i + 1
                  << std::setw(17) << equipo.nombre
                  << std::right << std::setw(4) << equipo.jugados
                  << std::setw(4) << equipo.ganados
                  << std::setw(4) << equipo.empatados
                  << std::setw(4) << equipo.perdidos
                  << std::setw(5) << equipo.golesFavor
                  << std::setw(5) << equipo.golesContra
                  << std::setw(6) << equipo.puntos << '\n';
    }
}

void mostrarCampeon(const Equipo equipos[]) {
    int maximoPuntos = equipos[0].puntos;
    for (int i = 1; i < MAX_EQUIPOS; i++) {
        if (equipos[i].puntos > maximoPuntos) {
            maximoPuntos = equipos[i].puntos;
        }
    }

    int empatados[MAX_EQUIPOS];
    int cantidadEmpatados = 0;
    for (int i = 0; i < MAX_EQUIPOS; i++) {
        if (equipos[i].puntos == maximoPuntos) {
            empatados[cantidadEmpatados] = i;
            cantidadEmpatados++;
        }
    }

    if (cantidadEmpatados == 1) {
        std::cout << "El campeon es " << equipos[empatados[0]].nombre
                  << " con " << maximoPuntos << " puntos.\n";
        return;
    }

    std::cout << "Hay empate por el primer lugar:\n";
    for (int i = 0; i < cantidadEmpatados; i++) {
        std::cout << i + 1 << ". " << equipos[empatados[i]].nombre << '\n';
    }

    int eleccion = leerEntero("Elige al campeon: ");
    while (eleccion < 1 || eleccion > cantidadEmpatados) {
        std::cout << "Opcion no valida.\n";
        eleccion = leerEntero("Elige al campeon: ");
    }

    std::cout << "El campeon es " << equipos[empatados[eleccion - 1]].nombre
              << " con " << maximoPuntos << " puntos.\n";
}

void consultarEquipo(const Equipo equipos[]) {
    const std::string nombreBuscado =
        aMinusculas(leerCadena("Nombre del equipo: "));

    for (int i = 0; i < MAX_EQUIPOS; i++) {
        if (aMinusculas(equipos[i].nombre) == nombreBuscado) {
            const Equipo& equipo = equipos[i];
            std::cout << "\n--- FICHA DE " << equipo.nombre << " ---\n"
                      << "PJ: " << equipo.jugados
                      << " | PG: " << equipo.ganados
                      << " | PE: " << equipo.empatados
                      << " | PP: " << equipo.perdidos << '\n'
                      << "GF: " << equipo.golesFavor
                      << " | GC: " << equipo.golesContra
                      << " | PTS: " << equipo.puntos << '\n';
            return;
        }
    }

    std::cout << "No se encontro el equipo.\n";
}

void mostrarMatriz(const Equipo equipos[], const Partido partidos[]) {
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

int main() {
    Equipo equipos[MAX_EQUIPOS];
    Partido partidos[TOTAL_PARTIDOS];
    int cantidad = 0;
    bool simulado = false;
    int opcion = 0;

    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ");

        if (opcion == OPC_REGISTRAR) {
            registrarEquipo(equipos, cantidad);
        } else if (opcion == OPC_MOSTRAR_EQUIPOS) {
            mostrarEquipos(equipos, cantidad);
        } else if (opcion == OPC_SIMULAR) {
            if (cantidad < MAX_EQUIPOS) {
                std::cout << "Faltan equipos: se necesitan " << MAX_EQUIPOS
                          << " para simular.\n";
            } else if (simulado) {
                std::cout << "El torneo ya fue simulado.\n";
            } else {
                int modo = leerEntero("Modo (1 = aleatorio, 2 = prueba): ");
                while (modo != MODO_ALEATORIO && modo != MODO_PRUEBA) {
                    std::cout << "Modo no valido.\n";
                    modo = leerEntero("Modo (1 = aleatorio, 2 = prueba): ");
                }

                simularPartidos(partidos, modo);
                calcularTabla(equipos, MAX_EQUIPOS, partidos, TOTAL_PARTIDOS);
                simulado = true;
                std::cout << "Torneo simulado correctamente.\n";
            }
        } else if (opcion >= OPC_RESULTADOS && opcion <= OPC_MATRIZ) {
            if (!simulado) {
                std::cout << "Primero debes simular el torneo.\n";
            } else if (opcion == OPC_RESULTADOS) {
                mostrarResultados(equipos, partidos);
            } else if (opcion == OPC_TABLA) {
                mostrarTabla(equipos);
            } else if (opcion == OPC_CAMPEON) {
                mostrarCampeon(equipos);
            } else if (opcion == OPC_CONSULTAR) {
                consultarEquipo(equipos);
            } else if (opcion == OPC_MATRIZ) {
                mostrarMatriz(equipos, partidos);
            }
        } else if (opcion == OPC_SALIR) {
            std::cout << "Hasta luego.\n";
        } else {
            std::cout << "Opcion no valida. Intenta de nuevo.\n";
        }
    } while (opcion != OPC_SALIR);

    return 0;
}
