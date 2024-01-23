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
     { setlocale(LC_CTYPE, "Spanish");
     float DIA,mul;
     gotoxy(5,5);
     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),6);    
	printf("\tIngrese el numero de dias que desea convertir a segundos: ");
	scanf("%f",&DIA);
	system("pause");
	system("cls");


	mul=DIA*86400;
	
	gotoxy(10,10);
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);    
	printf("\tEl numero de segundos obtenidos son: %f ",mul);
	
	 }
