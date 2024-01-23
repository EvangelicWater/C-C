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
int main()
{
  	int x, v1,v2;
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
	gotoxy(24,10);
  	printf("Este programa indica los numeros pares entre los dos valores ingresados\n");
  	system("pause");
  	system("cls");
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(24,10);
  	printf("ingrese el primer valor:  ");
  	scanf("%d", &v1);
  	system("pause");
  	system("cls");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(24,10);
  	printf("Ingrese el segundo valor:  ");
  	scanf("%d", &v2);
	system("pause");
  	system("cls");  
  
  	printf(" Los numeros pares entre %d y %d son : ",v1,v2);
  	for(x = v1; x <= v2; x= x+2)
  	{
    	printf(" %d ", x);
  	}
 
  	return 0;
}
