// Proyecto Parcial 3: Sistema de Gestion de un Torneo de Futbol
// Programa principal (bloque de integracion, de todo el equipo).
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo
// Ejecutar en macOS:
//   ./torneo
// Ejecutar en Windows:
//   .\torneo.exe
//
// Lean PROYECTO.md antes de escribir codigo.

#include <iostream>
#include "utilerias.h"
#include "torneo.h"
#include "registros.h"
#include "tabla.h"

// ---------- Constantes del menu ----------
const int OPC_REGISTRAR = 1;
const int OPC_MOSTRAR_EQUIPOS = 2;
const int OPC_SIMULAR = 3;
const int OPC_RESULTADOS = 4;
const int OPC_TABLA = 5;
const int OPC_CAMPEON = 6;
const int OPC_CONSULTAR = 7;
const int OPC_MATRIZ = 8;
const int OPC_SALIR = 9;

// Modos de simulacion
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

                // TODO modulo 2: generar los partidos segun el modo.
                //   Ejemplo de forma: simularPartidos(equipos, partidos, modo);
                //   (usen la firma real de su companero)

                // Modulo 3: se calcula la tabla una vez, justo despues
                // de generar los partidos, en AMBOS modos.
                calcularTabla(equipos, MAX_EQUIPOS, partidos, TOTAL_PARTIDOS);

                simulado = true;
            }

        } else if (opcion >= OPC_RESULTADOS && opcion <= OPC_MATRIZ) {
            if (!simulado) {
                std::cout << "Primero debes simular el torneo.\n";
            } else if (opcion == OPC_RESULTADOS) {
                // TODO modulo 2: mostrar resultados de los partidos
            } else if (opcion == OPC_TABLA) {
                // TODO modulo 4: ordenar y mostrar la tabla
            } else if (opcion == OPC_CAMPEON) {
                // TODO modulo 4: detectar empate, elegir y mostrar campeon
            } else if (opcion == OPC_CONSULTAR) {
                // TODO modulo 5: pedir nombre, buscar (puntero) y mostrar ficha
            } else if (opcion == OPC_MATRIZ) {
                // TODO modulo 6: mostrar matriz, mejor ataque y mejor defensa
            }

        } else if (opcion == OPC_SALIR) {
            std::cout << "Hasta luego.\n";

        } else {
            std::cout << "Opcion no valida. Intenta de nuevo.\n";
        }
    } while (opcion != OPC_SALIR);

    return 0;
}