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
 	int N1,N2;
 	    
    	      
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),4);
	gotoxy(23,9);    
	printf("\t     Ingrese un numero  ");
	scanf("%d",&N1);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),5); 
	gotoxy(23,9);   
	printf("\t     Ingrese otro numero  ");
	scanf("%d",&N2);
	
	
	system("pause");

	system("cls");
	
	
	if(N1%N2 ==0)
	{
		gotoxy(23,9);   
		printf("\t Los valores ingresados son divisores. \n");
	}

	
	else
	{
		gotoxy(23,9);   
		printf("\t Los valores ingresados no son divisores o no son validos. \n");
	}
 }
