#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
// Programa elaborado por Andres Humberto Martinez Escobedo//
 void gotoxy(int x,int y){  //columna, rengl?
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
main()
{
	float cal[9];
	int i;
	
	for(i=0;i<=9;i++)
	{
		printf("\nIngrese el valor  %d:",i+1);
		scanf("%f",&cal[i]);
	}
	for(i=9;i>=0;i--)
	{
		printf("\n Calificacion ingresada #%d es:  %0.2f",i+1,cal[i]);
	}
}
