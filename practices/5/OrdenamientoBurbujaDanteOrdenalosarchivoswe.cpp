#include <stdio.h>
#include <time.h>
#include <windows.h>

int main () {

/*Variables*/
int a[100],n,i,j,temp,arregloultradeluxepromaxhd;

/*Ingresar datos*/
printf("Ingrese tamaño de arreglo\n");
scanf("%i",&n);
system("cls");


for (i=0;i<n;i++)
	{printf("A continuacion rellene el arreglo\n");
	scanf("%i",&a[i]);
	system("cls");}


for (i=0;i<n-1;i++)
	{for (j=n-1;j>i;j--)
		{if (a[j]<a[j-1])
			{temp=a[j];
			 a[j]=a[j-1];
			 a[j-1]=temp;}}}


for (i=0;i<n-1;i++)
	{printf("%i,",a[i]);}
	 printf("%i",a[n-1]);

	
	

}
