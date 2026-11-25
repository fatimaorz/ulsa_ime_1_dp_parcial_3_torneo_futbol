## 1. Autor

**Nombre:** Regina Murillo Arellano 
**Matrícula:** 26100  
**Módulo:** consultas  
**Archivo de código:** consultas.h

## 2. Propósito

¿Qué hace tu módulo y para qué le sirve a quien usa el programa?

Mi módulo sirve para consultar la ficha del equipo, donde se muestra, su nombre, los juegos; ganados, perdidos y empatados, goles a favor y en contra. Además se muestran los equipos contra quienes ha jugado, aqui puedes verificar el marcador y si se perdio, gano o empato el partido, de igual manera si ingresas el nombre de un equipo que no se encuentra el programa te dice que ese equipo no fue encontrado. 

Esto le sirve a las personas que usan el programa porque pueden visualizar rapidamente toda la información de su equipo. 

## 3. Entradas y salidas

¿Qué recibe tu módulo (parámetros y datos del teclado) y qué produce (lo que imprime o devuelve)?

Recibe: los equipos registrados, los partidos, y la información de cada equipo (leerCadena)
Salidas: imprime la ficha del equipo con la tabla de rivales 
En caso de no ser encontrado el equipo muestra que el equipo no fue encontrado 

## 4. Decisiones de diseño

Explica cada decisión y por qué la tomaste.

**¿Qué funciones tiene tu módulo y qué tarea hace cada una?**

buscar equipo en esta función busca al equipo comparando los nombres, si tiene mayusculas o minisculas. Si encuentra el equipo regresa su información si no lo enceuntra regresa nullptr

consultar equipo en esta función busca al equipo, muestra su ficha, tambien recorre los partidos, sus rivales, etc.

**¿Qué estructuras de datos usa tu módulo (registros, arreglos, matrices o apuntadores), por qué las elegiste y cómo pasas los datos a cada función (por valor, por referencia, como arreglo o con un apuntador)?**

arreglos para equipos y partidos para ver toda la información 
apuntadores para acceder a los elementos de los arreglos sin modificarlos 

**¿Dónde demuestras los temas asignados a tu módulo?**

buscarEquipo - localizar el equipo 
consultarEquipo - recorre los partidos
nullptr para cuando no se encuentre un equipo, regresa 

**¿Qué ciclos usaste y por qué esos?**

for, if, if else, else 

**¿Qué constantes usaste y por qué son constantes?**

ANCHO_RIVAL y ANCHO_MARCADOR - ayuda a establecer los espacios al momento de imprimir la tabla para que no se empalme 


**¿Qué funciones reutilizaste de `utilerias.h`, de `torneo.h` o de otro módulo?**

leerCadena - para el nombre del equipo 
aMinusculas - para comparar los nombres, sin importar minusculas y mayusculas 
to_string - los goles a texto 
setw - para acomodar las columnas 

**¿Qué casos de rechazo maneja tu módulo y qué mensaje muestra en cada uno?** Si tu módulo es el 3, escribe "No aplica".

Equipo no encontrado - cuando se busca el equipo y no esta nullptr regresa y muestra mensaje de que no esta 

## 5. Receta

Tu receta en pseudocódigo, escrita antes de programar.

```
FUNCION buscarEquipo(equipos, nombreBuscado)
    PARA i desde 0 hasta MAX_EQUIPOS - 1
        p = direccion del equipo i              (equipos + i)
        SI el nombre de p es igual a nombreBuscado
           (sin importar mayusculas)
            REGRESAR p
    REGRESAR nullptr                            (no se encontro)

FUNCION consultarEquipo(equipos, partidos)
    nombreBuscado = leerCadena("Nombre del equipo: ")
    equipoEncontrado = buscarEquipo(equipos, nombreBuscado)

    MOSTRAR "--- FICHA DE EQUIPO ---"

    SI equipoEncontrado es nullptr
        MOSTRAR "Equipo no encontrado: " + nombreBuscado
        TERMINAR

    MOSTRAR nombre, jugados, ganados, empatados, perdidos,
            goles a favor, goles en contra, puntos

    fila = equipoEncontrado - equipos           (posicion del equipo)
    MOSTRAR encabezado: RIVAL, MARCADOR, RESULTADO

    PARA i desde 0 hasta TOTAL_PARTIDOS - 1
        p = direccion del partido i             (partidos + i)

        SI el local de p es fila
            rival = visitante
            golesEquipo = golesLocal
            golesContrario = golesVisitante
        SI NO, SI el visitante de p es fila
            rival = local
            golesEquipo = golesVisitante
            golesContrario = golesLocal
        SI NO
            saltar este partido

        equipoRival = *(equipos + rival)

        SI golesEquipo > golesContrario
            resultado = "Ganado"
        SI NO, SI golesEquipo < golesContrario
            resultado = "Perdido"
        SI NO
            resultado = "Empatado"

        MOSTRAR equipoRival.nombre, marcador, resultado

```

**¿Probaste tu receta a mano con los datos del escenario? ¿Qué corregiste?**

Si lo revise con los datos de prueba para comparar y como localizar el equipo, verificar que los datos coincidan y la ficha esta correcta 
Tambien la parte del equipo que no existe para que indique que no esta 
Al igual que la parte de mayusculas y minisculas, para que aun asi mostrara la ficha del equipo 

## 6. Pruebas

Incluye casos normales y casos límite.

| # | Qué probaste | Entrada | Resultado esperado | Resultado obtenido |
| --- | --- | --- | --- | --- |
| 1 | Consultar equipo existente | Leones | Mostrar la ficha completa de Leones| Mostro su ficha completa sin errores |
| 2 | Consultar un equipo que no existe | Muffy | Mostrar equipo no encontrado: Muffy| SE muestra el mensaje de equipo no encontrado |
| 3 | Buscar equipo con mayusculas y minusculas | LeONes | Encontrar el equipo sin importar como se escriba | Si se encuentra el equipo |

## 7. Bitácora de dudas y errores

| # | Duda o error | Cómo lo resolví |
| --- | --- | --- |
| 1 | No sabía bien como se utilizaba nullptr| Regrese a notas de clase, investigue y pregunte |
| 2 | Tuve problemas al integrar al main, ya que la función mostraba error al imprimir la ficha  | modificar el main, preguntar y borrar elementos del main, para que la ficha saliera bien  |
| 3 | Se me dificulto mas la integración de consultas al main | consultando mis errores |

## 8. Reflexión

**¿Qué aprendiste?**

A usar de mejor manera las constantes, nullptr

**¿Qué cambiarías de tu proceso?**

Dedicar más tiempo para corregir los errores al momento de compilar 
