# Tarea2SSOO

Descripción del proyecto.

## Instrucciones de Uso

### Instalación

Para poder ejecutar los programas primero necesitamos ejecutar nuestro archivo makefile, para esto utilizamos la consola de comandos y nos situamos en la carpeta "src", una vez dentro de este ejecutamos el comando "make" para que cree los ejecutables de los programas, estos tendran los nombres a sus correspondientes metodos:
* PS, Procesamiento Secuencial
* PT, Procesamiento Threads
* POMP, Procesamiento OpenMP

### Como usar

Una vez ejecutado el comando make se nos generaran 3 ejecutables; PS, PT y POMP

* Para Ejecutar PS simplemente escribimos ./PS



## Estructura del Proyecto

El proyecto fue estructurado en base a lo que se nos solicito, una carpeta "src" con los codigos de los programas a utilizar y carpetas donde estan enlazadas los programas para procesar las imagenes, una para las imagenes a procesar y otra con las imagenes convertidas

## Dependencias

Las dependencias utilizadas para este trabajo fueron:
* threads, para la manejar threads
* OpenCV, para manipular la matriz de pixeles
* OpenMP, para manipular threads
* Chrono, para medir el tiempo que demora en ejecutar
* iostream, para mensajes en consola
* vector
