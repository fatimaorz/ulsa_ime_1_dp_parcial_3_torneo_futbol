# Proyecto Parcial 3: Sistema de Gestión de un Torneo de Fútbol

> **Importante:** este README es del equipo y debe tener aportaciones de todos los integrantes. La guía completa está en [`PROYECTO.md`](PROYECTO.md).

## 1. Integrantes

| Módulo | Matrícula | Nombre | Usuario de GitHub | Tema |
| --- | --- | --- | --- | --- |
| 1 | [26081] | [Fatima Marisol Orozco Castro] | [fatimaorz] | Registro de equipos |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Simulación de partidos |
| 3 | 26113 | Andrés Galindo Dávila | andresgalindod-rgb | Tabla de posiciones |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | Clasificación y campeón |
| 5 | 26100 | Regina Murillo Arellano | reginamurilloa | Consultas |
| 6 | [26167] | [Daniel Miranda Ferreira] | [Dan-Byte0] | Matriz de enfrentamientos |

> **Nota:** en los equipos de 5 integrantes, todos contribuyen al módulo 6. En esa fila escriban "Todo el equipo".

## 2. Opciones del menú

Escriban las opciones del menú en el orden en que aparecen en el programa.


--- TORNEO DE FUTBOL DE MERMELADA CODE ---
1. Registrar equipo
2. Mostrar equipos
3. Simular torneo
4. Mostrar resultados
5. Mostrar tabla de posiciones
6. Mostrar campeon
7. Consultar equipo
8. Mostrar matriz de enfrentamientos
9. Salir
Opcion:

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

[Matriz de enfrentamientos:

- La matriz usa las posiciones de los equipos en el arreglo para relacionar los resultados de cada partido.
- Cada celda muestra primero los goles del equipo de la fila y después los goles del equipo de la columna.
- La diagonal principal se representa con `---`, porque un equipo no juega contra sí mismo.
- Las abreviaturas se forman tomando los primeros caracteres del nombre del equipo y convirtiéndolos a mayúsculas.
- La matriz se construyo usando los resultados guardados en el arreglo de partidos.
- El mejor ataque corresponde al equipo o equipos con más goles a favor.
- La mejor defensa corresponde al equipo o equipos con menos goles en contra.
- Si hay empate en mejor ataque o mejor defensa, se muestran todos los equipos empatados.]

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
CONSTANTES
    OPC_REGISTRAR = 1 ... OPC_SALIR = 9
    MODO_ALEATORIO = 1, MODO_PRUEBA = 2

FUNCION mostrarMenu()
    1. Mostrar el titulo del torneo
    2. Mostrar las 9 opciones numeradas

FUNCION simularPartidos(partidos, modo)
    RECIBE: partidos (arreglo, se modifica), modo (entero, por valor)
    1. indicePartido = 0
    2. Para cada local de 0 hasta MAX_EQUIPOS - 1:
          3. Para cada visitante de local + 1 hasta MAX_EQUIPOS - 1:
                4. Guardar local y visitante en partidos[indicePartido]
                5. Si modo es MODO_PRUEBA:
                      tomar los goles de GOLES_PRUEBA[indicePartido]
                   Si no:
                      goles de cada lado = numeroAleatorio()
                6. Aumentar indicePartido en 1

FUNCION mostrarResultados(equipos, partidos)
    1. Mostrar el titulo
    2. Para cada partido de 0 hasta TOTAL_PARTIDOS - 1:
          3. Mostrar local, marcador y visitante

FUNCION mostrarTabla(equipos)
    1. Copiar equipos en el arreglo ordenados
    2. Ordenar ordenados de mayor a menor por puntos (burbuja)
    3. Mostrar titulo y encabezados
    4. Para cada posicion de 0 hasta MAX_EQUIPOS - 1:
          5. Mostrar posicion, nombre y estadisticas

FUNCION mostrarCampeon(equipos)
    1. Buscar el maximo de puntos
    2. Guardar en empatados los indices con ese maximo
    3. Si solo hay uno: mostrar campeon y puntos, terminar
    4. Mostrar los empatados numerados desde 1
    5. Pedir eleccion con leerEntero
    6. Mientras eleccion sea menor que 1 o mayor que cantidadEmpatados:
          mostrar rechazo y volver a pedir
    7. Mostrar el campeon elegido y sus puntos

PROGRAMA PRINCIPAL main
    1. Declarar equipos, partidos, cantidad = 0, simulado = falso
    2. Repetir:
          3. Mostrar menu y leer opcion con leerEntero
          4. Si opcion es REGISTRAR:
                registrarEquipo(equipos, cantidad)
          5. Si no, si opcion es MOSTRAR_EQUIPOS:
                mostrarEquipos(equipos, cantidad)
          6. Si no, si opcion es SIMULAR:
                a. Si cantidad < MAX_EQUIPOS: rechazar (faltan equipos)
                b. Si no, si simulado: rechazar (ya se simulo)
                c. Si no:
                      pedir modo hasta que sea MODO_ALEATORIO o MODO_PRUEBA
                      simularPartidos(partidos, modo)
                      calcularTabla(equipos, MAX_EQUIPOS, partidos, TOTAL_PARTIDOS)
                      simulado = verdadero
          7. Si no, si opcion esta entre RESULTADOS y MATRIZ:
                a. Si NO simulado: rechazar ("Primero debes simular")
                b. Si no, segun la opcion:
                      RESULTADOS: mostrarResultados
                      TABLA: mostrarTabla
                      CAMPEON: mostrarCampeon
                      CONSULTAR: consultarEquipo
                      MATRIZ: mostrarMatriz y mostrarMejores
          8. Si no, si opcion es SALIR: mostrar despedida
          9. Si no: mostrar "Opcion no valida" y volver al menu
       hasta que opcion sea OPC_SALIR
```

## 9. Documentación individual

Enlace a la documentación y a la propuesta de mejora de cada integrante.

| Módulo | Documentación | Propuesta de mejora |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [docs/docs/26113/modulo.md] | [docs/mejoras/docs/mejoras/26113/mejora.md] |
| 4 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 5 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 6 | [docs/docs/26167/modulo.md] | [docs/mejoras/26167/mejora.md] |

<!-- Si el equipo es de seis integrantes, agreguen una fila para el módulo 6. En equipos de cinco, agreguen una fila con el enlace a docs/modulo_6/modulo.md, sin propuesta de mejora. -->

## 10. Cambios a la base común

Si cambiaron una constante de `include/torneo.h`, expliquen qué cambiaron y por qué. Si no cambiaron nada, escriban "Sin cambios".

Sin cambios