//Practoca de ciclo for
//Amdres Humberto Martinez Escobedo 00601AM

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
int i,n;
setlocale(LC_CTYPE, "Spanish");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),13);
gotoxy(23,9);  
printf("Ingrese el numero positivo en el que desea que termine el ciclo:  ");
scanf("%i",&n);
	
	for(i=5;i<=n;i++)
	{ 
		printf("%d\n",i);
	} 
	
	
	
		
}
