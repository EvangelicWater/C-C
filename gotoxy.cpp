#include <iostream> 
#include <windows.h>  
#include <locale.h>
 void gotoxy(int x,int y){  //columna, rengl�n
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
	printf("�Hola Mundo! ");
	gotoxy(23,9);
	printf("Ni�o\n");
	gotoxy(20,10);
	printf("C�mo est�s?");
	//system("PAUSE"); 
	printf("�Hola de nuevo! �Qu� edad tienes? ");
	scanf("%d",&edad);
	printf("Tienes %d a�os",edad);
	
} 
