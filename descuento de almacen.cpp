#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <conio.h>

main()
{
	float compra,desc,tot_pag;
	printf("LINDA ALMACEN  Ingrese el total de tu compra  ");
	scanf("%f",&compra);
	
	if(compra>1000)
	{
		desc=compra*.2;
		
	}
	else desc=0;
	tot_pag=compra-desc;
	printf ("Total a pagar: $%f    GRACIAS POR TU PREFERENCIA",tot_pag);
	getch();
	return 0;
}
