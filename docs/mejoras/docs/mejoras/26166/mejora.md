**Matrícula:** 26166  
**Título de la propuesta:** [Resumen de goles del torneo]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

[Es una mejora. Hoy el usuario tiene que leer los 15 resultados para saber cómo estuvo el torneo en general. Agrego un reporte que muestra el total de goles, el promedio por partido y el partido con más goles. Beneficia a quien usa el programa y quiere un panorama rápido sin revisar partido por partido.]

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

[ Dos funciones nuevas en Simulacion.h. Una calcula (total de goles, promedio y cuál fue el partido con más goles) y otra imprime. Las separé para que cada una haga una sola tarea, igual que en tabla y mostrar tabla.
 No cambian los registros ni los arreglos: todo sale de los goles que ya están guardados en el arreglo de Partido.
 La función que calcula devuelve sus resultados por referencia, porque son varios valores y una función solo puede devolver uno con return. El arreglo de partidos va como const, porque solo se lee.
 El menú de main.cpp cambia: se agrega la opción "Mostrar resumen de goles" y Salir se recorre al final.
 Caso de rechazo: si el torneo no se ha simulado, avisa "Primero simula el torneo." y regresa al menú, igual que los demás reportes.
 No se necesitan constantes nuevas: se reutiliza TOTAL_PARTIDOS y los anchos de columna que ya existen.]

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
[programa principal:
    repetir
        mostrar menú  [CAMBIA]: ahora tiene una opción más, y Salir es la última
        leer opción con leerEntero
        si es registrar, mostrar equipos, simular, resultados, tabla, campeón, consulta o matriz:
            llamar a la función de su módulo
        [NUEVO] si es mostrar resumen de goles:
            mostrarResumenGoles(equipos, partidos, totalPartidos)
        si es salir: terminar
        si no existe: avisar y volver a mostrar el menú
    hasta elegir salir

[NUEVO] calcularResumenGoles(partidos, totalPartidos, totalGoles, indiceMayor):
    totalGoles = 0
    indiceMayor = 0
    para k de 0 a totalPartidos - 1
        golesPartido = golesLocal + golesVisitante del partido k
        totalGoles = totalGoles + golesPartido
        si golesPartido es mayor que los goles del partido indiceMayor:
            indiceMayor = k

[NUEVO] mostrarResumenGoles(equipos, partidos, totalPartidos):
    si totalPartidos es 0: avisar "Primero simula el torneo." y regresar
    calcularResumenGoles(partidos, totalPartidos, totalGoles, indiceMayor)
    promedio = totalGoles / totalPartidos
    imprimir título
    imprimir total de goles y promedio
    imprimir local, marcador y visitante del partido indiceMayor]
```
