# Documentación individual del módulo 6

## 1. Autor

**Nombre:** Daniel Miranda Ferreira  
**Matrícula:** 26167  
**Módulo:** 6  
**Archivo de código:** matriz.h

## 2. Propósito

El módulo 6 tiene como propósito construir y mostrar una matriz de enfrentamientos entre los seis equipos del torneo, en ella se pueden consultar los marcadores de los partidos jugados entre cada equipo.

También permite identificar al equipo con el mejor ataque, que es el que anotó más goles, y al equipo con la mejor defensa, que es el que recibió menos goles, si existen empates, muestra todos los equipos que estén esa posición.

## 3. Entradas y salidas

**Entradas:**

- El arreglo de estructuras `Equipo`, que contiene los nombres y estadísticas de los equipos.
- El arreglo de estructuras `Partido`, que contiene los equipos participantes y los goles de cada enfrentamiento.
- El número total de partidos que recibe la función `construirMatriz()`, gracias al parámetro `totalPartidos`.

El módulo no solicita datos directamente por teclado.

**Salidas:**

- Una matriz de enfrentamientos con los marcadores de los partidos.
- Las abreviaturas de los nombres de los equipos en los encabezados.
- El nombre del equipo o de los equipos con mejor ataque.
- El nombre del equipo o  de los equipos con mejor defensa.
- La cantidad de goles a favor y en contra que corresponde a cada resultado.

Las funciones muestran los resultados, no devuelven valores.

## 4. Decisiones de diseño

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

1. `construirMatriz()`: recorre los partidos y anota los goles correspondientes en la matriz, relacionando los equipos local y visitante.

2. `mostrarMatriz()`: inicia la matriz, llama a `construirMatriz()` y presenta los enfrentamientos en forma de tabla, también muestra las abreviaturas de los equipos y usa `---` en la diagonal principal.

3. `mostrarMejores()`: recorre las estadísticas de los equipos para encontrar el máximo de goles a favor y el mínimo de goles en contra, después muestra todos los equipos que tengan esos valores.

**¿Qué estructuras de datos usa tu módulo, por qué las elegiste y cómo pasas los datos a cada función?**

Se usan las estructuras `Equipo` y `Partido`, escritas en `torneo.h`, para organizar la información de los equipos y los resultados de los encuentros.

También se utiliza una matriz bidimensional de enteros de tamaño `MAX_EQUIPOS x MAX_EQUIPOS`, porque permite representar los enfrentamientos entre todos los equipos mediante filas y columnas.

Los arreglos de equipos y partidos se reciben como parámetros de las funciones, se usan parámetros `const` cuando solamente se necesita consultar la información, evitando modificar los datos originales.

En `construirMatriz()` se recibe la matriz bidimensional para modificar sus valores y el número de partidos por valor, dentro de esa función se usa una referencia constante `const Partido&` para consultar cada partido sin copiar toda la estructura.

**¿Dónde demuestras los temas asignados a tu módulo?**

Demuestro el uso de matrices bidimensionales al almacenar los resultados de los enfrentamientos entre los equipos, también utilizo estructuras para organizar los datos de cada equipo y de cada partido, además uso ciclos para recorrer la información y hacer comparaciones.

**¿Qué ciclos usaste y por qué esos?**

Use ciclos `for` porque se cual es la cantidad máxima de equipos y partidos que se deben recorrer.

- En `construirMatriz()` se usa un ciclo para recorrer los partidos.
- En `mostrarMatriz()` se usan ciclos anidados para recorrer filas y columnas.
- En `mostrarMejores()` se usan ciclos para buscar los valores máximos y mínimos y para mostrar los equipos que empataron.

**¿Qué constantes usaste y por qué son constantes?**

Use las constantes definidas en `torneo.h`:

- `MAX_EQUIPOS`: Dice que el torneo tiene un máximo de seis equipos.
- `TOTAL_PARTIDOS`: Dice que se disputan quince partidos.
- `CARACTERES_ABREVIATURA`: indica que se usan los primeros tres caracteres del nombre para las abreviaturas.

Son constantes porque representan valores definidos por las reglas del proyecto y no necesitan cambiar cuando se ejectute el programa.

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

Utilicé las estructuras `Equipo` y `Partido`, también las constantes de `torneo.h`.

También use funciones de la biblioteca estándar de C++:

- `std::setw()` y `std::left` / `std::right` para organizar la presentación de la matriz.
- `std::toupper()` para convertir las abreviaturas a mayúsculas.
- `std::to_string()` para convertir los goles a texto y formar los marcadores.

