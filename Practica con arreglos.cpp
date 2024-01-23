#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <conio.h>
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
   char  nombre[50];
   float valores[5];
   int suma,media;
   setlocale(LC_CTYPE,"Spanish");
   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);    
    gotoxy(23,9);
   printf("\nEste programa pide 5 valores para despues sumarlos e imprimir su resultado y su media en orden inverso.\n");
   system("pause");
	    system("cls");
   printf("Ingrese su nombre: ");
   scanf("%s",&nombre);
   printf("Bienvenido  %s ",nombre);
   for(int i=0;i<5;i++){
	 
 	printf("\nIngrese  5 valores. ",i+1);
 	scanf("%f",&valores[i]);
	 suma+=valores[i];
	 media=suma/5;
	 }
 	
 	for(int i=4;i>=0;i--){
 		printf("Los datos ingresados fueron: %f \n",valores[i],i+1);
	 }
	 
 		
	 
	 
	 printf("\n El resultado de la suma  es %d  \n ",suma);
	 printf(" La media es %d",media);
	 
 }
