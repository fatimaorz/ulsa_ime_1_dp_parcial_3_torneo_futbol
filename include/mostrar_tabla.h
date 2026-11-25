#pragma once
#include <iostream> 
#include "torneo.h"
#include "tabla.h"
#include "utilerias.h"
//Agregar librerías necesarias para el trabajo


void intercambiar (Equipo*a, Equipo*b){
std::swap(*a, *b);
}

void ordenarTabla(Equipo equipos[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (Equipo* actual = equipos; actual < equipos + total - 1 - i; actual++) {
            Equipo* siguiente = actual + 1;

            if (actual->puntos < siguiente->puntos) {
                intercambiar(actual, siguiente);
            }
        }
    }
}

int contarEmpatados(const Equipo equipos[], int total) {
    int cantidad = 0; 
    for (int i = 0; i < total; i++) {
        if (equipos[i].puntos == equipos[0].puntos) {
            cantidad++;
        }
    }
    return cantidad;
}

int elegirCampeon(const Equipo equipos[], int empatados) {
    std::cout << "Hay empate en el primer lugar:\n";
    for (int i = 0; i < empatados; i++) {
        std::cout << (i + 1) << ". " << equipos[i].nombre << "\n";
    }

    int opcion;
do {
    opcion = leerEntero("Elige al campeon: ");
    if (opcion < 1 || opcion > empatados) {
        std::cout << "Opcion no valida. Elige un numero entre 1 y "
                  << empatados << ".\n";
    }
} while (opcion < 1 || opcion > empatados);
}

void mostrarCampeon(const Equipo equipos[], int total) {
    int empatados = contarEmpatados(equipos, total);
    int campeon = 0;

    if (empatados > 1) {
        campeon = elegirCampeon(equipos, empatados);
    }

    std::cout << "El campeon es: " << equipos[campeon].nombre
              << " con " << equipos[campeon].puntos << " puntos\n";
}

