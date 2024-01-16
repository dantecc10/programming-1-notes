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
	/*
		Constantes
		Declaraciones globales
		Prototipos de funciones
		Variables
	*/

main(){
	/*Declaraciones locales*/
	/*Sentencias*/
}
Tipo t función f (){ /*Definición de otras funciones*/
}
```

Snippet:

```c
/*Muestra los tipos de datos y constantes*/

#include <stdio.h>
#define N 10 /*Se define la constante con valor de 10*/

main()
{
	int a, b = 20;

	printf("El valor de a es: %d", a);
	printf("\nDame un dato: ");
	scanf("%i", &a);
	printf("\nEl valor de a después de leer: %i", a);
	printf("\nEl valor de N es %d: ", N);
	printf("\nEl valor de b es %i: ", b);
	b = b + a;
	printf("\nEl valor de b es %i: ", b);
	// N = N + a; /*No se puede asignar a una constante*/
}
```

### Comentarios

Los comentarios en C son cadenas arbitrarias de símbolos colocados entre los delimitadores `/*` y `*/`.

### Cadenas

Una cadena es una secuencia de caracteres entre comillas. Si el caracter `"` tiene que aparecer en la cadena, se precede por el caracter `\`.

Ejemplos:

* `"Una cadena de texto"`
* `"z"`
* `"           "`
* `"Una cadena con \" comillas"`
* `""`

## Tipos de datos

Los tipos básicos de variables en C son:

* Caracter: Se declara con la palabra reservada `char`, ocupa un byte de memoria y puede representar 256 símbolos.
* Real: Se declara con la palabra reservada `double` o `float`, ocupa 8 o 16 bytes de memoria, respectivamente.
* Entero: Se declara con la palabra reservada `int` y `short`; ocupa 4 o 2 bytes de memoria, respectivamente.

### Constantes

En C, las constantes se definen con la palabra reservada `#define`, seguida del tipo de variable y su nombre.

### Expresiones

Se tienen operadores:

* Aritméticos (`*`, `/`, `%` `+`, `-`)
* Relacionales (`>`, `>=`, `<`, `<=`, `==`, `!=`, `!`, `&&`, `||`)
* De incremento y decremento (`++`, `--`)
* Lógicos (`~`, `&`, `|`, `^`, `<<`, `>>`)
* Asignación (`=`, `+=`, `-=`, `*=`, `/=`, `%=`, `<<=`, `>>=`, `&=`, `|=`, `^=`)

Para hacer una conversión de datos en una operación, como un cociente flotante de dos enteros, se puede usar `w = (float)x/y //cast`.

Programa de ejemplo:

```c
#include <stdio.h>
int main() {
	int x = 9, y = 6, z;

	z = x & y;
	printf("El AND es: %d", z);
	z = x | y;
	printf("\nEl OR es: %d", z);
	z = ~x;
	printf("\nEl NOT es: %d", z);
}
```

## Condicionales

Se usan las palabras reservadas printf, scanf, getchar, puts, putc, fprint, fscan.

## Estructura de secuencia

En se tienen proposiciones. Una proposición simepl es una única instrucción. Una proposición compuesta son dos o más instrucciones, en este caso es necesario que éstas se encuentren entre corchetes `{}`.

Cada instrucción

## Estructuras de decisión

Hay dos ejemplos básicos:

* Condicional simple:
  * `if` (condición)
    * *Proposición*
* Condición doble:
  * `if` (condición)

    * *Proposición verdadera*
  * `else`

    * *Proposición falsa*

Ejemplo de condicional simple:

```c
#include <stdio.h>

main() {
	int a;

	printf("\nDame el número: ");
	scanf("%d", &a);

	if(a < 0) // No es necesario escribir las llaves cuando sólo hay una instrucción
		a *= -1; // a = a * -1

	printf("\El valor absoluto es: %i", a);
}
```

Ejemplo de condicional doble:

```c
#include <stdio.h>

main() {
	int a, b;

	printf("\nDame el primer número: ");
	scanf("%d", &a);
	printf("\nDame el segundonúmero: ");
	scanf("%d", &b);

	if(a > b) // No es necesario escribir las llaves cuando sólo hay una instrucción
		printf("El primer número es mayor");
	else
		if(a<b)
			printf("\El segundo número es mayor");
		else
			printf("\nAmbos números son iguales");

	printf("\El valor absoluto es: %i", a);
}
```

### Expresión condicional <`?`>

Ejemplo simple:

```c
#include <stdio.h>

main() {
	int a, b;

	printf("\nDame el primer número: ");
	scanf("%d", &a);
	printf("\nDame el segundonúmero: ");
	scanf("%d", &b);

	(a > b) ? printf("\nEl primer número es mayor") : (a < b) ? printf("\El segundo número es mayor") : printf("\nAmbos números son iguales");

}
```

### Decisión múltiple

La decisión múltiple, con condición igual es de esta forma:

```c
switch(expresión){
	case exp_const:
		proposición
		break;
	default:
		proposición
}
```

Ejemplo:

```c
#include <stdio.h>

main(){
	int a, b;
	float c;
	char op;
	printf("\nIndique a: ");
	scanf(%i, &a);
	printf("\nIndique b: ");
	scanf(%i, &b);

	printf("\nIndique la operación: ");
	scanf(%c, &op);

	switch(op){
		case '+':
			c = a + b;
			printf("\nLa suma es: %f", c);
			break;
		case '-':
			c = a - b;
			printf("\nLa resta es: %f", c);
			break;
		case '*':
			c = a * b;
			printf("\nEl producto es: %f", c);
			break;
		case '/':
			if (b != 0) {
				c = (float) a / b;
				printf("\nEl cociente es es: %f", c);
			} else {
				printf("\nEl divisor no puede ser 0.);
			}
			break;

	}
}
```
