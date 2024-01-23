#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <conio.h>
#include <math.h>
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
  	int a;
  	setlocale(LC_CTYPE, "Spanish");
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),13);
	 gotoxy(24,10);  
  	printf("Ingrese cuatro digitos  ");
  	scanf("%d",&a);
  	system("pause");
	    system("cls");
  	/*al principio intente que mostrara una condicion para determinar si es entero o decimal pero no pude hacer que el programa mostrara si es entero, decimal y bisiesto 
  	por lo que simplemente lo deje en int ya que int no permite decimales
  	*/
  	if(a<1000){
  		printf("los numeros ingresados no cumplen con el requisito de cuatro digitos obligatorios");
	  }
	if(a>9999){
		printf("Los numeros ingresados exceden la cantidad requerida");
	}
	if(a%4==0 and a%100!=0 or a%400==0)
	{
		printf("Es bisiesto");
	}
	else{
		printf("No es bisiesto");
	}
	
	return 0;

  }
  
