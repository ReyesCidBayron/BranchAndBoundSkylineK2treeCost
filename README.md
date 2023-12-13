# README 
Nueva versión implementación Skyline y sus variantes implementadas sobre un k2-tree.

## Contenido del repositorio

Contiene las siguientes carpetas:
* dataset: Lugar en donde se generan los datos sintéticos
* libs: Contiene la implementación de las consultas.
* results: Gráficas resultantes de la experimentación.
* skyline-master: versión anterior.
***
Contiene los siguentes archivos:
* .cpp: Códigos C++ que permiten la ejecución de los algoritmos y de las pruebas de correctitud, tiempo y memoria.
* .sh: Script Shell que permiten la ejecución de las pruebas de correctitud y el proceso de experimentación.
* .txt y .kt: pequeños datasets de prueba en su formato sin comprimir (.txt) y comprimidos (.kt).

## Compilación

Para compilar todo use:
```
make
javac libs/*.java
```