**Matrícula:** 26167

**Título de la propuesta:** Identificación de victorias, empates y derrotas en la matriz de enfrentamientos

## 1. Impacto

Es una mejora que solamente agrega una característica a la matriz de enfrentamientos del torneo.

Actualmente, el programa enseña los marcadores de los partidos, pero el usuario necesita comparar los goles de cada equipo para saber si ganó, empató o perdió.

Mi propuesta es el  agregar una letra junto a cada marcador para identificar el resultado del equipo que aparece en la fila más facilmente:

G: Ganó.
E: Empató.
P: Perdió.

Por ejemplo, si un equipo tiene un marcador de 3-1 contra otro, aparecería `3-1 (G)`. Si el resultado es 2-2, aparecería `2-2 (E)`.

Esta mejora beneficiaría a los usuarios porque facilitaría la lectura de la matriz, permitiría identificar más rapido los resultados de cada enfrentamiento y haría que el reporte fuera más claro y práctico.

## 2. Qué implica en el diseño

**Registros:**

No sería necesario modificar las estructuras `Equipo` y `Partido`, porque ya contienen los datos necesarios para conocer los goles de cada enfrentamiento.

**Arreglos y matrices:**

Se reutilizaría la matriz bidimensional, que almacena los goles de los equipos, no sería necesario agregar otra matriz ni modificar los arreglos puestos.

**Constantes:**

Se podrían agregar constantes para representar los resultados:

- `RESULTADO_GANADO`
- `RESULTADO_EMPATE`
- `RESULTADO_PERDIDO`

Esto permitiría identificar los resultados con valores definidos y facilitaría su mantenimiento.

**Funciones:**

Se modificaría la función `mostrarMatriz()` para que, además de mostrar los marcadores, compare los goles de ambos equipos y determine si el equipo de la fila ganó, empató o perdió.

La función `construirMatriz()` conservaría su mismo funcionamiento, ya que seguiría encargándose de almacenar los goles de los enfrentamientos.

**Menú:**

No sería necesario modificar el menú, porque la mejora se integraría directamente en la opción que ya muestra la matriz.

**Justificación:**

Estos cambios permitirían mejorar la presentación de los resultados sin modificar la estructura principal del programa, además, se aprovecharía el trabajo existente y se mantendría la organización por las funciones.

## 3. Receta

```text
INICIO

FUNCIÓN mostrarMatriz(equipos, partidos)

    Crear e inicializar la matriz de enfrentamientos.

    Llamar a construirMatriz() para guardar los marcadores.

    Mostrar los encabezados de las columnas.

    PARA cada equipo de las filas HACER

        Mostrar el nombre del equipo.

        PARA cada equipo de las columnas HACER

            SI el equipo de la fila y el de la columna
            son el mismo ENTONCES

                Mostrar "---".

            SI NO

                Obtener los goles del equipo de la fila.

                Obtener los goles del equipo de la columna.

                [CAMBIA] Formar el marcador con los goles
                de ambos equipos.

                [NUEVO] Comparar los goles de los dos equipos:

                    SI los goles del equipo de la fila
                    son mayores ENTONCES

                        [NUEVO] Asignar la letra "G".

                    SI los goles son iguales ENTONCES

                        [NUEVO] Asignar la letra "E".

                    SI los goles del equipo de la fila
                    son menores ENTONCES

                        [NUEVO] Asignar la letra "P".

                [NUEVO] Agregar la letra correspondiente
                al marcador.

                [CAMBIA] Mostrar el marcador junto
                con la letra del resultado.

            FIN SI

        FIN PARA

        Cambiar a la siguiente línea.

    FIN PARA

FIN FUNCIÓN

FIN
```