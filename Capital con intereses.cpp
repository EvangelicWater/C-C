#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <conio.h>

main()
{
 float p_int,cap,tot_i,capf;
 char op;
 printf(" Banco Nacional ingresa tu capital  ");
 scanf("%f",&cap);
 printf("Ingrese la tasa de intereses  ");
 scanf("%f",&p_int);
 tot_i=cap*p_int;
 if(tot_i>7000)
 {
 	printf("Deseas reinvertir tu capital? \nS=Si\nN=No ");
 	scanf("&s",&op);
 	switch(op)
 	{
 		case 1: capf=cap+tot_i;
 		  printf("Tu inversion sera de $%f\n GRACIAS POR TU PREFERENCIA",capf);
 		  break;
 		  case 2: printf("Tu capital esta seguro\nGRACIAS POR TU PREFERENCIA");
 		  
	 }
	
	 
 }
 else printf("Tu capital esta seguro\nGRACIAS POR TU PREFERENCIA");
 	getch();
	return 0;
}
