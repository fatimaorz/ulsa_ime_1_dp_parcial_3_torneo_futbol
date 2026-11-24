# Documentación del módulo

## 1. Autor

**Nombre:** Andrés Galindo Dávila  
**Matrícula:** 26113  
**Módulo:** 3. Tabla de posiciones  
**Archivo de código:** `include/tabla.h`

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

Mi módulo calcula las estadísticas de cada equipo del torneo a partir de los resultados de los 15 partidos: partidos jugados (PJ), ganados (PG), empatados (PE), perdidos (PP), goles a favor (GF), goles en contra (GC) y puntos (PTS). No imprime nada; solo deja esos datos guardados dentro de cada `Equipo`.

Al usuario le sirve porque, sin este cálculo, no habría tabla de posiciones, ni campeón, ni ficha de equipo: el módulo 4 ordena y muestra la tabla con estos datos, y el módulo 5 los usa en la ficha. El programa lo ejecuta una sola vez, justo después de simular el torneo.

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

**Recibe (por parámetros):**

- El arreglo de equipos (`Equipo equipos[]`), que se modifica.
- Cuántos equipos hay (`int totalEquipos`).
- El arreglo de partidos ya simulados (`const Partido partidos[]`), que solo se lee.
- Cuántos partidos hay (`int totalPartidos`).

**Del teclado:** nada. El módulo no interactúa con el usuario.

**Produce:** no imprime ni devuelve valores (todas sus funciones son `void`). Su resultado son los campos de estadísticas (`jugados`, `ganados`, `empatados`, `perdidos`, `golesFavor`, `golesContra` y `puntos`) actualizados dentro de cada equipo del arreglo original, gracias al paso por referencia.

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

| Función | Tarea (una sola) |
| --- | --- |
| `reiniciarEstadisticas(Equipo& equipo)` | Pone en cero las estadísticas de un equipo, sin tocar su nombre. |
| `registrarResultado(Equipo& equipo, int golesFavor, int golesContra)` | Suma a un equipo un partido jugado: sus goles y el resultado (ganado, empatado o perdido) con sus puntos. Es la operación "registrar resultado" del TDA `Equipo`. |
| `aplicarPartido(const Partido& partido, Equipo& local, Equipo& visitante)` | Aplica un partido a los dos equipos que lo jugaron, cada uno con el marcador visto desde su lado. |
| `calcularTabla(Equipo equipos[], int totalEquipos, const Partido partidos[], int totalPartidos)` | Calcula la tabla completa: reinicia a todos los equipos y recorre los partidos. Es la función que llama `main`. |

Las funciones se apoyan entre sí: `calcularTabla` usa `reiniciarEstadisticas` y `aplicarPartido`, y `aplicarPartido` usa `registrarResultado` dos veces. Así ninguna lógica se escribe dos veces.

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

- **Registro `Equipo` (TDA del bloque 0):** agregué las estadísticas dentro del mismo registro, junto al nombre. Así todos los datos de un equipo viajan juntos y no se necesitan arreglos paralelos, que el proyecto prohíbe.
- **Registro `Partido` (TDA del bloque 0):** guarda la posición del equipo local y del visitante en el arreglo de equipos, y los goles de cada uno. Elegí guardar la posición (un índice) y no el nombre porque así llego directo al equipo con `equipos[partido.local]`, sin tener que buscarlo por nombre.
- **Arreglo de `Equipo` y arreglo de `Partido`:** son las estructuras obligatorias del bloque 0. Mi módulo recorre el de partidos y modifica el de equipos.

Cómo paso los datos:

- `Equipo&` **por referencia** en `reiniciarEstadisticas`, `registrarResultado` y `aplicarPartido`, porque la función tiene que modificar el equipo original y no una copia.
- `const Partido&` **por referencia constante** en `aplicarPartido`, porque el partido solo se lee: la referencia evita copiarlo y `const` evita modificarlo por error.
- Los goles (`int`) **por valor**, porque son datos pequeños que solo se leen.
- Los arreglos se pasan **como arreglo**: C++ manda la dirección del primer elemento, así que `calcularTabla` modifica los equipos originales. El arreglo de partidos va como `const` porque solo se lee.

