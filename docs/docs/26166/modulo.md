## 1. Autor

**Nombre:** Roberto Emiliano Velazquez Ibarra 
**Matrícula:** 26166 
**Módulo:** [2-Simulacion de partidos]  
**Archivo de código:** [Simulacion.h]

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

[Mi módulo genera los 15 partidos del torneo (todos contra todos, una vuelta), les pone marcador y los muestra en pantalla. Le sirve al usuario para ver cuánto quedó cada partido, ya sea con goles aleatorios o con los marcadores fijos del modo de prueba.]

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

[Recibe por parámetros los equipos, los partidos y cuántos equipos hay. Del teclado solo lee el modo de simulación (1 para aleatorio, 2 para prueba). Lo que produce son los 15 partidos con sus goles guardados en el arreglo, y en pantalla imprime la tabla de resultados y los mensajes de rechazo cuando algo no se puede hacer.]

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

[ generarPartidos: arma los 15 enfrentamientos con dos ciclos anidados.
 asignarMarcadores: pone los goles de cada partido, aleatorios o de prueba.
pedirModoSimulacion: pregunta el modo y repite hasta que la opción sea válida.
simularPartidos: valida y junta todo lo anterior.
 mostrarResultados: imprime el reporte con el formato pedido.
Las separé así para que cada función haga una sola tarea.]

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

[Uso un arreglo de registros Partido, donde cada uno guarda el índice del local, el del visitante y sus goles. Elegí registros para tener todos los datos de un partido juntos, y guardar índices en vez de nombres para no duplicar información. Los arreglos se pasan como arreglo: sin const en los que se modifican (partidos) y con const en los que solo se leen (equipos). El número de equipos va por valor, porque solo lo leo, y totalPartidos va por referencia, porque la función lo actualiza.]

**¿Dónde demuestras los temas asignados a tu módulo?**

[Registros: en generarPartidos y asignarMarcadores, al usar partidos[k].local, .visitante, .golesLocal y .golesVisitante. Ciclos anidados: en generarPartidos, con el ciclo de i y el de j desde i + 1.]

**¿Qué ciclos usaste y por qué esos?**

[Dos for anidados en generarPartidos: j empieza en i + 1 para que no haya partidos repetidos ni un equipo contra sí mismo, y salen justo 15. Un for en asignarMarcadores y otro en mostrarResultados, porque sé cuántos partidos son. Un while en pedirModoSimulacion, porque no sé cuántas veces se va a equivocar el usuario.]

**¿Qué constantes usaste y por qué son constantes?**

[MAX_EQUIPOS y TOTAL_PARTIDOS (de torneo.h), COL_LOCAL y COL_VISITANTE (columnas de la matriz de prueba), OPCION_ALEATORIO y OPCION_PRUEBA (opciones del modo), y ANCHO_NUM, ANCHO_EQUIPO y ANCHO_MARCADOR (anchos de columna del reporte). Son constantes porque no cambian durante el programa y así evito números sueltos como 6, 15 o 17, que dificultan entender y cambiar el código.]

**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

[De utilerias.h uso leerEntero, para pedir el modo de simulación sin que se rompa con texto o decimales, y numeroAleatorio, para los goles del modo aleatorio. De escenario_prueba.h leo la matriz GOLES_PRUEBA para el modo de prueba. De torneo.h uso los registros Equipo y Partido y las constantes MAX_EQUIPOS y TOTAL_PARTIDOS. No repetí lógica de ninguno: no escribí mi propia lectura ni mi propio generador de números.]

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

