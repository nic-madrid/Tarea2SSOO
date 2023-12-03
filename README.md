# Tarea 2 - SSOO

Nuestro proyecto se basa en el procesamiento de imágenes mediante tres metodos: Procesamiento Secuencial (PS), Procesamiento con Threads (PT) y Procesamiento con OpenMP (POMP). El objetivo es comparar y analizar el rendimiento de cada metodo en términos de velocidad y eficiencia al procesar imágenes.

## Instrucciones de Uso

### Instalación

Para poder ejecutar los programas primero necesitamos ejecutar nuestro archivo makefile, para esto utilizamos la consola de comandos y nos situamos en la carpeta "src", una vez dentro de este ejecutamos el comando "make" para que cree los ejecutables de los programas, estos tendran los nombres a sus correspondientes metodos:
* PS, Procesamiento Secuencial
* PT, Procesamiento Threads
* POMP, Procesamiento OpenMP


![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/7af4220d-fb29-455f-902a-8381c6878685)

![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/788afe1f-d2ff-4ac3-9672-9a291e0294cb)


### Como usar

Una vez ejecutado el comando make se nos generaran 3 ejecutables; PS, PT y POMP
Pero para utilizarlos necesitamos imagenes de prueba, en nuestro caso utiizamos la siguiente imagen: 
* https://eoimages.gsfc.nasa.gov/images/imagerecords/73000/73751/world.topo.bathy.200407.3x21600x21600.C1.png
*(DISCLAIMER, en mi computador no funciona la imagen al ser muy grande, pero en maquinas mas potentes funciona perfectamente, para casos practicos y mas visibles utilizamos otra imagen en las pruebas)
Ahora procedemos a utilizar los ejecutables

#### PS
* Primero ejecutamos el comando "./PS"
* Luego escribimos el nombre de la imagen a procesar
* Luego escribimos el nombre que queremos que tenga la imagen de salida
![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/0b3a4373-9e67-4b0c-8d56-51eab7222eea)

* Se nos abre la imagen a tamaño completo en ambos formatos y por consola se muestra el tiempo que demora
![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/692f9376-8976-433d-8fe0-51623cbbcf80)

  
* Una vez cerramos la ventana nos muestra la ruta en donde queda almacenado
![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/34217dc2-4e47-4702-8043-2f4488fdbdf4)


#### PT
* Primero ejecutamos el comando "./PT"
* Luego escribimos el nombre de la imagen a procesar
* Luego escribimos el nombre que queremos que tenga la imagen de salida
* Escogemos la cantidad de nucleos a utilizar
![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/150937bd-9215-45f6-a373-5981de05cc2a)

* Se nos abre la imagen a tamaño completo en ambos formatos y por consola se muestra el tiempo que demora
![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/7e13847f-0a11-4f27-9e9e-ce059a7f8515)



#### POMP
* Primero ejecutamos el comando "./POMP"
* Luego escribimos el nombre de la imagen a procesar
* Luego escribimos el nombre que queremos que tenga la imagen de salida
* Escogemos la cantidad de nucleos a utilizar
![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/30163524-0f3b-4bba-96c0-44ca1da98c0f)

* Se nos abre la imagen a tamaño completo en ambos formatos y por consola se muestra el tiempo que demora
![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/52292a60-1fa7-4aaf-9297-ce246293d4fd)

* Una vez cerramos la ventana nos muestra la ruta en donde queda almacenado
![image](https://github.com/nic-madrid/Tarea2SSOO/assets/142953854/180fdff2-e46a-4d99-b54e-044d3c6a708b)




## Estructura del Proyecto

El proyecto fue estructurado en base a lo que se nos solicito, una carpeta "src" con los codigos de los programas a utilizar y carpetas donde estan enlazadas los programas para procesar las imagenes, una para las imagenes a procesar y otra con las imagenes convertidas

## Dependencias

Las dependencias utilizadas para este trabajo fueron:
* threads, para la manejar threads
* OpenCV, para manipular la matriz de pixeles
* OpenMP, para manipular threads
* Chrono, para medir el tiempo que demora en ejecutar
* iostream, para mensajes en consola
* vector, para manipulación de vectores.
