**Matrícula:** 26100 
**Título de la propuesta:** Agregar porcentajes de rendimiento del equipo 

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

Es una mejora, ya que agrega información estadística 
Mi modulo muestra los partidos ganados, perdidos y empates, con esta mejora mostraria el rendimiento de cada equipo y de esta manera puedes ver como va evolucionando tu equipo 

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

La parte de consultarEquipo para calcular los porcentajes utilizando los datos del equipo consultado
Lo demás no es necesario modificar nada ya que la información esta correcta para que funcione asi 

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
FUNCION consultarEquipo(equipos, partidos)

    nombreBuscado = leerCadena("Nombre del equipo: ")
    equipoEncontrado = buscarEquipo(equipos, nombreBuscado)

    MOSTRAR "--- FICHA DE EQUIPO ---"

    SI equipoEncontrado es nullptr
        MOSTRAR "Equipo no encontrado: " + nombreBuscado
        TERMINAR

    MOSTRAR nombre, jugados, ganados, empatados, perdidos,
            goles a favor, goles en contra, puntos

    [NUEVO] SI jugados > 0
        [NUEVO] porcentajeGanados = (ganados / jugados) * 100
        [NUEVO] porcentajeEmpatados = (empatados / jugados) * 100
        [NUEVO] porcentajePerdidos = (perdidos / jugados) * 100

        [NUEVO] MOSTRAR porcentaje de victorias
        [NUEVO] MOSTRAR porcentaje de empates
        [NUEVO] MOSTRAR porcentaje de derrotas

    [NUEVO] SI NO
        [NUEVO] MOSTRAR "El equipo todavía no tiene partidos jugados"

    fila = equipoEncontrado - equipos

    MOSTRAR encabezado: RIVAL, MARCADOR, RESULTADO

    PARA i desde 0 hasta TOTAL_PARTIDOS - 1
        p = direccion del partido i

        SI el local de p es fila
            rival = visitante
            golesEquipo = golesLocal
            golesContrario = golesVisitante

        SI NO, SI el visitante de p es fila
            rival = local
            golesEquipo = golesVisitante
            golesContrario = golesLocal

        SI NO
            saltar este partido

        equipoRival = *(equipos + rival)

        SI golesEquipo > golesContrario
            resultado = "Ganado"
        SI NO, SI golesEquipo < golesContrario
            resultado = "Perdido"
        SI NO
            resultado = "Empatado"

        MOSTRAR equipoRival.nombre, marcador, resultado
```