## Practica 2, Diseño de firmware basado en sistema operativo de tiempo real
El objetivo de esta practica es trabajar sobre FreeRTOS, sistema operativo de tiempo real para microcontroladores, en esta practica se muestran conceptos de periodicidad, manejo de colas y bloqueos.   

## Ejercicio 1
En primer lugar, se crea un programa con dos tareas, una que parpada un LED cada 200 ms y otra que envía un “hola mundo” por la UART cada segundo.
Para que ambas tareas sean periódicas se utiliza la función vTaskDelayUntil.

## Ejercicio 2
En este ejercicio, se utilizan tres tareas, en la primera tarea se leen mediante i2c los datos provenientes de un acelerómetro cada 100ms, se utiliza una cola donde se almacena una estructura con los datos para que pueda ser leída por la tarea 2.
La tarea 2 muestra cada segundo por puerto serie los datos de la cola y enciende un LED, también se utiliza para desbloquear a la tarea 3.
La tarea 3 apaga el led encendido por la tarea 2 a los 200ms y se bloquea hasta que no haya transcurrido el siguiente periodo de la tarea 2.

## Enlace
Los siguientes ejercicios se pueden consultar en [git](https://github.com/joaquinuza/Practica2)

