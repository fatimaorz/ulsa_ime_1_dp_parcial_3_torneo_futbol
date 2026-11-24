# Propuesta de mejora

Propuesta de mejora elaborada por: Andrés Galindo Dávila

**Matrícula:** 26113  
**Título de la propuesta:** Criterios de desempate en la tabla de posiciones (diferencia de goles y goles a favor)

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

Es una mejora. Hoy, cuando dos equipos tienen los mismos puntos, pueden quedar en cualquier orden en la tabla, y si empatan en el primer lugar el usuario tiene que elegir al campeón a mano. En el escenario de prueba pasa justo eso: Aguilas y Leones terminan con 10 puntos.

La propuesta agrega los criterios de desempate que usan las ligas reales:

1. Más puntos.
2. Si empatan en puntos: mayor diferencia de goles (GF - GC).
3. Si siguen empatados: más goles a favor.

Así la tabla queda en un orden justo y siempre igual para los mismos resultados, y el usuario solo elige al campeón cuando dos equipos empatan en los tres criterios. En el escenario de prueba, Aguilas (13 - 8 = +5) quedaría arriba de Leones (14 - 10 = +4) sin preguntarle a nadie.

Beneficia a quien usa el programa, porque obtiene una clasificación confiable, y al equipo, porque el cálculo a mano del README tiene una regla clara para ordenar.

## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

- **Registros:** no cambian. La diferencia de goles se calcula con `golesFavor` y `golesContra`, que ya existen en `Equipo`. No conviene guardarla como un campo más, porque se podría quedar desactualizada si alguien cambia los goles y olvida cambiarla.
- **Módulo 3 (`tabla.h`), función nueva `int diferenciaGoles(const Equipo& equipo)`:** devuelve `golesFavor - golesContra`. Recibe el equipo por referencia constante porque solo lo lee. Va en mi módulo porque es una estadística del equipo y la pueden reutilizar los módulos 4 y 5.
- **Módulo 4, función nueva `bool vaAntes(const Equipo* a, const Equipo* b)`:** decide si el equipo `a` debe ir antes que `b` aplicando los tres criterios en orden. Recibe apuntadores, igual que la función de intercambio que ya pide el proyecto.
- **Módulo 4, ordenamiento:** cambia la comparación. En lugar de comparar solo puntos, llama a `vaAntes`. El intercambio de registros con apuntadores se queda igual.
- **Módulo 4, campeón:** cambia la detección de empate. Solo hay empate en el primer lugar si los equipos tienen los mismos puntos, la misma diferencia de goles y los mismos goles a favor.
- **Constantes y menú:** no cambian. El formato de los reportes tampoco cambia, porque es obligatorio; solo cambia el orden de las filas cuando hay empate en puntos.
- **README:** en "Reglas del programa" se escriben los criterios de desempate, porque el cálculo a mano los necesita.

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
Al simular el torneo:
    1. Generar los 15 partidos (modulo 2)
    2. calcularTabla(equipos, MAX_EQUIPOS, partidos, TOTAL_PARTIDOS) (modulo 3)

diferenciaGoles(equipo)                                   [NUEVO]
    1. Devolver equipo.golesFavor - equipo.golesContra    [NUEVO]

vaAntes(a, b)                                             [NUEVO]
    1. Si a->puntos != b->puntos:                         [NUEVO]
           devolver a->puntos > b->puntos
    2. Si diferenciaGoles(*a) != diferenciaGoles(*b):     [NUEVO]
           devolver diferenciaGoles(*a) > diferenciaGoles(*b)
    3. Devolver a->golesFavor > b->golesFavor             [NUEVO]

Mostrar tabla de posiciones (modulo 4):
    1. Copiar los equipos a un arreglo tabla, para conservar el orden de registro
    2. Para cada vuelta del ordenamiento:
           Para cada par de equipos vecinos tabla[j] y tabla[j + 1]:
               Si vaAntes(&tabla[j + 1], &tabla[j]):     [CAMBIA] (antes solo comparaba puntos)
                   intercambiar(&tabla[j], &tabla[j + 1])
    3. Imprimir la tabla con el formato obligatorio

Mostrar campeon (modulo 4):
    1. Ordenar la tabla como arriba
    2. Contar empatados: equipos con los mismos puntos,    [CAMBIA]
       la misma diferencia de goles y los mismos goles
       a favor que el primer lugar
    3. Si hay un solo equipo: mostrarlo como campeon
    4. Si hay varios: mostrarlos y pedir al usuario que elija;
       si elige una opcion que no existe, volver a preguntar
```
