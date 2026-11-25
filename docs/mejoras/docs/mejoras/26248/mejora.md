**Matrícula:** 26248 
**Título de la propuesta:** Mejora en desición en caso de empate

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

es una mejora, resuelve el proceso de que la persona tenga que decidir manualmente al ganador creo que estaría mejor que el programa pueda decidir automaticamente en caso de un empate tomando en cuenta diferentes variables del equipo durante el torneo como goles o cantidad de partidos ganados.
beneficia creo que a el organizador del torneo y a los equipos, al organizador para que sea rapido el resultado y a los equipos para que puedan calcular incluso en un empate si pudieran ganar con otras reglas impuestas por el torneo.
## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

No cambiaria registros, arreglos ni constantes solo agregaría unas funciones como para comparar los equipos o tener la diferencia de los goles para que se pueda escoger un ganador con esas dos reglas.
ordenarTabla: en vez de comparar solo los puntos, usa compararEquipos. La tabla mostrada también queda con el desempate aplicado.
contarEmpatados: ahora cuenta como empatado solo al equipo que sigue igual al líder en todos los criterios. Si da 1, el campeón sale solo.
mostrarCampeon: avisa cuando el campeón se decidió por desempate automático.
elegirCampeon: se conserva. Solo se usa si el empate persiste en todos los criterios.
Menú: no cambia. La opción 6 sigue siendo "Mostrar campeón", solo que ahora pregunta menos veces.

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
COMPARAR_EQUIPOS(a, b)                                        [NUEVO]
    // a y b son apuntadores a Equipo
    // devuelve positivo si a es mejor, negativo si b es mejor, 0 si empatan en todo
    SI puntos de a != puntos de b
        DEVOLVER puntos de a - puntos de b
    SI DIFERENCIA_GOLES(a) != DIFERENCIA_GOLES(b)
        DEVOLVER DIFERENCIA_GOLES(a) - DIFERENCIA_GOLES(b)
    SI goles a favor de a != goles a favor de b
        DEVOLVER goles a favor de a - goles a favor de b
    SI ganados de a != ganados de b
        DEVOLVER ganados de a - ganados de b
    DEVOLVER 0

DIFERENCIA_GOLES(equipo)                                      [NUEVO]
    DEVOLVER goles a favor del equipo - goles en contra del equipo

INTERCAMBIAR(a, b)
    guardar en temporal el equipo al que apunta a
    copiar en a el equipo al que apunta b
    copiar en b el equipo guardado en temporal

ORDENAR_TABLA(equipos, total)
    PARA i DESDE 0 HASTA total - 2
        actual = apuntador al primer equipo
        MIENTRAS actual esté antes de la posición (total - 1 - i)
            siguiente = apuntador al equipo que está después de actual
            SI COMPARAR_EQUIPOS(actual, siguiente) < 0           [CAMBIA]
                INTERCAMBIAR(actual, siguiente)
            FIN SI
            avanzar actual al siguiente equipo
        FIN MIENTRAS
    FIN PARA

MOSTRAR_TABLA(equipos, total)
    imprimir título y encabezados
    PARA i DESDE 0 HASTA total - 1
        imprimir i + 1, nombre y estadísticas del equipo i
    FIN PARA

CONTAR_EMPATADOS(equipos, total)
    cantidad = 0
    PARA i DESDE 0 HASTA total - 1
        SI COMPARAR_EQUIPOS(equipo i, equipo 0) == 0             [CAMBIA]
            cantidad = cantidad + 1
        FIN SI
    FIN PARA
    DEVOLVER cantidad

ELEGIR_CAMPEON(equipos, empatados)
    imprimir "Hay empate en el primer lugar"
    PARA i DESDE 0 HASTA empatados - 1
        imprimir i + 1 y el nombre del equipo i
    FIN PARA
    REPETIR
        pedir opcion al usuario
        SI opcion < 1 O opcion > empatados
            imprimir "Opcion no valida"
        FIN SI
    HASTA QUE opcion esté entre 1 y empatados
    DEVOLVER opcion - 1

MOSTRAR_CAMPEON(equipos, total)
    SI total <= 0
        imprimir "No hay equipos para determinar un campeon"
        TERMINAR
    FIN SI
    empatados = CONTAR_EMPATADOS(equipos, total)
    campeon = 0
    SI empatados > 1
        campeon = ELEGIR_CAMPEON(equipos, empatados)
    FIN SI
    SI empatados == 1 Y total > 1 Y puntos del equipo 0 == puntos del equipo 1   [NUEVO]
        imprimir "Empate en puntos resuelto por desempate automatico"
    FIN SI
    imprimir nombre y puntos del equipo en la posición campeon
```
