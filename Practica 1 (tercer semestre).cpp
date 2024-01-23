#include "score4.h"
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <stdio.h>
// Programa elaborado por Andres Humberto Martinez Escobedo//
 void gotoxy(int x,int y){  //columna, rengl?
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
int main (int argc, char *argv[])//inicia main incluyendo las variables necesarias para la piramide
 {
 	int opcion;//declaro la variable opcion
 	do{
 	printf("----------------------------------");//imprimo el menu incluyendo separacion	
	printf("\nBienvenido\n"); 
 	printf("\nCalculo de calificaciones.......1 \n");
 	printf("\nNumeros perfectos..........2\n");
 	printf("\nPiramide...........3\n");
 	printf("\nPortada de integrantes..........4\n");
 	printf("\nSalir..........5\n");
 	printf("----------------------------------");
 	printf("\nIntrodusca la opcion que desea ejecutar: \n");//finaliza el menu
 	scanf("%d",&opcion);//obtiene la opcion elegida del menu
 	
 	
 	switch (opcion){//inicia switch conforme el menu
 		case 1: { //inicia el primer switch correspondiente a el calculo de calificaciones
			
		 printf("\nRango de Calificaciones\n");//imprime lo de que se va a llevar acabo
 		       int rango1=0,rango2=0,rango3=0,rango4=0,rango5=0,c2;//declaracion de variables para el calculo de calificaciones
 		       
 		       printf("\n Ingrese la calificacion o ingrese -5 para terminar: \n");//se solicita las calificaciones añadiendo estableciendo -5 para terminar el bucle de while     
 		       scanf("%d",&c2);//se obtiene el valor de las calificaciones
 		       
 		       while(c2>-5){
 		       	printf("\n Calificacion: \n");// si no se selecciona -5 no termina el bucle
 		       	scanf("%d",&c2);// se obtiene el valor de las calificaciones
 		       	
 		       	if(c2>0&&c2<3.99){// se establece que si la calificacion es mayor a 0 y menor a 3.99 se incremente el rango1
					
 		       		rango1++;//incremento
					}
				else 
				if(c2>=4&&c2<5.99){// se establece que si la calificacion es mayor o igual a 4 y menor a 5.99 se incrementa el rango2
				
					rango2++;}//incremento
				
				else 
				if(c2>=6&&c2<7.99){//se establece que si la calificacion es mayor o igual a 6 y menor a 7.99 se incrementa el rango3
				
					rango3++;//incremento
				}
				else 
				if(c2>=8&&c2<8.99){// se establece que si la calificacion es mayor o igual a 8 y menor a 8.99 se incrementa el rango4
				
					rango4++;//incremento
				}
				else{ // si no se cumple ninguna de las condiciones anteriores se le aplica incremento a el rango5
				 
				
				
				     rango5++;//incremento
					}
				
 		       	
 		       	}
				
				
 		       
 		        
				 printf("\n0..3.99 = %d\n",rango1);//impresion de la cantidad de valores en cada rango
				 printf("\n4..5.99 = %d\n",rango2);
				 printf("\n6..7.99 = %d\n",rango3);
				 printf("\n8..8.99 = %d\n",rango4);
				 printf("\n9..10.99 = %d\n",rango5);//ultima impresion
 		  }
 		break;//finaliza primer case 
 		case 2: printf("\n Numeros Perfectos \n");//inicia case de numeros perfectos
 		int cantidad;//se declara la variable de cantidad 
 		printf("\nIngrese un numero entero: \n");//se solicita ingresar un numero entero
		 scanf("%d",&cantidad);//se obtiene el numero ingresado
		 
		 if (cantidad==6)// si la cantidad ingresada es igual a 5 se imprime que hay 1 numero perfecto
		{
			printf("\nTiene 1 numero perfecto\n");//impresion
		}
		else if (cantidad==26)// si la cantidad es igual a 26 se imprime que hay 2 numeros perfectos
		{
			printf("\nTiene 2 numeros perfectos\n");//impresion
		}
		else if(cantidad<26&&cantidad>=6)// si la cantidad es menor a 26 y mayor o igual a 6 entonces se imprime que hay 1 numero perfecto
		{
			printf("\nTiene 1 numero perfecto\n");//impresion
		}
		else if (cantidad<496&&cantidad>=26)//si la cantidad es menor a 496 y mayor o igual a 26 se imprime que hay 2 numeros perfectos
		{
			printf("\nTiene 2 numeros perfectos\n");//impresion
		}
		 else if (cantidad==496)//si la cantidad ingresada es igual a 496 se imprime que hay 3 numeros perfectos
		{
			printf("\nTiene 3 numeros perfectos\n");//impresion
		}
		 else if (cantidad<8128&&cantidad>=496)//si la cantidad es menor a 8128 y menor o igual a 496 se imprime que tiene 3 numeros perfectos
		{
			printf("\nTiene 3 numeros perfectos\n");//impresion
		}
		else if (cantidad>=8128)//si la cantidad es mayor o igual a 8128 se imprime que hay 4 numeros perfectos
		{
			printf("\nTiene 4 numeros perfectos\n");//impresion
		}
		else if(cantidad<2){//si la cantidad es menor a 2 se imprime que no puede ser menor a 2 la cantidad ingresada
			printf("\nLa cantidad no puede ser menor a 2\n");//impresion
		}
		
		else{
			printf("\nNo tiene numeros perfectos\n");//si no se cumple ninguna de las condiciones anteriores se imprime que no tiene ningun numero entero la cantidad ingresada
		}
		printf("\nFIN\n");//fin 
		system("pause");//pausa
	    system("cls");//limpieza de pantalla       
 		break;//finaliza case 2
 		case 3: printf("\nPiramide\n");//empieza el case 3 de la piramide
  int contador;//declaracion de la variable usada para el contador
  int filas;//declaracion de la variable usada para las filas
  int posiciones;//declaracion de la variable usada para las posiciones
  int asteriscos;//declaracion de la variable para los los el uso de asteriscos 
  char c;//declaracion de variable para el ingreso de letras
  printf("No. de Filas : ");// se solicita el numero de filas
  scanf(" %d",&filas);// se obtiene el numero de filas
  printf("caracter: ");//se solicita el caracter a usar en la piramide
  scanf(" %c",&c);//se obtiene el caracte a usar en la piramide 
   posiciones=filas*2;// se declara que las posiciones son las filas multiplicadas por 2
  for(contador=1;contador<=posiciones;contador+=2) {//inicio de ciclo for utilizado para imprimir los caracteres de la piramide
     printf("%*c",((posiciones-(contador))/2)+1,'*');
     for(asteriscos=1;asteriscos<contador;asteriscos++) {
        printf("%c",c);
     }//finaliza impresion de la piramide
     printf("\n");//se imprime un espacio
     
     
  }
 		break;//finalizacion del case 3
 		case 4: printf("\nPortada de integrantes: \n");//inicio del case que contiene la cantidad inmensa de integrantes de mi equipo
 		        printf("\n Andres Humberto Martinez Escobedo");//se imprime el integrante mas importante del equipo
 		        printf("\nFIN\n");//se imprime la finalizacion de la portada de integrantes porque no tengo equipo 
 		        system("pause");//pausa
	    system("cls");//limpieza de pantalla
 		break;//finalizacion del case 4
 		
	 }
	 
 	}while ( opcion !=5 );//se declara que mientras no se seleccione 5 se repetira el menu indefinidamente
 	return 0;//finalizacion del codigo
 }
