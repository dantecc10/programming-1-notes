
Inicio
	Entero n, lim, acumulador = 0, i = 0;

	Escribir "\nIntroduce un número: "
	scanf("%i", &n);
	printf("\nIndica un límite: ");
	scanf("%i", &lim);
	while((n*i)<=lim) {
		acumulador += n*i;
		i++;
	}

	printf("\nLa suma de los multiplos de %i hasta el numero %i es %i.", n, lim, acumulador);
}