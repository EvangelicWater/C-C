#include <windows.h>
#include <iostream>   
#include <locale.h> 
#include <stdio.h>
#include <conio.h> //librerias
#define MAXIMA_LONGITUD_CADENA 100//definimos la longitud maxima de la cadena con un valor de 100
#define ESC 27 //definimos que esc corresponde a 27 del codigo ascii
 
#define F1  -59
#define F2  -60
#define F3  -61
#define F4  -62
#define F5  -63
#define F6  -64
#define F7  -65
#define F8  -66
#define F9  -67//se define cada tecla f con su respectivo valor del codigo ascii
 
 
  char mat[5][100]={ //variable global que contiene todas las materias
  "Historia",
  "Calculo",
  "Sociales",
  "Biologia",
  "Etica",
  };      
    
    float tot[5][5];//variable global que va a recibir las calificaciones
    float prom;//variable global utilizada para calcular el promedio
    float suma=0;//variable global utilizada para la suma necesaria al calcular el promedio
    float promg=0;//variable global utilizada para calcular el promedio general
    float promMa=tot[5][5];//variable global utilizada el promedio mayor
          
           char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];//variable global utilizada para el alumno con mayor promedio 
    float matprom=tot[5][5];//variable global para calcular el promedio de cada materia 
    char materiaPromedioMayor[MAXIMA_LONGITUD_CADENA];//variable global para calcular el promedio mayor de las materias 
   
    void imprimirLinea()//funcion utilizada para la impresion de lineas "+------+------+" que se utilizan al imprimir las calificaciones
{
    int j;
    printf("+----------");
    for (j = 0; j< 5 + 1; j++)
    {
        printf("+--------");
    }
    printf("+\n");//se imprime + y se deja un espacio
}
int main()//inicializa main
{
    int key = 0;//se define que key vale 0
    
    printf("\nMenu Calificaciones <Array Bidimensional> \n");//inicio de menu
    printf("\n[F1] Capturar Calificaciones.\n");
    printf("\n[F2] Mostrar Calificaciones.\n");
    printf("\n[F3] Promedio de los Alumnos.\n");
    printf("\n[F4] Mejor Alumno.\n");
    printf("\n[F5] Promedio por Materias.\n");
    printf("\n[F6] Promedio general.\n");
    printf("\n[F7] Mejor promedio por materia.\n");
    printf("\n[Esc]Salir\n");
    printf("\n---------- \n");
    printf("Ingrese la opcion que desea ejecutar: \n");//fin de menu
    while(key != ESC)//mientras que la tecla ingresada sea diferente a ESC se ejecutara lo siguiente
    {
        key = getch();//se obtiene el valor ingresado de key
        if(key == 0)
            key = -getch();
        switch(key)//inicio de switch con el valor de key
        {
        case F1://primer case F1
        	int i;//variable de contador
        	int j;//variable de contador
        	
            printf("\nIngresar calificaciones ha sido elegido.\n");//se imprime un aviso de que opcion ha sido elegida 
            system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
            for(i=0;i<5;i++){//inicio de for con contador i
			
            for(j=0;j<5;j++){//inicio de for anidado con contador j
		
			
            printf("\nIngrese la calificacion: \n");//se solicitan las calificaciones
            scanf("%f",&tot[i][j]);//se obtienen las calificaciones
            	
			}//fin de for anidado
            }//fin de primer for
            
           
            printf("\nFin. ingrese otra opcion a ejecutar o ingrese esc para salir\n");//se imprime un aviso para que el usuario eliga la accion a tomar
            break;//fin de primer case
        case F2://inicio de segundo case F2
        	
        
        
            printf("\nMostrar calificaciones ha sido elegido.\n");//aviso
             char nomb[5][100]={ //variable global que contiene los nombres de los alumnos 
			 "Pedro",
        "Manuel",
        "Marina",
        "Renata",
        "Ruben",};
            system("pause");//pausa
	    system("cls");//limpieza
	    
	      
	       
	
	        imprimirLinea();//llamado a la funcion imprimirLinea
    printf("|  Alumno  |");//se empieza a imprimir la tabla 
     for (j = 0; j < 5; j++)//primer for
    {
        printf("%-10s", mat[j]);//imprime las materias con contador j
        
    }//fin del primer for
    printf("\n");//imprime espacio
    imprimirLinea();//llamado a la funcion imprimirLinea
            for(i=0;i<5;i++){//segundo for
            	 printf("|%-10s|", nomb[i]);//impresion de nombres con contador i
           	
	 	for(j=0;j<5;j++){//tercer for anidado
		 
	 	    
	 		printf("%0.4f |",tot[i][j]);//impresion de las calificaciones
	 		 
		 }//fin de tercer for
		 printf("\n");//se imprime espacios
        imprimirLinea();//llamado a la funcion imprimirLinea
		 
		 }//fin del segundo for
		printf("\nFin. ingrese otra opcion a ejecutar o ingrese esc para salir\n");//aviso
            break;//fin del segundo case
        case F3://inicio del tercer case
            printf("\nPromedio de los alumnos ha sido elegido\n");//aviso
             system("pause");//pausa
	    system("cls");//limpieza 
           
         for (i=0; i<5; i++) {//inicio de primer for
      suma = 0;//declaramos que suma tiene un valor de 0
 
      for (j=0; j<5; j++)//segundo for anidado
        suma = suma + tot[i][j];//se declara que el valor de la suma es el resultante de sumar la variable de suma con la variable de las calificaciones
 
      prom = suma /5;//se declara que el valor 
      printf("\nPromedio de %-10s:%f\n",nomb[i],prom);//impresion de los nombres con su respectivo promedio
      
    }//fin de primer for
 printf("\nFin. ingrese otra opcion a ejecutar o ingrese esc para salir\n");//aviso
          
            break;//fin de case
        case F4://inicio de case
            printf("\nMostrar el mejor promedio ha sido elegido.\n");//aviso
            system("pause");//pausa 
	    system("cls");//limpieza
	    memcpy(alumnoPromedioMayor, nomb[i], MAXIMA_LONGITUD_CADENA);//se utiliza la funcion memcpy que copia "n" de valores al destino elegido
   
             for (i = 0; i < 5; i++){//inicio de primer for
			 
         if (prom > promMa)//si el promedio es menor al promedio mayor
        {
            promMa = prom;//promedio mayor es igual a promedio 
            memcpy(alumnoPromedioMayor, nomb[i], MAXIMA_LONGITUD_CADENA);//se copia el valor de la variable para el alumno con el promedio mayor
        }//fin de if
       
        }//fin de for
         printf("Promedio mayor: %s con %0.2f\n", alumnoPromedioMayor, promMa);//se imprime el alumno con el mayor promedio y el promedio
          printf("\nFin. ingrese otra opcion a ejecutar o ingrese esc para salir\n");//aviso
    
            break;//fin de case
        case F5://inicio de case
            printf("\nPromedio por materia ha sido elegido.\n");//aviso
            system("pause");//pausa
	    system("cls");//limpieza
	    for (i=0; i<5; i++) {//inicio de for
      suma = 0;//suma tiene un valor de 0
      prom=0;//prom tiene un valor de 0
 
      for (j=0; j<5; j++)//inicio de for anidado
        suma = suma + tot[j][i];//suma tiene un valor de la suma mas la calificacion ingresada por fila para poder calcular el promedio de la materia
 
      prom = suma /5;//promedio tiene un valor de la suma entre 5
      printf("\nPromedio de %-10s:%f\n",mat[i],prom);//impresion de promedio por materia
       printf("\nFin. ingrese otra opcion a ejecutar o ingrese esc para salir\n");//aviso
	  
    }//fin de for
            break;//fin de case
        case F6://inicio de case
            printf("\nPromedio general ha sido elegido.\n");//aviso
            system("pause");//pausa
            system("cls");//limpieza
             for (i=0; i<5; i++) {//inicio de for
      suma = 0;//suma tiene un valor de 0
      prom=0;//promedio tiene un valor de 0
 
      for (j=0; j<5; j++)//inicio de segundo for anidado
        suma = suma + tot[j][i];//cambio de valores para calcular el promedio general
 
      prom = suma /5;
      promg=promg+prom;// se calculo sumando todas las calificaciones y dividiendolas por la cantidad de alumnos
      
      
    }//fin de for
    promg=promg/5;//se divide la suma de las calificaciones entre 5
            printf("\nPromedio general:%f\n",promg);//impresion de promedio general
             printf("\nFin. ingrese otra opcion a ejecutar o ingrese esc para salir\n");//aviso   
           
	    
            break;//fin de case
    case F7://inicio de case
	printf("Mejor promedio por materia ha sido elegido.");//aviso
	system("pause");//pausa
	    system("cls");//limpieza
	  memcpy(materiaPromedioMayor, mat[i], MAXIMA_LONGITUD_CADENA);//copia de valores con funcion memcpy
   
             for (i = 0; i < 5; i++){//inicio de for
			 
         if (prom > matprom)//si el promedio es menor a el promedio de la materia
        {
            matprom = prom;//promedio de la materia obtiene el valor de promedio
            memcpy(materiaPromedioMayor, mat[i], MAXIMA_LONGITUD_CADENA);//se copian los valores con la funcion memcpy
        }//fin de if
      
        }//fin de for
         printf("Promedio mayor: %s con %0.2f\n", materiaPromedioMayor, matprom);//se imprime la materia con el mayor promedio y el promedio
          printf("\nFin. ingrese otra opcion a ejecutar o ingrese esc para salir\n");   //aviso
		     
        
		   
        default://default por si no se ingresa ninguna opcion del menu
            printf("\n no se selecciono ninguna opcion del menu.  \n");//aviso
            break;//fin de default
 
        }//fin de switch
    }//fin de while
    return 0;
}//fin de main
