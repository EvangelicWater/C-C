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
  	float rad,area,circun;
  	
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),6);
	  gotoxy(20,8);  
	printf("Ingrese el radio del circulo ");

	scanf("%f",&rad);
		system("pause");
			system("cls");

	
	
	area=rad*rad*3.14;
	circun=rad*3.14*2;

    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),9);
    	gotoxy(22,8);
    
	printf("\n El area del circulo es de \n %f",area);
	system("pause");
	system("cls");
	
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),2);
	gotoxy(15,8);  
	
	printf("\n La circunferencia del circulo es de %f",circun);
  }
