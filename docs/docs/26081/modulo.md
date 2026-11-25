## 1. Autor

**Nombre:** Fatima Marisol Orozco Castro  
**Matrícula:** 26081  
**Módulo:** 1 
**Archivo de código:** registros.h

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

El módulo 1 permite registrar los equipos del torneo uno por uno y mostrar la lista de equipos registrados. Valida que cada nombre cumpla las reglas (largo de 3 a 15 caracteres, sin acentos ni ñ, sin repetirse y sin distinguir mayúsculas de minúsculas) para que el resto de los módulos trabaje con datos correctos.

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

Entradas:
- Del teclado: el nombre del equipo, con `leerCadena`.
- Por parámetros: el arreglo `equipos` y la variable `cantidad` (equipos registrados hasta el momento).

Salidas:
- `registrarEquipo`: guarda el nombre en `equipos[cantidad]`, aumenta `cantidad` e imprime mensajes de error o de éxito.
- `mostrarEquipos`: imprime el reporte `--- EQUIPOS REGISTRADOS ---` con columnas `#` y `EQUIPO`.
- Las funciones de validación devuelven `true` o `false`.

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

`largoValido`: revisa que el largo esté entre `MIN_CARACTERES_NOMBRE` y `MAX_CARACTERES_NOMBRE`.
- `sinAcentos`: revisa que cada carácter sea letra A-Z, a-z o espacio.
- `aMinusculas`: convierte un texto a minúsculas para comparar sin distinguir mayúsculas.
- `nombreRepetido`: revisa si el nombre ya existe entre los equipos registrados.
- `registrarEquipo`: pide el nombre, lo valida y lo guarda.
- `mostrarEquipos`: imprime la lista de equipos.

Separé una función por regla para que cada una haga una sola tarea y se pueda probar por separado.

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

**Registro (`Equipo`):** agrupa los datos de cada equipo en una sola unidad.
- **Arreglo de `Equipo`:** guarda los 6 equipos en orden de registro, con tamaño fijo `MAX_EQUIPOS`.
- Paso de datos:
  - `cantidad` va **por referencia** (`int&`) porque `registrarEquipo` la modifica y `main` debe ver el cambio.
  - `equipos` se recibe como arreglo (no se copia). En `registrarEquipo` se modifica; en `mostrarEquipos` y `nombreRepetido` va como `const` porque solo se lee.
  - Los textos van como `const std::string&` cuando solo se leen (evita copiar y evita modificar).
  - `aMinusculas` recibe una **copia** a propósito, para no alterar el nombre original.

**¿Dónde demuestras los temas asignados a tu módulo?**

Registros: `Equipo` y el campo `nombre`.
- Arreglos: `equipos[cantidad].nombre = nombre;` y los recorridos.
- Validación de cadenas: `largoValido`, `sinAcentos`, `aMinusculas` y `nombreRepetido`.

**¿Qué ciclos usaste y por qué esos?**

for` en `sinAcentos`, `aMinusculas`, `nombreRepetido` y `mostrarEquipos`: se conoce de antemano cuántas posiciones recorrer.
- `while (!valido)` en `registrarEquipo`: no se sabe cuántos intentos fallidos habrá, así que se repite hasta que el nombre sea válido.

**¿Qué constantes usaste y por qué son constantes?**

MAX_EQUIPOS`, `MIN_CARACTERES_NOMBRE` y `MAX_CARACTERES_NOMBRE`. Son constantes porque su valor nunca cambia, y si hay que modificarlas se cambian en un solo lugar `torneo.h` en vez de buscar números sueltos como 6 o 15.

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

`leerCadena` (de `utilerias.h`) para leer el nombre. Ya rechaza texto vacío y quita espacios en las orillas, así que no dupliqué esa lógica.
- Las constantes de `torneo.h` y el registro `Equipo`.
- Dentro de mi módulo, `nombreRepetido` reutiliza `aMinusculas`.

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

Lista llena: "Lista llena, no se pueden registrar mas equipos."
- Largo no válido: "Error: longitud de nombre no valida."
- Acentos, ñ u otros caracteres: "Error: solo se permiten letras y espacios."
- Nombre repetido: "Error: el equipo ya esta registrado."
- Mostrar sin equipos: "No hay equipos registrados."
Decisión de diseño: se permiten espacios en medio del nombre (por ejemplo "Real Madrid"), pero no números ni símbolos.
## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
FUNCION largoValido(nombre)
    RECIBE: nombre (texto, solo lectura)
    DEVUELVE: verdadero o falso
    1. Si largo de nombre < MIN_CARACTERES_NOMBRE, devolver falso
    2. Si largo de nombre > MAX_CARACTERES_NOMBRE, devolver falso
    3. Devolver verdadero

FUNCION sinAcentos(nombre)
    RECIBE: nombre (texto, solo lectura)
    DEVUELVE: verdadero o falso
    1. Para cada posicion i de 0 hasta largo de nombre - 1:
          2. Si la letra en i no es A-Z, a-z ni espacio, devolver falso
    3. Devolver verdadero

