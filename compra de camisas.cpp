#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <conio.h>

main()
{
	int num_camisas;
	float pre,tot_comp,tot_pag;
	printf ("CAMISAS POLO  ingresa el precio de la camisa ");
	scanf ("%f",&pre);
	printf ("Ingrese el numero de camisas a comprar ");
	scanf ("%d",&num_camisas);
	tot_comp=num_camisas*pre;
	
	tot_pag=tot_comp;

	if(num_camisas<1);
	{
		printf("no puedes ingresar numeros negativos ni 0   ");
		
	}
	printf("El total a pagar es de $%f",tot_pag);
	getch();
	return 0;
} 
