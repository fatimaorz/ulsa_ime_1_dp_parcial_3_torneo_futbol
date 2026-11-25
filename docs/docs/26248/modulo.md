## 1. Autor

**Nombre:** Diego Serrano Martínez  
**Matrícula:** 26248 
**Módulo:** modulo 4 
**Archivo de código:** mostrar_tabla.h

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

mi modulo acomoda los equipos en orden de puntos y muestra el ganador, sirve para mostrar el equipo en orden y no tener que buscar en una lista desordenada el ganador, también permite ver si hay empates y elegir cual equipo ganaría.

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

mi modulo recive los puntos que hizo el equipo en el torneo, que son los resultados de los partidos que la persona agrega y produce la lista de los equipos en orden por mayor a menor puntaje. 

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**
use intercambiar(Equipo* a, Equipo* b): esto hace que se cambie el equipo de posición si tiene menos puntos que el equipo al lado de el.
ordenarTabla(Equipo equipos[], int total): este llama al apuntador intercambiar si es que la lista esta en orden equivocado.
mostrarTabla(const Equipo equipos[], int total): esto imprime la tabla de posiciones, el nombre y las estadisticas del equipo.
contarEmpatados(const Equipo equipos[], int total): en caso de que haya un empate esto hace que se tenga que elegir entre los 2 equipos para ver cual es el ganador.
mostrarCampeon(const Equipo equipos[], int total): anuncia el campeon con sus puntos.



**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**
Registro (Equipo): agrupa todos los datos de un equipo (nombre, jugados, ganados, puntos, etc.). lo elegí porque así un equipo se mueve completo y no quedan datos sueltos. Por eso, al intercambiar dos equipos, el nombre y las estadísticas se van juntos.
Arreglo de Equipo: guarda los 6 equipos en orden. lo elegí porque permite recorrerlos con un ciclo, compararlos por posición y reacomodarlos al ordenar.
Apuntadores (Equipo*): se usan en intercambiar, y en ordenarTabla para recorrer el arreglo (actual y siguiente). Se eligieron porque el módulo lo pide y porque con la dirección de los equipos se modifican los equipos reales, no copias.
LOS DATOS SE PASAN:
intercambiar(Equipo* a, Equipo* b)	Con apuntadores: recibe las direcciones de los dos equipos y los modifica directamente.
ordenarTabla(Equipo equipos[], int total)	Como arreglo (sin const, porque lo modifica) y total por valor.
mostrarTabla(const Equipo equipos[], int total)	Como arreglo constante (solo lectura) y total por valor.
contarEmpatados(const Equipo equipos[], int total)	Arreglo constante y total por valor. Devuelve un int.
elegirCampeon(const Equipo equipos[], int empatados)	Arreglo constante y empatados por valor. Devuelve la posición elegida.
mostrarCampeon(const Equipo equipos[], int total)	Arreglo constante y total por valor.


**¿Dónde demuestras los temas asignados a tu módulo?**

Los temas son el ordenamiento que se demuestra en "ordenarTabla", intercambio de posiciones que se demuestra con el "intercambiar" y los apuntadores son "Intercambiar" y "ordenarTabla".

**¿Qué ciclos usaste y por qué esos?**

[Inserta aquí tu respuesta]

**¿Qué constantes usaste y por qué son constantes?**

[Inserta aquí tu respuesta]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[Inserta aquí tu respuesta]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[Inserta aquí tu respuesta]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[Inserta aquí tu respuesta]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Inserta aquí tu respuesta]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 2 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |
| 3 | [Inserta aquí tu respuesta] | [Inserta aquí tu respuesta] |

## 8. Reflexión

**¿Qué aprendiste?**

[Inserta aquí tu respuesta]

**¿Qué cambiarías de tu proceso?**

[Inserta aquí tu respuesta]
