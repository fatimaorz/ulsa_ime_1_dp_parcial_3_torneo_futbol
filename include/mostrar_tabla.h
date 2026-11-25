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



