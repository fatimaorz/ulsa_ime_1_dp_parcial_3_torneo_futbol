# Proyecto Parcial 3: Sistema de Gestión de un Torneo de Fútbol

> **Importante:** este README es del equipo y debe tener aportaciones de todos los integrantes. La guía completa está en [`PROYECTO.md`](PROYECTO.md).

## 1. Integrantes

| Módulo | Matrícula | Nombre | Usuario de GitHub | Tema |
| --- | --- | --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Registro de equipos |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Simulación de partidos |
| 3 | 26113 | Andrés Galindo Dávila | andresgalindod-rgb | Tabla de posiciones |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Clasificación y campeón |
| 5 | [Inserta aquí tu respuesta] | 26100 | Regina Murillo Arellano | Consultas |
| 6 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Matriz de enfrentamientos |

> **Nota:** en los equipos de 5 integrantes, todos contribuyen al módulo 6. En esa fila escriban "Todo el equipo".

## 2. Opciones del menú

Escriban las opciones del menú en el orden en que aparecen en el programa.

[Inserta aquí tu respuesta]

## 3. Cómo compilar y ejecutar

Desde la carpeta del proyecto:

```
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o torneo
```

Para ejecutar en macOS:

```
./torneo
```

Para ejecutar en Windows:

```
.\torneo.exe
```

## 4. Tipos de datos abstractos (TDA)

Describan cada TDA que diseñaron como registro (`struct`): qué datos guarda, qué operaciones tiene y por qué.

**TDA `Equipo`** (`include/torneo.h`)

- **Datos:** `nombre` y sus estadísticas del torneo: `jugados`, `ganados`, `empatados`, `perdidos`, `golesFavor`, `golesContra` y `puntos`. Las estadísticas inician en 0.
- **Operaciones:**
  - Registrar equipo (`registrarEquipo`, módulo 1).
  - Reiniciar estadísticas (`reiniciarEstadisticas`, módulo 3).
  - Registrar resultado (`registrarResultado`, módulo 3): suma un partido jugado, sus goles y sus puntos.
- **Por qué:** todos los datos de un equipo viajan juntos en un solo registro, sin arreglos paralelos. Los equipos se guardan en un arreglo de `Equipo` de tamaño `MAX_EQUIPOS`, en orden de registro.

**TDA `Partido`** (`include/torneo.h`)

- **Datos:** `local` y `visitante` (posición de cada equipo en el arreglo de equipos, de 0 a `MAX_EQUIPOS - 1`), `golesLocal` y `golesVisitante`.
- **Operaciones:**
  - Aplicar partido a la tabla (`aplicarPartido`, módulo 3): registra el resultado en los dos equipos, cada uno desde su lado del marcador.
- **Por qué:** guardar la posición del equipo, y no su nombre, permite llegar directo al equipo con `equipos[partido.local]` sin buscarlo. Los partidos se guardan en un arreglo de `Partido` de tamaño `TOTAL_PARTIDOS`.

## 5. Reglas del programa

Escriban las decisiones que el equipo tomó y que el cálculo a mano necesita. Por ejemplo: cómo se obtiene la abreviatura y qué pasa si dos se repiten.

[Inserta aquí tu respuesta]

## 6. Equipos del escenario

Los 6 equipos que registran en el escenario obligatorio, en orden de registro.

| # | Nombre | Abreviatura |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 6 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 7. Cálculo a mano

Ejecuten una corrida en modo aleatorio y copien aquí sus 15 resultados.

```
[Inserta aquí tu respuesta]
```

Antes de consultar los demás reportes de esa corrida, calculen a mano los resultados.

**Tabla de posiciones:**

| Equipo | PJ | PG | PE | PP | GF | GC | PTS |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

**Campeón o equipos empatados en el primer lugar:** [Inserta aquí tu respuesta]  
**Mejor ataque:** [Inserta aquí tu respuesta]  
**Mejor defensa:** [Inserta aquí tu respuesta]

**¿La salida del programa coincidió con el cálculo a mano? Si no, ¿qué corrigieron?**

[Inserta aquí tu respuesta]

## 8. Receta del menú

Receta en pseudocódigo del programa principal: el menú y cómo se conecta con cada módulo.

```
[Inserta aquí tu respuesta]
```

## 9. Documentación individual

Enlace a la documentación y a la propuesta de mejora de cada integrante.

| Módulo | Documentación | Propuesta de mejora |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [docs/docs/26113/modulo.md](docs/docs/26113/modulo.md) | [docs/mejoras/docs/mejoras/26113/mejora.md](docs/mejoras/docs/mejoras/26113/mejora.md) |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

<!-- Si el equipo es de seis integrantes, agreguen una fila para el módulo 6. En equipos de cinco, agreguen una fila con el enlace a docs/modulo_6/modulo.md, sin propuesta de mejora. -->

## 10. Cambios a la base común

Si cambiaron una constante de `include/torneo.h`, expliquen qué cambiaron y por qué. Si no cambiaron nada, escriban "Sin cambios".

[Inserta aquí tu respuesta]
