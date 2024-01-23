#include <stdio.h>
//Pedir al usuario que capture 10 valores 
int i;
main()
{
	printf("Porfavor ingrese el numero que quiere iniciar   ");
	scanf("%d",&i);
	do{
		printf(" El ciclo se repite mientras ingreses valores menores a  11. ");
		printf("Ingrese un valor:  ");
		scanf("%d",&i);
	}
	while(i<11);
	{
		printf("Termina el ciclo, valor= %d  ",i);
	}
}