No reutilicé directamente funciones de `utilerias.h`.

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?**

Actualmente, el módulo no tiene casos de rechazo  ni solicita información por teclado, trabaja con los equipos y partidos registrados por el programa.

Como mejora, sería mejor validar que existan los equipos y que los índices de los partidos sean válidos antes de construir la matriz.

## 5. Receta

### Pseudocódigo

```text
INICIO

FUNCIÓN construirMatriz(matriz, partidos, totalPartidos)

    PARA cada partido desde 0 hasta totalPartidos - 1 HACER

        Obtener el partido actual

        Guardar los goles del equipo local
        en la posición [local][visitante]

        Guardar los goles del equipo visitante
        en la posición [visitante][local]

    FIN PARA

FIN FUNCIÓN


FUNCIÓN mostrarMatriz(equipos, partidos)

    Crear una matriz de seis por seis
    e inicializar sus valores en cero

    Llamar a construirMatriz()

    Mostrar el título de la matriz

    Mostrar las abreviaturas de los equipos

    PARA cada fila HACER

        Mostrar el nombre del equipo

        PARA cada columna HACER

            SI la fila y la columna son iguales ENTONCES

                Mostrar ---

            SI NO

                Formar el marcador utilizando
                los goles de ambos equipos

                Mostrar el marcador

            FIN SI

        FIN PARA

    FIN PARA

FIN FUNCIÓN


FUNCIÓN mostrarMejores(equipos)

    Inicializar el máximo de goles a favor
    con el valor del primer equipo

    Inicializar el mínimo de goles en contra
    con el valor del primer equipo

    PARA cada equipo HACER

        Actualizar el máximo de goles a favor
        si se encuentra un valor mayor

        Actualizar el mínimo de goles en contra
        si se encuentra un valor menor

    FIN PARA

    Mostrar el título de mejor ataque

    PARA cada equipo HACER

        SI sus goles a favor son iguales al máximo ENTONCES

            Mostrar su nombre

        FIN SI

    FIN PARA

    Mostrar el título de mejor defensa

    PARA cada equipo HACER

        SI sus goles en contra son iguales al mínimo ENTONCES

            Mostrar su nombre

        FIN SI

    FIN PARA

FIN FUNCIÓN

FIN
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

Probé el funcionamiento con los resultados del escenario de prueba, comprobé que los goles de cada equipo se colocaran en las posiciones indicadas de la matriz y que los marcadores se mostraran correctamente desde la perspectiva de cada equipo.

También comprobé que se identificara correctamente el mejor ataque y la mejor defensa, durante las pruebas observé que era importante mantener el orden de los equipos para que los resultados de las filas y columnas fueran correctos.

## 6. Pruebas

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
|---|---|---|---|---|
| 1 | Mostrar la matriz de enfrentamientos | Seis equipos y 15 partidos del escenario de prueba | Mostrar los seis equipos y sus marcadores | Correcto, se mostraron los seis equipos y los enfrentamientos. |
| 2 | Identificar el mejor ataque | Resultados del escenario de prueba | Dortmund con 14 goles a favor | Correcto, apareció Dortmund con 14 goles. |
| 3 | Identificar la mejor defensa | Resultados del escenario de prueba | Arsenal con 7 goles en contra | Correcto, apareció Arsenal con 7 goles en contra. |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
|---|---|---|
| 1 | Cómo organizar los marcadores de los enfrentamientos en una matriz bidimensional. | Use las posiciones de los equipos local y visitante para guardar los goles correspondientes. |
| 2 | Cómo mostrar los marcadores desde la perspectiva de cada equipo. | Use las posiciones opuestas de la matriz para formar el marcador de cada enfrentamiento. |


## 8. Reflexión

**¿Qué aprendiste?**

Aprendí a utilizar matrices bidimensionales para organizar información de varios equipos y sus enfrentamientos, también aprendí más el uso de estructuras, arreglos y ciclos.

Entendí cómo relacionar los datos de los partidos con las estadísticas de los equipos, aprendí la importancia de dividir el programa en funciones para que cada una tenga una responsabilidad específica.

**¿Qué cambiarías de tu proceso?**

Mejoraría la planeación inicial del módulo, haciendo más pruebas antes de integrarlo al programa principal, también agregaría validaciones para comprobar que los datos de los partidos sean correctos y que existan equipos registrados antes de generar los resultados.

Así, el módulo sería más robusto y podría manejar mejor situaciones inesperadas.