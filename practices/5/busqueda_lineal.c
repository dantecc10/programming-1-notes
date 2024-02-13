#include <stdio.h>
int main(void){
	int a[10],num,bandera=0,pos[10];
	printf("Dame el arreglo de 10 elementos\n");
	for (int i=0;i<10;i++){
		printf("[%i]= ",i+1);
		scanf("%i",&a[i]);
	};
    printf("---------------\n");
    printf("Num que deseas encontrar: ");
    scanf("%i",&num);
    //busqueda lineal
    printf("\n\nBusqueda lineal\n--------------------\n");
    int x=0;
    for (int i=0;i<10;i++){
		if (a[i]==num){
			bandera=1;
			pos[x]=i;
			x++;
		};
	};
	if (bandera==1){
		printf("\nEl número se encuentra en el arreglo :)\nEn la(s) posicion(es):\n");
		for (int i=0;i<x;i++){
			printf(": %i\n",pos[i]+1);
		};
	}else{
		printf("El número no se encuentra en el arreglo\n");
	};
	printf("\n\nBusqueda binaria\n----------------\n");
	// busqueda binaria
	int l=0,r=10,encontrar=0,m;
	while ((l<r)&& ((encontrar+1)==1)){
		m=(l+r)/2;
		if (a[m]==num){
			encontrar=1;
		}else 
		if(a[m]<num){
			l=m+1;
		}else{r=m;};
	};
	if (encontrar==0){
		printf("El número no se encuentra en el arreglo\n");
	}else{printf("El número se encuentra en el arreglo :>\n");};
	//
};
