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
#include "tabla.h"   
#include "consultas.h" 

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
 
    return 0;
}