[ Si hay menos de 6 equipos registrados: "Faltan equipos para simular el torneo."
 Si el torneo ya se simuló: "El torneo ya fue simulado."
 Si el usuario elige un modo que no existe: "Opcion no valida. Elige 1 o 2." y se vuelve a preguntar.
 Si pide ver los resultados antes de simular: "Primero simula el torneo."]

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
[simularPartidos(totalEquipos, partidos, totalPartidos):
    si totalEquipos < MAX_EQUIPOS: avisar y regresar
    si totalPartidos > 0: avisar que ya se simuló y regresar
    modoPrueba = pedirModoSimulacion()
    generarPartidos(partidos, totalEquipos)
    totalPartidos = TOTAL_PARTIDOS
    asignarMarcadores(partidos, totalPartidos, modoPrueba)

pedirModoSimulacion():
    repetir
        opcion = leerEntero(...)
        si opcion es 1: regresar falso
        si opcion es 2: regresar verdadero
        avisar que no es válida
    hasta que sea válida

generarPartidos(partidos, totalEquipos):
    k = 0
    para i de 0 a totalEquipos - 1
        para j de i + 1 a totalEquipos - 1
            partidos[k] = local i, visitante j, goles en 0
            k = k + 1

asignarMarcadores(partidos, totalPartidos, modoPrueba):
    para k de 0 a totalPartidos - 1
        si modoPrueba: goles = GOLES_PRUEBA[k]
        si no: goles = numeroAleatorio() para cada equipo

mostrarResultados(equipos, partidos, totalPartidos):
    si totalPartidos es 0: avisar y regresar
    imprimir título y encabezados
    para k de 0 a totalPartidos - 1
        armar marcador "golesLocal - golesVisitante"
        imprimir número, local, marcador, visitante con ancho fijo]
```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

[Sí. Con el escenario de prueba, el partido 1 sale de i = 0 y j = 1: Aguilas contra Halcones, con GOLES_PRUEBA[0] = {3, 3}, o sea 3 - 3. El ciclo termina en i = 4, j = 5, el partido 15: Pumas contra Tigres, 0 - 1. Conté 5 + 4 + 3 + 2 + 1 = 15 partidos, que coincide con TOTAL_PARTIDOS. [Corregí: escribe aquí lo que de verdad cambiaste. Si fue algo del borrador, por ejemplo que antes validaba dentro de otra función o que el modo se pasaba como parámetro, ponlo. Si no cambiaste nada, dilo así.]]

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Simular con menos de 6 equipos | Opción 3 con 2 equipos | "Faltan equipos para simular el torneo." | [lo que salga] |
| 2 | Modo de prueba | 6 equipos, modo 2 | 15 partidos; el 1 es Aguilas 3 - 3 Halcones y el 15 Pumas 0 - 1 Tigres | [lo que salga] |
| 3 | Modo inválido | Modo 7, luego "abc", luego 1 | Avisa y vuelve a preguntar hasta aceptar el 1 | [lo que salga] |
| 4 | Simular dos veces | Opción 3 otra vez | "El torneo ya fue simulado." | [lo que salga] |
| 5 | Resultados antes de simular | Opción 4 sin simular | "Primero simula el torneo." | [lo que salga] |
| 6 | Modo aleatorio | 6 equipos, modo 1 | 15 partidos con goles entre 0 y 5 | [lo que salga] |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
Duda: si mi código iba en escenario_prueba.h. Vi que ese archivo dice "NO MODIFICAR" y que el proyecto pide un .h propio, así que lo puse en Simulacion.h y solo lo incluyo para leer GOLES_PRUEBA.
 Duda: si tenía que usar apuntadores. Revisé la sección 2.2 y mis temas son registros y ciclos anidados; los apuntadores les tocan a los módulos 4 y 5.
 Duda: qué cosas eran obligatorias en el código. Repasé el contrato mínimo (sección 3.2) y fui palomeando cada punto contra mi módulo.
 Error:  Hubo un problema debido a que se escribio dos veces el codigo y nos soltaba un errormal compilar, indagando encontramos el problema y lo solucionamos.

## 8. Reflexión

**¿Qué aprendiste?**

[Especificamente en este proyecto aprebdi a optimizar mas las coas, tambien investigando en un proyecto personal descubri que puedo hacer muchas cosas interesantes con git, visual studio y phyton, estoy investigando como descargar en mi laptop un asistente virtual que pueda hacer bastantes cosas.]

**¿Qué cambiarías de tu proceso?**

[Creo que la manera de trabajarlo, ya que hasta el final empece a trabajarlo con ganas, cuandodesde un pruncipio debio ser asi.]