**¿Dónde demuestras los temas asignados a tu módulo?**

- **Funciones:** el módulo tiene cuatro funciones, cada una con una sola tarea, con parámetros y con comentario de qué recibe y qué devuelve. Se reutilizan entre ellas (por ejemplo, `registrarResultado` se usa para el local y para el visitante).
- **Paso por referencia:** en `reiniciarEstadisticas(Equipo& equipo)`, `registrarResultado(Equipo& equipo, ...)` y `aplicarPartido(..., Equipo& local, Equipo& visitante)`. Sin el `&`, la función cambiaría una copia y la tabla se quedaría en ceros. También uso referencia constante en `const Partido& partido`.

**¿Qué ciclos usaste y por qué esos?**

Dos ciclos `for` en `calcularTabla`: el primero recorre los equipos para reiniciarlos, y el segundo recorre los partidos para aplicarlos. Usé `for` porque sé de antemano cuántas vueltas da cada uno (`totalEquipos` y `totalPartidos`).

**¿Qué constantes usaste y por qué son constantes?**

- `PUNTOS_VICTORIA`, `PUNTOS_EMPATE` y `PUNTOS_DERROTA` de `torneo.h`, para sumar los puntos. Son constantes porque la regla del torneo no cambia durante el programa, y si algún día cambia, se modifica en un solo lugar.
- `MAX_EQUIPOS` y `TOTAL_PARTIDOS` de `torneo.h`: `main` los pasa a `calcularTabla`, en lugar de escribir 6 y 15.

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

De `torneo.h` reutilizo los registros `Equipo` y `Partido` y las constantes de puntos y de tamaño. No uso funciones de `utilerias.h` porque mi módulo no lee nada del teclado. Mi módulo depende del módulo 2, que llena el arreglo de partidos, y le sirve a los módulos 4 y 5, que usan las estadísticas.

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

No aplica.

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
calcularTabla(equipos, totalEquipos, partidos, totalPartidos)
    1. Para i desde 0 hasta totalEquipos - 1:
           reiniciarEstadisticas(equipos[i])
    2. Para i desde 0 hasta totalPartidos - 1:
           partido <- partidos[i]
           aplicarPartido(partido, equipos[partido.local], equipos[partido.visitante])

reiniciarEstadisticas(equipo)
    1. jugados, ganados, empatados, perdidos <- 0
    2. golesFavor, golesContra, puntos <- 0

aplicarPartido(partido, local, visitante)
    1. registrarResultado(local, partido.golesLocal, partido.golesVisitante)
    2. registrarResultado(visitante, partido.golesVisitante, partido.golesLocal)

registrarResultado(equipo, golesFavor, golesContra)
    1. equipo.jugados <- equipo.jugados + 1
    2. equipo.golesFavor <- equipo.golesFavor + golesFavor
    3. equipo.golesContra <- equipo.golesContra + golesContra
    4. Si golesFavor > golesContra:
           equipo.ganados <- equipo.ganados + 1
           equipo.puntos <- equipo.puntos + PUNTOS_VICTORIA
       Si no, si golesFavor = golesContra:
           equipo.empatados <- equipo.empatados + 1
           equipo.puntos <- equipo.puntos + PUNTOS_EMPATE
       Si no:
           equipo.perdidos <- equipo.perdidos + 1
           equipo.puntos <- equipo.puntos + PUNTOS_DERROTA
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

Sí. Con los marcadores del modo de prueba seguí la receta para Leones (equipo 4):

| Rival | Marcador (Leones primero) | Resultado |
| --- | --- | --- |
| Aguilas | 0 - 4 | Perdido |
| Halcones | 5 - 0 | Ganado |
| Jaguares | 1 - 0 | Ganado |
| Pumas | 5 - 3 | Ganado |
| Tigres | 3 - 3 | Empatado |

PJ = 5, PG = 3, PE = 1, PP = 1, GF = 0 + 5 + 1 + 5 + 3 = 14, GC = 4 + 0 + 0 + 3 + 3 = 10, PTS = 3 x 3 + 1 x 1 = 10. Coincide con la tabla de ejemplo de `PROYECTO.md`.

