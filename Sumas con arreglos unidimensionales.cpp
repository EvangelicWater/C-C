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
 main()
 {
 	float vec1[5],vec2[5],sum[5];
 	int i;
 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);    
    gotoxy(23,9);
 	printf("Este programa pide 5 valores para solicitar despues otros 5 valores y sumarlos\n");
 	system("pause");
 	system("cls");
 	for(i=0;i<5;i++){
	 
 	printf("\nIngrese los primeros 5 valores. %d:",i+1);
 	scanf("%f",&vec1[i]);
	 }
 	for(i=0;i<5;i++){
 		
 		printf("\n Ingrese los siguientes 5 valores. %d:",i+1);
 		scanf("%f",&vec2[i]);
	 }
	 for(i=0;i<5;i++){
	 	sum[i]=vec1[i]+vec2[i];
	 }
	 for(i=0;i<5;i++){
	 
	 printf("\n El resultado de la suma numero %d es = %f \n ",i+1,sum[i]);}
 }
