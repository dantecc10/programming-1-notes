Algoritmo Problem
	Definir n, lim, acumulador, i como Entero
	
	Escribir "Introduce un n�mero: " 
	Leer n
	Escribir "Indica un l�mite: "
	Leer lim
	Mientras (n*i) <= lim
		acumulador = acumulador + (n*i)
		i = (i+1)
	FinMientras
		Escribir "La suma de los multiplos de ", n, " hasta el numero ", lim, " es ", acumulador, "."
FinAlgoritmo
