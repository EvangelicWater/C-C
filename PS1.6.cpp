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
    float can,mul;
    gotoxy(30,10);
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),13);
	printf("\n  Input the number of dollars you want to convert to pesos: ");
	scanf("%f",&can);
	system("pause");
	system("cls");


	mul=can*20;
	gotoxy(28,10);

	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("\n The result of the conversion is an amount of  %f",mul);

	}
