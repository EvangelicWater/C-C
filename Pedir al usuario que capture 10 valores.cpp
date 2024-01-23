#include <stdio.h>
//Pedir al usuario que capture 10 valores
int i,val;
main()
{
	printf("porfavor ingrese los 10 numeros      ");
	for(i=1;i<=10;i++)
	{
		printf(" Ingrese el valor  #%d: ",i);
		scanf("%d",&val);
		printf("El ultimo dato ingresado fue:  %d  ",val);
	}
}
