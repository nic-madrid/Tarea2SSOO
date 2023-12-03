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
Pero para utilizarlos necesitamos imagenes de prueba, en nuestro caso utiizamos la siguiente imagen: 
* https://eoimages.gsfc.nasa.gov/images/imagerecords/73000/73751/world.topo.bathy.200407.3x21600x21600.C1.png

Ahora procedemos a utilizar los ejecutables

#### PS
* Primero ejecutamos el comando "./PS"
* Luego escribimos el nombre de la imagen a procesar
* Luego escribimos el nombre que queremos que tenga la imagen de salida
* Se nos abre la imagen a tamaño completo en ambos formatos y por consola se muestra el tiempo que demora

#### PT
* Primero ejecutamos el comando "./PT"
* Luego escribimos el nombre de la imagen a procesar
* Luego escribimos el nombre que queremos que tenga la imagen de salida
* Escogemos la cantidad de nucleos a utilizar
* Se nos abre la imagen a tamaño completo en ambos formatos y por consola se muestra el tiempo que demora

#### POMP
* Primero ejecutamos el comando "./POMP"
* Luego escribimos el nombre de la imagen a procesar
* Luego escribimos el nombre que queremos que tenga la imagen de salida
* Escogemos la cantidad de nucleos a utilizar
* Se nos abre la imagen a tamaño completo en ambos formatos y por consola se muestra el tiempo que demora



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
