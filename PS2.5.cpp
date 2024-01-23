#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
 void gotoxy(int x,int y){  //columna, renglón
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 main()
 {
 
 setlocale(LC_CTYPE, "Spanish");
 float com,pf1,d1,d2,d3,pf2,pf3;
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),7); 
 gotoxy(23,9);      
	printf("\t  Ingrese el precio de su producto a pagar: ");
	scanf("%f",&com)
	;system("pause");
	 ;system("cls");
	
	if(com>0&&com<800)
	{
		printf("\t Su producto cuenta con un descuento de 0 por ciento.\n ");
		system("pause");
	    system("cls");
		printf(" El precio final de su producto es de %f",com);
		
		
	  }  
	else if(com>=800&&com<=1500)
	{
		printf(" \t Su producto cuenta con un descuento de 10 por ciento. \n ");
		system("pause");
	    system("cls");
		d1=com*10/100;
	    pf1=com-d1;
		
		printf(" El precio final de su producto es de %f",pf1);
		
			
	  }
	else if(com>1500&&com<=5000)
	  {
	  	printf(" \t Su producto cuenta con un descuento de 15 por ciento. \n ");
	  	system("pause");
	    system("cls");
	    d2=com*15/100;
	    pf2=com-d2
	    ;printf("El precio final de su producto es de %f",pf2);
		}  
	else if(com>5000)
	{
		printf(" \t Su producto cuenta con un descuento de 20 por ciento. \n");
		system("pause");
	    system("cls");
	    d3=com*20/100;
	    pf3=com-d3;
	    printf("El precio final de su producto es de %f",pf3);
		}
	else if(com<0)
	{
		printf("Los valores ingresados son negativos");
		}	
	else
		{
			printf("Los valores ingresados no son correctos ");
			
			}	
}
