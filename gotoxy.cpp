#include <iostream> 
#include <windows.h>  
#include <locale.h>
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
	int edad; 
    gotoxy(20,8);
	printf("¡Hola Mundo! ");
	gotoxy(23,9);
	printf("Niño\n");
	gotoxy(20,10);
	printf("Cómo estás?");
	//system("PAUSE"); 
	printf("¡Hola de nuevo! ¿Qué edad tienes? ");
	scanf("%d",&edad);
	printf("Tienes %d años",edad);
	
} 