FUNCION aMinusculas(texto)
    RECIBE: texto (copia)
    DEVUELVE: el texto en minusculas
    1. Para cada posicion i del texto:
          2. Cambiar la letra en i por su version minuscula
    3. Devolver texto

FUNCION nombreRepetido(nombre, equipos, cantidad)
    RECIBE: nombre (solo lectura), equipos (arreglo, solo lectura),
            cantidad (entero, por valor)
    DEVUELVE: verdadero o falso
    1. Guardar aMinusculas(nombre) en nombreMin
    2. Para cada posicion i de 0 hasta cantidad - 1:
          3. Si aMinusculas(equipos[i].nombre) es igual a nombreMin,
             devolver verdadero
    4. Devolver falso

FUNCION registrarEquipo(equipos, cantidad)
    RECIBE: equipos (arreglo, se modifica), cantidad (entero, por referencia)
    DEVUELVE: nada
    1. Si cantidad es igual a MAX_EQUIPOS:
          mostrar mensaje de lista llena y terminar
    2. Repetir hasta que el nombre sea valido:
          3. nombre = leerCadena("Nombre del equipo: ")
          4. Si NO largoValido: mostrar mensaje de largo
          5. Si no, si NO sinAcentos: mostrar mensaje de caracteres
          6. Si no, si nombreRepetido: mostrar mensaje de repetido
          7. Si no: marcar nombre como valido
    8. Guardar nombre en equipos[cantidad].nombre
    9. Aumentar cantidad en 1

FUNCION mostrarEquipos(equipos, cantidad)
    RECIBE: equipos (arreglo, solo lectura), cantidad (entero, por valor)
    DEVUELVE: nada
    1. Si cantidad es 0: mostrar "No hay equipos registrados" y terminar
    2. Mostrar "--- EQUIPOS REGISTRADOS ---"
    3. Mostrar "#" con ancho 4, alineado a la izquierda, y "EQUIPO"
    4. Para cada posicion i de 0 hasta cantidad - 1:
          5. Mostrar i + 1 con ancho 4 y equipos[i].nombre
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**
Probé la receta a mano con los nombres Pumas, pumas y Al. Vi que mostrarEquipos no decía nada si no había equipos, así que agregué un caso de rechazo. También me di cuenta de que largoValido debía usar < y > para aceptar exactamente 3 y 15 caracteres.

## 6. Pruebas

Incluye casos normales y casos límite.
| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Nombre válido normal | `Pumas` | Se registra | [pumas] |
| 2 | Largo mínimo (límite) | `Abc` (3) | Se registra | [abc] |
| 3 | Largo máximo (límite) | un nombre de 15 letras | Se registra | [nombre de 15 letras en minusculas] |
| 4 | Demasiado corto | `Al` | Error de longitud | [Error: longitud de nombre no valida] |
| 5 | Demasiado largo | `UnNombreMuyLargoX` (17) | Error de longitud | [Error: longitud de nombre no valida] |
| 6 | Repetido con otras mayúsculas | `Pumas` y luego `pumas` | Error de repetido | [Error: el equipo ya esta registrado.] |
| 7 | Con acento | `Aguilas` escrito con tilde | Error de caracteres | [Error: el equipo ya esta registrado.] |
| 8 | Con ñ | `Leñones` | Error de caracteres | [Error: el equipo ya esta registrado.] |
| 9 | Séptimo equipo | registrar después de 6 | Lista llena | [Lista llena, no se pueden registrar mas equipos] |
| 10 | Mostrar sin equipos | cantidad = 0 | "No hay equipos registrados." | [No hay equipos registrados] |
| 11 | Mostrar con equipos | 6 equipos | Lista numerada del 1 al 6 en orden de registro | [--- EQUIPOS REGISTRADOS ---
#   EQUIPO
1   Pumas
2   tadeo
3   barcelona
4   mermeladas
5   estigo
6   zasa] |


## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | Escribí `#include "Utilerias.h"` con mayúscula, pero el archivo se llama `utilerias.h`. En mi computadora no compilaba | Lo cambié a minúsculas para que coincida exactamente con el nombre del archivo. |
| 2 | Mi primera versión no tenía `#pragma once`, y el contrato lo exige en el `.h`. | Lo agregué al inicio de mi archivo. |
| 3 | Llamaba a `largoValido`, `sinAcentos` y `nombreRepetido` en `registrarEquipo`, pero todavía no las había escrito. | Las escribí arriba de `registrarEquipo`, porque C++ lee de arriba hacia abajo. |

## 8. Reflexión

**¿Qué aprendiste?**

Que de mis errores de programacion se puede aprender, no necesito que me salga desde el pricipio. Esta bien perfeccionar sobre la marcha.

**¿Qué cambiarías de tu proceso?**

Nada, me gusto que pude iniciar por mi cuenta pero tambien obtuve ayuda de la ia sobre que tipos de cambios debia hacer asi como tambien ayudarme a entenedr el por que era mejor realizarlo de otras maneras.
