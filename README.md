[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/lY6sRjHW)




UNIVERSIDAD TECNOLÓGICA NACIONAL 
INSTITUTO NACIONAL SUPERIOR DEL PROFESORADO TÉCNICO


SIMON SAYS

Trabajo final de Técnicas Digitales 3-602

Uriel Elías Irusta - Jonathan Ezequiel Vizgarra
uriel.irusta@alu.inspt.utn.edu.ar - jonathan.vizgarra@alu.inspt.utn.edu.ar
         

Docente de la cátedra
Prof. Israel Pavelek


Tabla de contenido
1. Introducción	
2. Descripción
3. Flujo del Juego:
4. Resumen del Programa desarrollado:

 
1. Introducción
El proyecto del "Juego de Simon Dice" es una implementación electrónica y programada de un juego clásico de memoria y secuencias. 
El juego se basa en una serie de luces LED y botones que se iluminan y emiten tonos en una secuencia aleatoria, que el jugador debe repetir correctamente. 
Este juego es una excelente manera de desafiar y mejorar la memoria secuencial y la coordinación en los jugadores.

2. Descripción
Componentes y Funcionamiento:

•	LEDs y Botones: El proyecto utiliza LEDs de diferentes colores (rojo, amarillo, verde y azul) que se iluminan en secuencia. 
Los botones correspondientes a estos colores se utilizan para que el jugador repita la secuencia.

•	Buzzer: Se utiliza un buzzer para generar tonos musicales que coinciden con los colores de los LEDs. 
Los tonos ayudan al jugador a asociar los sonidos con los colores.

•	Arduino: El proyecto se implementa en una plataforma Arduino, que controla la secuencia, los LEDs y los botones, y genera los tonos a través del buzzer.

•	Cables, Resistencias y Protoboard.

3. Flujo del Juego:

•	Inicio: El juego comienza con una secuencia de inicio en la que los LEDs parpadean y se emiten tonos musicales.

•	Secuencia del Juego: Después del inicio, el Arduino genera una secuencia aleatoria de colores y sonidos. Los LEDs correspondientes se encienden y los tonos se reproducen en orden.

•	Respuesta del Jugador: El jugador debe repetir la secuencia presionando los botones correspondientes en el mismo orden. Un temporizador limita el tiempo para cada respuesta.
•	Evaluación de la Respuesta: El Arduino verifica si la secuencia del jugador coincide con la generada por el juego. 
Si la respuesta es correcta, el juego avanza a la siguiente ronda. Si es incorrecta o el tiempo se agota, el jugador pierde.

•	Victoria o Derrota: El juego continúa hasta que el jugador haya completado con éxito un número específico de rondas (configurable en el código). 
Si el jugador alcanza este objetivo, el juego celebra su victoria. Si no, se reproduce una secuencia de derrota.


4. Resumen del Programa desarrollado:
1.	Verifica si comienza un nuevo juego. Si es así, reproduce la secuencia de inicio, restablece el contador de rondas y genera aleatoriamente una secuencia de números del 0 al 3 que controla qué LEDs el usuario debe recordar.

2.	El juego avanza en rondas del 0 al N nivel. En cada ronda, los LEDs parpadearán en un patrón, y el jugador debe recrear el patrón presionando los botones correspondientes. La dificultad aumenta con cada ronda.

3.	Utiliza un bucle para hacer parpadear los LEDs según la secuencia hasta alcanzar la cantidad correspondiente a la ronda.

4.	Si se presiona el botón incorrecto, el jugador pierde. Si se presiona el botón correcto, pasa al siguiente número en la secuencia.

5.	Si el jugador repite la secuencia completa para esa ronda, aumenta el número de rondas. Vuelve al paso 3.

6.	Sigue incrementando la ronda hasta que el jugador pierda o complete N rondas.

Algunas Funciones implementadas:
1.	encenderLed(int led): Enciende uno de los cuatro LEDs y reproduce el tono asociado.
2.	apagarLed(int led): Apaga el LED especificado.
3.	encenderTodos(): Enciende todos los LEDs.
4.	apagarTodos(): Apaga todos los LEDs.
5.	efectoBarrido(int demora, int repeticiones): Realiza un efecto de barrido encendiendo y apagando los LEDs en un patrón.
6.	gameOver(): Realiza acciones y efectos cuando el jugador pierde el juego.
7.	iniciarNuevoJuego(): Inicia un nuevo juego, llenando la secuencia y ejecutando la melodía inicial.
8.	llenarSecuencia(): Llena la secuencia con valores aleatorios.
9.	mostrarSecuencia(int hasta, int demora): Muestra la secuencia hasta el nivel especificado con cierta demora entre LEDs.
10.	leerBotones(): Utiliza digitalRead() para verificar qué botón está presionado y devuelve un valor de 0 a 3 o 4 si ningún botón está presionado.
11.	ejecutarMelodia(): Reproduce una melodía al inicio del juego o después de una victoria.
12.	efectoBaliza(int demora, int repeticiones): Realiza un efecto de baliza encendiendo y apagando todos los LEDs junto con tonos.



