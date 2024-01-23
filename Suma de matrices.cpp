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
 	float m1[3][3],m2[3][3],re[3][3];
 	int i,j;
 	
 	for(i=0;i<3;i++){
 		for(j=0;j<3;j++){ 
 		
		 
 		printf("\nIngrese los valores de la primera  matriz 3x3.  \n",i+1);
 	      scanf("%f",&m1[i][j]); }
	 
	 }
	 for(i=0;i<3;i++){
	 	for(j=0;j<3;j++){
		 
		 
	 	printf("\nIngrese los valores de la segunda matriz 3x3.  \n",i+1);
 	scanf("%f",&m2[i][j]); }
	 	
	 
	 }
	 for( i=0;i<3;i++){
	 	for(j=0;j<3;j++){
		 
	 	
		 
	 
	 re[i][j]=m1[i][j]+m2[i][j];}
	 }
	 
	 for(i=0;i<3;i++){
	 	for(j=0;j<3;j++){
		 
	 	
	 		printf("\t%f",re[i][j]);
		 }
		 printf("\n\n");
	 }
	 return 0;
 }