Al probarla corregí dos cosas:

1. Cuando Leones es visitante (contra Aguilas y Halcones), sus goles están en la columna del visitante. Por eso `aplicarPartido` llama a `registrarResultado` con los goles invertidos para el visitante.
2. Si la tabla se calculara dos veces, las estadísticas se sumarían dos veces. Por eso agregué el paso 1 de `calcularTabla`, que pone todo en cero antes de recorrer los partidos.

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Escenario de prueba, equipo con empate en el primer lugar | Marcadores de `escenario_prueba.h`, equipo 1 (Aguilas) | PJ 5, PG 3, PE 1, PP 1, GF 13, GC 8, PTS 10 | PJ 5, PG 3, PE 1, PP 1, GF 13, GC 8, PTS 10 |
| 2 | Escenario de prueba, equipo que juega de visitante | Marcadores de `escenario_prueba.h`, equipo 4 (Leones) | PJ 5, PG 3, PE 1, PP 1, GF 14, GC 10, PTS 10 | PJ 5, PG 3, PE 1, PP 1, GF 14, GC 10, PTS 10 |
| 3 | Escenario de prueba, último lugar | Marcadores de `escenario_prueba.h`, equipo 5 (Pumas) | PJ 5, PG 1, PE 0, PP 4, GF 7, GC 15, PTS 3 | PJ 5, PG 1, PE 0, PP 4, GF 7, GC 15, PTS 3 |
| 4 | Calcular la tabla dos veces seguidas (no debe duplicar) | Escenario de prueba, `calcularTabla` dos veces | Aguilas sigue con PJ 5 y PTS 10 | Aguilas con PJ 5 y PTS 10 |
| 5 | Caso límite: todos los partidos empatados | Los 15 partidos 0 - 0 | Cada equipo: PJ 5, PE 5, GF 0, GC 0, PTS 5 | Cada equipo: PJ 5, PE 5, GF 0, GC 0, PTS 5 |
| 6 | Caso límite: un equipo gana todo y otro pierde todo | Los 15 partidos 5 - 0 a favor del local | Equipo 1: PG 5, GF 25, PTS 15. Equipo 6: PP 5, GC 25, PTS 0 | Equipo 1: PG 5, GF 25, PTS 15. Equipo 6: PP 5, GC 25, PTS 0 |
| 7 | Comprobación general: los goles cuadran | Caso de la prueba 6 | Suma de GF de todos = suma de GC de todos | 75 = 75 |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | El registro `Equipo` del equipo solo tenía el nombre, y mi módulo no tenía dónde guardar las estadísticas. | Agregué en `torneo.h` los campos `jugados`, `ganados`, `empatados`, `perdidos`, `golesFavor`, `golesContra` y `puntos`, iniciados en 0. |
| 2 | No existía el registro `Partido`, y mi módulo necesita leer los marcadores. | Lo creé en `torneo.h` con la posición del local, la del visitante y los goles de cada uno. Guardé la posición y no el nombre para llegar directo al equipo en el arreglo. |
| 3 | Duda: ¿por qué hace falta el `&` si la función ya recibe el equipo? | Sin `&`, C++ manda una copia: la función suma los puntos a la copia y el equipo original se queda en ceros. Con `&` se trabaja sobre el original. |
| 4 | Al calcular la tabla dos veces, las estadísticas se duplicaban. | `calcularTabla` primero reinicia a todos los equipos con `reiniciarEstadisticas`. |

## 8. Reflexión

**¿Qué aprendiste?**

Aprendí a usar el paso por referencia para que una función modifique un registro sin regresar nada, y a usar `const` con referencia cuando solo necesito leer. También aprendí que dividir el problema en funciones pequeñas, cada una con una sola tarea, hace que el código sea más fácil de probar y de reutilizar: `registrarResultado` sirve igual para el local y para el visitante.

**¿Qué cambiarías de tu proceso?**

Pondría de acuerdo antes al equipo sobre los registros `Equipo` y `Partido`, porque todos los módulos dependen de ellos. También haría mis commits más seguido, en lugar de dejar el trabajo para los últimos días.
