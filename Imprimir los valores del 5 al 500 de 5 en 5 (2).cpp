//Imprimir los valores del 5 al 500 de 5 en 5
#include <stdio.h>
int x,lim;
main()
{
	printf("Numero limite: ");
	scanf("%d",lim);
	for(x=5;x<=lim;x+=5)
	{
		printf("%d",x);
	}
	printf("El valor actual de X, fuera del ciclo: %d",x);
}
