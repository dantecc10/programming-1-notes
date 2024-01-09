# Programación 1

## Clasificación de los lenguajes

* Lenguajes imperativos: Qué hacer y cómo hacerlo
  * Procedurales
  * Orientados a Objetos
  * Paralelos
    * Distribuidos
* Lenguajes declarativos: Qué hacer, pero no cómo hacerlo
  * Funcionales
  * Relacionales

## Historia del lenguaje C

C es un lenguaje de programación de propósito general, asociado a *UNIX*. Reúne características de los lenguajes de alto nivel; con gran poderío basado en sus operaciones a nivel de bits, y la mayorían de los elementos de la programación estructurada de los lenguajes de alto nivel. Proviene de BCPL, a través de B.

Sirvió para mejorar el sistema *UNIX*, por lo que se le considera su lenguaje nativo. Desarrollado por Dennis Ritchie en 1971.

Incluyó una sintaxis más simple, aritmética de direcciones de memoria e introdujo el concepto de ***apuntador***.

## Identificadores

Es una secuencia de letras y dígitos, donde el primer caracter debe ser una letra o subguión. Las letras mayúsculas son distintas de las minúsculas. Pueden tener cualquier longitud, pero sólo los primeros 31 caracteres son significativos.

Ejemplos:

* `x1 ≠ X1`
* `var ≠ Var`
* `var ≠ vaR`

Un identificador nunca puede ser una palabra reservada del lenguaje, como alguna de las siguientes:

* `short`
* `int`
* `long`
* `float`
* `double`
* `char`
* `signed`
* `unsigned`
* `if`
* `else`
* `switch`
* `case`
* `for`
* `while`
* `do`
* `continue`
* `break`
* `goto`
* `default`
* `register`
* `struct`
* `static`
* `typedef`
* `const`
* `enum`
* `union`
* `sizeof`

## Estructura de un programa en C

Primer programa en C:

```c
/* Un primer programa en C */

#include <stdio.h>
main()
{
	printf("Hola Puebla");
}
```

### Programa general

```c
#include ...
#define ...

main(){
	/*Declaraciones locales*/
	/*Sentencias*/
}
Tipo t función f (){
}
```

Los tipos básicos de variables en C son:

* Caracter: Se declara con la palabra reservada `char`, ocupa un byte de memoria
* Real:
* Entero: