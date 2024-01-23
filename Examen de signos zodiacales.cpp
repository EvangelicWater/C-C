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
int mes=0, dia=0;
 main()
 {
 	int mes,dia;
 	setlocale(LC_CTYPE, "Spanish");
 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),13);
	 gotoxy(24,10);    

 	printf("Bienvenido a la calculadorá de signo zodiacal \n ");
 	system("pause");
	    system("cls");
 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);    
    	gotoxy(23,9);
 	printf("Ingrese el mes en el que usted nacio:  ");
 	scanf("%d",&mes);
 	(getchar () != '\n');
 	system("pause");
	    system("cls");
 	
 	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);    
    	gotoxy(22,8);
 	printf("Ingrese el dia en el que usted nacio:  ");
 	scanf("%d",&dia);
 	(getchar () != '\n');
 	system("pause");
	    system("cls");
 	switch(mes)
 	{
 		case 1:
 			if(dia>18 && dia<32)
 			{
 				printf("Eres Acuario los Acuario a raiz de su fuerte personalidad tienen la capacidad de forjar relaciones muy estrechas y no dudan en entregarse a los demas cuando sea necesario  \n");
			 }
			 else if(dia>0 && dia<19)
			 {
			 	printf("Eres Capricornio eres muy seguro de ti mismo y no te gusta llevarte desagradables sorpresas, ser practico es crucial para la vida de los Capricornio  \n");
			 }
			 else
			 {
			 	printf("Error al ingresar los datos  \n");
			 }
			 break;
		case 2:
		    if(dia>0 && dia<19)
			{
				printf("Eres Acuario los Acuario a raiz de su fuerte personalidad tienen la capacidad de forjar relaciones muy estrechas y no dudan en entregarse a los demas cuando sea necesario  \n");
				 }
			else if(dia>18 && dia<30)
			{
				printf("Eres Piscis sabes gestionar los problemas y no dudas a la hora de tomar responsabilidades cuando surgen conflictos  \n");
					 }
			else
			{
				printf("Error al ingresar los datos  \n");
							  }
			break;
		case 3:
		    if(dia>20 && dia<32)
			{
				printf("Eres Aries eres muy energetico y emprendedor en todas tus acciones pero tiendes a ser extremadamente impetuoso  \n");
													}
			else if(dia>0 && dia<21)
			{
				printf("Eres Piscis sabes gestionar los problemas y no dudas a la hora de tomar responsabilidades cuando surgen conflictos  \n");
				}
			else
			{
				printf("Error al ingresar los datos \n ");
				}
			break;
		case 4:
		    if(dia>0 && dia<20)
			{
				printf("Eres Aries eres muy energetico y emprendedor en todas tus acciones pero tiendes a ser extremadamente impetuoso  \n");
						}
			else if(dia>19 && dia<31)
			{
				printf("Eres Tauro eres muy tranquilo y prefieres llevar una vida relajada buscas la estabilidad y eres muy romantico  \n");
									}
			else
			{
				printf("Error al ingresar los datos  \n");
															}
			break;
		case 5:
			if(dia>0 && dia<21)
			{
				printf(" Eres Tauro eres muy tranquilo y prefieres llevar una vida relajada buscas la estabilidad y eres muy romantico  \n ");
																											}
			else if(dia>20 && dia<32)
			{
				printf("Eres Geminis tiendes a la inestabilidad con el objetivo a dar rienda suelta a tu creatividad  \n");
																											}
			else
			{
				printf("Error al ingresar los datos  \n");
																																																			}
			break;
		case 6:
			if(dia>0 && dia<21)
			{
				printf("Eres Geminis tiendes a la inestabilidad con el objetivo a dar rienda suelta a tu creatividad  \n");
				
				}
			else if(dia>21 && dia<31)
			{
				printf("Eres Cancer destacas por tu amor por tu familia y eres muy hogareño  \n");
				}
			else
			{
				printf("Error al ingresar los datos  \n");
					}
			break;
		case 7:
			if(dia>0 && dia<23)
			{
				printf("Eres Cancer destacas por tu amor por tu familia y eres muy hogareño  \n");
							}
			else if(dia>22 && dia<32)
			{
				printf("Eres Leo eres muy optimista y tienes una cualidad innata para ser un lider  \n");
											}
			else
			{
				printf("Error al ingresar los datos  \n");
																			}
			break;
		case 8:
			if(dia>0 && dia<23)
			{
				printf("Eres Leo eres muy optimista y tienes una cualidad innata para ser un lider  \n");
																																			}
			else if(dia>22 && dia<32)
			{
				printf("Eres Virgo tiendes a ser muy cuidadoso y conservador y deseas tener una vida ordenada  \n");
			
			}
			else
			{
				printf("Error al ingresar los datos  \n");
				
																																																																																																																																																																																																																																																																	
			}
			break;
		case 9:
			if(dia>0 && dia<23)
			{
			     printf("Eres Virgo tiendes a ser muy cuidadoso y conservador y deseas tener una vida ordenada  \n");
			} 
			else if(dia>22 && dia<31)
			{
				printf("Eres Libra eres muy sociable y una compañia muy agradable para todo el mundo  \n");
				}
			else
			{
				printf("Error al ingresar los datos  \n");
			}
			break;
		case 10:
			if(dia>0 && dia<23)
			{
				printf("Eres Libra eres muy sociable y una compañia muy agradable para todo el mundo  \n");
			}
			else if(dia>22 && dia<32)
			{
				printf("Eres Escorpio eres tremendamente observador y sabes resolver problemas por muy complicados que estos sean  \n");
				}
			else
			{
				printf("Error al ingresar los datos  \n");
			}
			break;
		case 11:
			if(dia>0 && dia<23)
			{
				printf("Eres Escorpio eres tremendamente observador y sabes resolver problemas por muy complicados que estos sean  \n");
		      }
			else if(dia>20 && dia<31)
			{
				printf("Eres Sagitario eres muy positivo y optimista y no sueles tener miedo a nuevos proyectos  \n");
		     } 
			else
			{
				printf("Error al ingresar los datos   \n");
		      }
			break;
		case 12:
			if(dia>0 && dia<22)
			{
				printf("Eres Sagitario eres muy positivo y optimista y no sueles tener miedo a nuevos proyectos  \n");
								} 
			else if(dia>21 && dia<32)
			{
				printf("Eres Capricornio eres muy seguro de ti mismo y no te gusta llevarte desagradables sorpresas, ser practico es crucial para la vida de los Capricornio  \n");
						 }
			else
			{
				printf("Error al ingresar los datos  \n");
		 	}
		default:
			 	printf("Error al ingresar los datos \n");		 					   																																																																																																																																													
																							}
	 system("pause");																																					  		 		 
	 }
 	
 
