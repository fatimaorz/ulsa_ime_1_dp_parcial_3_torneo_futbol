**Matrícula:** 26081  
**Título de la propuesta:** [Desempate en la tabla por diferencia de goles y goles a favor]

## 1. Impacto

¿Es una mejora o una corrección? ¿Qué problema resuelve o qué agrega, y a quién beneficia?

Es una mejora. Hoy los equipos con los mismos puntos quedan en cualquier orden, así que la tabla puede poner arriba a un equipo que jugó peor que otro con los mismos puntos. Con la propuesta, los empatados en puntos se ordenan por diferencia de goles (GF - GC) y, si sigue el empate, por goles a favor. Si aún persiste, se conserva el orden que tenían.


## 2. Qué implica en el diseño

¿Qué partes de la solución cambian (registros, arreglos, constantes, funciones, menú)? Justifica cada cambio.

**Registro `Equipo`:** no cambia. La diferencia de goles se calcula con `golesFavor - golesContra` cuando se necesita, porque guardarla duplicaría un dato y podría quedar desactualizada. (Ajusta los nombres de los campos a los reales de `torneo.h`.)
- **Constantes:** no se necesitan nuevas.
- **Funciones nuevas en el archivo del módulo 4:**
  - `diferenciaGoles(const Equipo* equipo)`: devuelve GF - GC. Una sola tarea.
  - `debeIrAntes(const Equipo* a, const Equipo* b)`: devuelve `true` si `a` debe quedar arriba de `b`. Compara puntos; si empatan, diferencia de goles; si empatan, goles a favor. Recibe apuntadores porque el ordenamiento ya trabaja con apuntadores y así no se copian registros completos.
- **Función que cambia:** la de ordenamiento. Hoy compara solo puntos; ahora usa `debeIrAntes`. El intercambio con dos apuntadores a `Equipo` no cambia.
- **Se sigue ordenando una copia** del arreglo, para conservar el orden de registro que necesitan la lista, la ficha y la matriz.
- **Campeón:** no cambia. El empate en el primer lugar se detecta solo por puntos. Justificación: la guía define así al campeón y el escenario obligatorio exige elegir entre empatados. El desempate solo afecta el orden en que se muestra la tabla.
- **Menú y formato de reportes:** no cambian.

## 3. Receta

Receta en pseudocódigo de la solución con tu propuesta. Marca cada paso nuevo con `[NUEVO]` y cada paso que cambia con `[CAMBIA]`. Los pasos sin marca son los que ya existen.

```
FUNCION diferenciaGoles(equipo)                                    [NUEVO]
    RECIBE: equipo (apuntador a Equipo, solo lectura)
    DEVUELVE: entero
    1. Devolver goles a favor de equipo - goles en contra de equipo

FUNCION debeIrAntes(a, b)                                          [NUEVO]
    RECIBE: a y b (apuntadores a Equipo, solo lectura)
    DEVUELVE: verdadero o falso
    1. Si puntos de a es distinto de puntos de b:
          devolver (puntos de a > puntos de b)
    2. Si diferenciaGoles(a) es distinto de diferenciaGoles(b):
          devolver (diferenciaGoles(a) > diferenciaGoles(b))
    3. Devolver (goles a favor de a > goles a favor de b)

FUNCION ordenarTabla(copia, cantidad)
    RECIBE: copia (arreglo de Equipo, se modifica), cantidad (entero)
    DEVUELVE: nada
    1. Para cada posicion i de 0 hasta cantidad - 2:
          2. mejor = i
          3. Para cada posicion j de i + 1 hasta cantidad - 1:
                4. Si NO debeIrAntes(&copia[mejor], &copia[j])        [CAMBIA]
                   y debeIrAntes(&copia[j], &copia[mejor]):
                      mejor = j
          5. Si mejor es distinto de i:
                intercambiar(&copia[i], &copia[mejor])
```
