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
 	float n1,n2,n3;
 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),2);    
    	gotoxy(23,9);      
	printf("     ingrese un numero  ");
	scanf("%f",&n1);
	printf("     ingrese otro numero  ");
	scanf("%f",&n2);
	printf("     ingrese otro numero  ");
	scanf("%f",&n3);

	system("pause");
	system("cls");
 	if(n1<n2&&n2<n3)
 	{
 		printf("Esta en orden creciente.");
	 }
	 
	else 
	{
		printf(" Los numeros no estan ordenados");
	}
 }

