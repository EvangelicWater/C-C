#include <stdio.h>
//Pedir al usuario que capture 10 valores
int i,val;
main()
{
	printf("Porfavor ingrese 10 numeros. ");
	i=1;
	while(i<11)
	{
		printf("Ingrese el valor #%d ",i);
		scanf("%d",&val);
		printf("El ultimo dato ingresado fue: %d ",val);
		i++;
	}
	printf("Termina el ciclo valor de i=%d ",i);
}

