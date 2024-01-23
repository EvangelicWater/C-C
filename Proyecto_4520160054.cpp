#include<conio.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <iostream>//librerias
/*Programa realizado por Anddrés Humberto Martínez Escobedo 
4520160054
18/6/2021
00603AM
Seminario de Solucion de Problemas de Estructura de Datos I */


int main()//main
{
int  ch;//variable utilizada para la opcion del menu


while (1)//inicio de while con (1) para permetir  su  ejecuccion sin limite del contenido del ciclo  

{
system ("color 70"); // system cambia el color del fondo a 7=Blanco y 0=Negro para las letras 
printf("\n---------------------------------------------------------------------\n");  
printf("\nMenu\n");
printf("\nProyecto Integrador\n");
printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");  	
printf("1. Ingresar IP\n2. Informacion sobre la clasificacion de las IP\n3. Salir");
printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"); 
printf("\nIngrese una opcion del menu: ");
scanf("%d", &ch);
printf("\n---------------------------------------------------------------------\n");//menu
switch (ch) /*inicio de switch en base a la opcion ingresada*/
{

case 1:
	{
	
printf("\nIngresar Octetos\n\n*AVISO*\n\nEn caso de ingresar mas de 3 digitos se tomara como valor erroneo.\n\n*AVISO*\n\nNo es necesario ingresar un punto al final del octeto\n\n*AVISO*\n\nDebido a la validacion de numeros enteros no se puede ingresar el numero 0\n\nLas IP que se necesiten ingresar con 0 seran validadas con 1\n\n");	
//Aviso correspondiente a los octetos
 char p_oct[255];//variable char utilizada para el primer octeto
    int p_o_v;//variable int que va a contener el primer_octeto_validado 
    
    printf("\nIngrese el primer octeto: ");//se solicita el primer octeto
    scanf("%s",p_oct);//se obtiene el primer octeto mediante scanf
    p_o_v=atoi(p_oct); /* atoi convierte el numero ingresado como cadena en entero
    en caso de ser posible, de lo contrario retorna 0*/
    
    if(p_o_v!=0){//si el primer_octeto_validado es diferente a 0 se ejecuta el if
	
        
    
    if(p_o_v>=0&&p_o_v<=127){//  //  //  ////   //   //  //  //  /// //  //   //   //  //  //  /// //  // //  //
    // si el primer_octeto_validado es mayor o igual a 0 y el primer_octeto_validado es menor o igual a 127 se ejecuta el if
		printf("\nCLASE A\n");  //  //   // // //   //   //  //  //  /// //  //   //   //  //  //  /// //  //  //  // 
    	char s_oct[255];            //   //    // //   //   //  //  //  /// //  //   //   //  //  //  /// //   ///   //  /
    	int s_o_v;                               //  //   //   //  //  //  /// //   //   //   //  //  //  /// //   //  //  // /
    	printf("\nIngrese el segundo Octeto: "); //   // //   //   //  //  //  /// //  //   //   //  //  //  /// //  //  //  // //
    	// se repite la misma validacion para el segundo octeto
		scanf("%s",s_oct);                 
    	s_o_v=atoi(s_oct);                           //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //  //  //  // / /
    	if(s_o_v!=0){
    		                                         //  //  //  //  // //  //  //  //  //  //  //  //  // //  // // //  // // //  //  // /      
    		char t_oct[255];
    		int t_o_v;
    		printf("\nIngrese el tercer Octeto: ");  // //  //  //  // ///  //  //  //  ///  // //  // /// ///  // /// //  /// /// //  ///  //  /
    		// se repite la misma validacion para el tercer octeto
			scanf("%s",t_oct);
    		t_o_v=atoi(t_oct);
    		if(t_o_v!=0){
    			                                       // // // /  //  //  //  // //  //  //  //  //  //  // //  //  //  //   / //  //  //  //  // //
    			char c_oct[255];
    			int c_o_v;
    			printf("\nIngrese el cuarto Octeto: "); // //  //  //  //  // //  // //  //   //   /   /  //  //  //  //  //  //  / //  / // /  //  // //
    			// se repite la misma validacion para el ultimo y tercer octeto
				scanf("%s",c_oct);
    			c_o_v=atoi(c_oct);                                                                                                                             //  IF PERTENECIENTE A LAS IP DE CLASE A
    			if(c_o_v!=0){
    				
    				if(p_o_v==10&&s_o_v>=0&&s_o_v<=255&&t_o_v>=0&&t_o_v<=255&&c_o_v>=1&&c_o_v<=255){  //  //  //  // // // // /// // // // // // // // //
    					// si el primer octeto validado es igual a 10 y el segundo octeto validado es mayor o igual a 0 y el segundo octeto validado es menor o igual a 255 y el tercer octeto validado es mayor o igual a 0 y el tercer octeto validado es menor a 255 y el cuarto octeto validado es mayor o igual a 1 y el cuarto octeto validado es menor a 255
						printf("\nDireccion de RED PRIVADA\n");
    					printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);// ip completa con puntos
					}
					else if(p_o_v==172&&s_o_v>=16&&s_o_v<=32&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){ //  //  //  // //  //  // //  //  // // // 
					// si el primer octeto validado es igual a 172 y el segundo octeto validado es mayor o igual a 16 y menor o igual a 32 y el tercer octeto validado es mayor o igual a 0 y menor o igual a 255 y el cuarto octeto validado es mayor o igual a 0 y menor o igual a 255 
						printf("\nDirecion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);// ip completa con puntos 
					}
					else if(p_o_v==192&&s_o_v==168&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){  //  // // //  // // // // // // // /// /// ///
						// si el primer octeto validado es igual a 192 y el segundo octeto es igual a 168 y el tercer octeto validado es mayor o igual a 0 y menor o igual a 255 y el cuarto octeto validado es mayor o igual a 0 y el cuarto octeto validado es menor o igual a 255
						printf("\nDireccion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==127&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						// si el primer octeto validado es igual a 127 y el segundo octeto validado es igual a 1 y el tercer octeto validado es igual a 1 y el cuarto octeto validado es igual a 1
						printf("\nDireccion de LOOPBACK\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);  //  //  //  //  //   ///  //  //  //  //  //  //  //  
					}
					else if(p_o_v==224&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						// si el primer octeto validado es igual a 244 y el segundo octeto validado es igual a 1 y el tercer octeto validado es igual a 1 y el cuarto octeto validado es igual a 1
						printf("\nDireccion MULTICAST\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);  //  //  //  ///  /// //  // // / //  //  ///
					}
					else if(p_o_v==1&&s_o_v==255&&t_o_v==255&&c_o_v==255){
						// si el primer octeto validado es igual a 1 y el segundo octeto validado es igual a 255 y el tercer octeto valido es igual a 255 y el cuarto octeto validado es igual a 255
						printf("\nDireccion de Difusion\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);  //  //  //  //  // // //  ///  // ///
					}
					else if(p_o_v==1&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						// si el primer octeto validado es igual a 1 y el segundo octeto validado es igual a 1 y el tercer octeto validado es igual a 1 y el cuarto octeto validado es igual a 1
						printf("\nDireccion de RED\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);  //  //  //  //  //  //  // // //
					}
					else{
						// si ninguno de los octetos ya validados entra en alguna de las redes anteriores se define como una red publica
						printf("\nDireccion PUBLICA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v); //  //  //  //  // // //
					}
				}
				else{// si el cuarto octeto validado no es correcto
					printf("\nOcteto Erroneo");  //  //  // //  //  //  //  //  //  //  //  // //  // //
				}
			}// si el tercer octeto validado no es correcto
			else{
				printf("\nOcteto Erroneo\n");  //  //  //  //  //  //  // // //  //  // //  //  //
			}
		}// si el segundo octeto validado no es correcto
		else{
			printf("\nOcteto Erroneo\n");   //  //  //  //  //  // //  //  //  //  //  //
		}
	}// fin del if perteneciente a las IP de clase A
	 //  //  //  //  //  //  //  //  //  //  //   //  //   //  //  //  //  //  //
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------
	// todos los siguientes if perteneciente a las diferentes clases de IP realizan la misma validacion y tienen los mismos if a ejecutar para las direcciones de red
	else if(p_o_v>=128&&p_o_v<=191){
		printf("\nCLASE B\n");
			char s_oct[255];
    	int s_o_v;
    	printf("\nIngrese el segundo Octeto: ");
    	scanf("%s",s_oct);
    	s_o_v=atoi(s_oct);
    	if(s_o_v!=0){
    	
    		char t_oct[255];
    		int t_o_v;
    		printf("\nIngrese el tercer Octeto: ");
    		scanf("%s",t_oct);
    		t_o_v=atoi(t_oct);
    		if(t_o_v!=0){
    			
    			char c_oct[255];
    			int c_o_v;
    			printf("\nIngrese el cuarto Octeto: ");
    			scanf("%s",c_oct);
    			c_o_v=atoi(c_oct);
    			if(c_o_v!=0){
    				
    				if(p_o_v==10&&s_o_v>=0&&s_o_v<=255&&t_o_v>=0&&t_o_v<=255&&c_o_v>=1&&c_o_v<=255){
    					printf("\nDireccion de RED PRIVADA\n");
    					printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);                                                // IF PERTENECIENTE A LAS IP DE CLASE B
					}
					else if(p_o_v==172&&s_o_v>=16&&s_o_v<=32&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){
						printf("\nDirecion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==192&&s_o_v==168&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){
						printf("\nDireccion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==127&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion de LOOPBACK\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==224&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion MULTICAST\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==1&&s_o_v==255&&t_o_v==255&&c_o_v==255){
						printf("\nDireccion de Difusion\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==1&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion de RED\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else{
						printf("\nDireccion PUBLICA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
				}
				else{
					printf("\nOcteto Erroneo");
				}
			}
			else{
				printf("\nOcteto Erroneo\n");
			}
		}
		else{
			printf("\nOcteto Erroneo\n");
		}
	}
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	else if(p_o_v>=192&&p_o_v<=223){ //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  
		printf("\nCLASE C\n");
			char s_oct[255];
    	int s_o_v;
    	printf("\nIngrese el segundo Octeto: ");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  
    	scanf("%s",s_oct);
    	s_o_v=atoi(s_oct);
    	if(s_o_v!=0){
    		//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  
    		
    		char t_oct[255];
    		int t_o_v;
    		printf("\nIngrese el tercer Octeto: ");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  
    		scanf("%s",t_oct);
    		t_o_v=atoi(t_oct);
    		if(t_o_v!=0){
    			
    			char c_oct[255];
    			int c_o_v;
    			printf("\nIngrese el cuarto Octeto: ");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  
    			scanf("%s",c_oct);
    			c_o_v=atoi(c_oct);
    			if(c_o_v!=0){
    				
    				if(p_o_v==10&&s_o_v>=0&&s_o_v<=255&&t_o_v>=0&&t_o_v<=255&&c_o_v>=1&&c_o_v<=255){//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   
    					printf("\nDireccion de RED PRIVADA\n");
    					printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);                                                                                                                       // IF PERTENECIENTE A LAS IP DE CLASE C
					}
					else if(p_o_v==172&&s_o_v>=16&&s_o_v<=32&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// 
						printf("\nDirecion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==192&&s_o_v==168&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// 
						printf("\nDireccion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==127&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion de LOOPBACK\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// 
					}
					else if(p_o_v==224&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion MULTICAST\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  
					}
					else if(p_o_v==1&&s_o_v==255&&t_o_v==255&&c_o_v==255){
						printf("\nDireccion de Difusion\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   
					}
					else if(p_o_v==1&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion de RED\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);//   //   //  //  //  /// //  //   //   //  //  //  /// //  
					}
					else{
						printf("\nDireccion PUBLICA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);//   //   //  //  //  /// //  //   //   //  //  //  
					}
				}
				else{
					printf("\nOcteto Erroneo");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  
				}
			}
			else{
				printf("\nOcteto Erroneo\n");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   // 
			}
		}
		else{
			printf("\nOcteto Erroneo\n");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   
		}
	}//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------  
	else if(p_o_v>=224&&p_o_v<=239){
		printf("\nCLASE D\n");
			char s_oct[255];
    	int s_o_v;
    	printf("\nIngrese el segundo Octeto: ");
    	scanf("%s",s_oct);
    	s_o_v=atoi(s_oct);
    	if(s_o_v!=0){
    		
    		char t_oct[255];
    		int t_o_v;
    		printf("\nIngrese el tercer Octeto: ");
    		scanf("%s",t_oct);
    		t_o_v=atoi(t_oct);
    		if(t_o_v!=0){
    			
    			char c_oct[255];
    			int c_o_v;
    			printf("\nIngrese el cuarto Octeto: ");
    			scanf("%s",c_oct);
    			c_o_v=atoi(c_oct);
    			if(c_o_v!=0){
    				
    				if(p_o_v==10&&s_o_v>=0&&s_o_v<=255&&t_o_v>=0&&t_o_v<=255&&c_o_v>=1&&c_o_v<=255){
    					printf("\nDireccion de RED PRIVADA\n");
    					printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==172&&s_o_v>=16&&s_o_v<=32&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){
						printf("\nDirecion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==192&&s_o_v==168&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){
						printf("\nDireccion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==127&&s_o_v==1&&t_o_v==1&&c_o_v==1){                                                              // IF PERTENECIENTE A LAS IP DE CLASE D
						printf("\nDireccion de LOOPBACK\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==224&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion MULTICAST\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==1&&s_o_v==255&&t_o_v==255&&c_o_v==255){
						printf("\nDireccion de Difusion\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==1&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion de RED\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else{
						printf("\nDireccion PUBLICA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
				}
				else{
					printf("\nOcteto Erroneo");
				}
			}
			else{
				printf("\nOcteto Erroneo\n");
			}
		}
		else{
			printf("\nOcteto Erroneo\n");
		}
	}
	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	else if(p_o_v>=240&&p_o_v<=255){
		printf("\nCLASE E\n");
			char s_oct[255];//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  //
    	int s_o_v;
    	printf("\nIngrese el segundo Octeto: ");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //  
    	scanf("%s",s_oct);
    	s_o_v=atoi(s_oct);
    	if(s_o_v!=0){
    		                                       //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   
    		char t_oct[255];
    		int t_o_v;
    		printf("\nIngrese el tercer Octeto: ");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   // 
    		scanf("%s",t_oct);
    		t_o_v=atoi(t_oct);                     //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   // //
    		if(t_o_v!=0){
    			                                //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /
    			char c_oct[255];
    			int c_o_v;
    			printf("\nIngrese el cuarto Octeto: ");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  /
    			scanf("%s",c_oct);
    			c_o_v=atoi(c_oct);
    			if(c_o_v!=0){
    			
    				if(p_o_v==10&&s_o_v>=0&&s_o_v<=255&&t_o_v>=0&&t_o_v<=255&&c_o_v>=1&&c_o_v<=255){//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //
    					printf("\nDireccion de RED PRIVADA\n");
    					printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==172&&s_o_v>=16&&s_o_v<=32&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  
						printf("\nDirecion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==192&&s_o_v==168&&t_o_v>=0&&t_o_v<=255&&c_o_v>=0&&c_o_v<=255){//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  IF PERTENECIENTE A LAS IP DE CLASE E
						printf("\nDireccion de RED PRIVADA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==127&&s_o_v==1&&t_o_v==1&&c_o_v==1){//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  
						printf("\nDireccion de LOOPBACK\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);
					}
					else if(p_o_v==224&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion MULTICAST\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  //
					}
					else if(p_o_v==1&&s_o_v==255&&t_o_v==255&&c_o_v==255){
						printf("\nDireccion de Difusion\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  // 
					}
					else if(p_o_v==1&&s_o_v==1&&t_o_v==1&&c_o_v==1){
						printf("\nDireccion de RED\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   
					}
					else{
						printf("\nDireccion PUBLICA\n");
						printf("\nIP ingresada: %d.%d.%d.%d",p_o_v,s_o_v,t_o_v,c_o_v);//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  
					}
				}
				else{
					printf("\nOcteto Erroneo");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  
				}
			}
			else{
				printf("\nOcteto Erroneo\n");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  //
			}
		}
		else{
			printf("\nOcteto Erroneo\n");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  
		}
	}
	else{
		printf("\nOcteto Erroneo\n");//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   
	}
	
	}
	else{
		printf("\nOCTETO ERRONEO\n");
	}//   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  //   //   //  //  //  /// //  

   getch();// getch para capturar la tecla perteneciente al menu ingresada 
  }
	
break;// fin del primer case

case 2:{ //inicio del segundo case que basicamente contiene informacion necesaria para el uso del programa
	

printf("\nClasificacion de las IP\n");
printf("\n****************************\n");
system("pause");
printf("\nClase A: El primer octeto esta comprendido entre 0-127\n");
printf("\nClase B: El primer octeto esta comprendido entre 128-191\n");
printf("\nClase C: El primer octeto esta comprendido entre 192-223\n");
printf("\nClase D: El primer octeto esta comprendido entre 224-239\n");
printf("\nClase E: El primer octeto esta comprendido entre 240-255\n");
printf("\n****************************\n");
system("pause");
printf("\nDirecciones privadas: IP comprendida entre:\n\n 10.0.0.1-10.255.255.255\t 172.16.0.0-172.32.255.255\t 192.168.0.0-192.168.255.255\n");
printf("\nDebido a el metodo de validacion en este programa las direcciones privadas cambian a:\n\n10.1.1.1-10.255.255.255\t 172.16.1.1-172.32.255.255\t 192.168.1.1-192.168.255.255\n");
system("pause");
printf("\nDireccion de loopback: 127.0.0.0\n");
printf("\nDebido a la validacion las Direcciones de Loopback cambian a: 127.1.1.1\n");
system("pause");
printf("\nIP MULTICAST: 224.0.0.0\n");
printf("\nDebido a la validacion la IP MULTICAST cambia a 244.1.1.1\n");
system("pause");
printf("\nDireccion de Difusion: 0.255.255.255\n");
printf("\nDebido a la validacion la Direccion de Difusion se cambia a 1.255.255.255\n");
system("pause");
printf("\nDireccion de Red: 0.0.0.0 pero debido a la validacion en este caso se tomara como 1.1.1.1\n");
system("pause");
printf("\nDireccion publica: Toda aquella que no entre en nignuna de las especificaciones anteriores\n");
printf("\n****************************\n");
printf("\nFIN\n");
printf("\n****************************\n");
system("pause");
}
break; // fin del segundo case

case 3: //inicio del tercer case utilizado para salir del programa
Beep(523,500); //se emite un beep antes de salir del programa
printf("Saliendo...");
exit(0);// fin del programa
break;
default:
printf("\nOpcion Invalida\n"); // defualt en caso de que no se ingrese ninguna opcion valida del menu 
break;//fin de default 
} //fin de switch
}// fin del while
return 0;
}

