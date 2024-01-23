#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <ios>
#include <ostream>        
#include <locale.h> 
#include <windows.h>
#include <ctype.h>
#include <string.h>
#define ESC 27 //definimos que esc corresponde a 27 del codigo ascii
 
#define F1  -59
#define F2  -60
#define F3  -61
#define F4  -62
#define F5  -63
#define F6  -64
#define F7  -65
#define F8  -66
#define F9  -67
//se define cada tecla f con su respectivo valor del codigo ascii

/*Programa hecho por Andres Humberto Martinez Escobedo 
 4520160054
 00603AM
 27/4/2021
*/


typedef struct{
	int edad[100];
	float estatura[10];
	char nombpil[10];
	char calle[50];
	char numero[50];
	char colonia[50];
	int telefono[10];
	char nombarch[8];
	char correo;
	
	
}registro;
//se define el struct con todo lo que necesito


void continuar()//funcion para pausa


{
    printf("Presione una tecla para continuar\n");
    getch();
}

void edad()//funcion para pedir la edad
{
	FILE*arch;
	arch=fopen("reg.dat","ab");//se abre el archivo 
	if (arch==NULL)//si el archivo no se puede abrir el programa regresa de valor "1"
        exit(1);
    registro reg;
	printf("\nIngrese la edad (solo numeros): \n");
	//se obtiene la edad
	if(scanf("%i",reg.edad) != 1){
		printf("Entrada de datos equivocados");
		fclose(arch);
		exit(-1);
	}
	fwrite(&reg,sizeof(registro),1,arch);//se utiliza fwrite para escribir los datos en el archivo
	
   
    
    fclose(arch);//fclose sirve para cerrar el archivo 
    continuar();//llamado a la funcion continuar
     
}

void estatura()//funcion que añade la estatura de la misma manera
{
	FILE*arch;
	arch=fopen("reg.dat","ab");
	if (arch==NULL)//si el archivo no se puede abrir el programa regresa de valor "1"
        exit(1);
    registro reg;
	printf("\nIngrese la estatura en metros (solo numeros): \n");
	
	
	if(scanf("%i",reg.estatura) != 1){
		printf("Entrada de datos equivocados");
		fclose(arch);
		exit(-1);
	}
	fflush(stdin);
	fwrite(&reg, sizeof(registro), 1, arch);//fwrite sirve para leer los datos de la memoria principal y los pasa el archivo, en este caso lee los datos ingresados del fichero y los pasa a el struct y el 1 representa las veces en las que se escribiran los datos
    fclose(arch);//fclose sirve para cerrar el archivo 
    continuar();//llamado a la funcion continuar 
	
}

void nombrepila()//funcion que añade el nombre de pila de la misma manera
{
	FILE*arch;
	arch=fopen("reg.dat","ab");
	if (arch==NULL)//si el archivo no se puede abrir el programa regresa de valor "1"
        exit(1);
    registro reg;
	printf("\nIngrese el nombre de pila: \n");
	
	if(scanf("%c",reg.nombpil) != 1){
		printf("Entrada de datos equivocados");
		fclose(arch);
		exit(-1);
	}
	fwrite(&reg, sizeof(registro), 1, arch);//fwrite sirve para leer los datos de la memoria principal y los pasa el archivo, en este caso lee los datos ingresados del fichero y los pasa a el struct y el 1 representa las veces en las que se escribiran los datos
    fclose(arch);//fclose sirve para cerrar el archivo 
    continuar();//llamado a la funcion continuar 
}

void domicilio()//funcion para el domicilio 
{
	FILE*arch;
	arch=fopen("reg.dat","r+b");
	if (arch==NULL)//si el archivo no se puede abrir el programa regresa de valor "1"
        exit(1);
    registro reg;
	printf("\nIngrese el nombre de  la calle: \n");
	
	if(scanf("%s",reg.calle) != 1){
		printf("Entrada de datos equivocados");
		fclose(arch);
		exit(-1);
	}
	printf("\nIngrese el numero de su domicilio (solo numeros): \n");
	
	if(scanf("%i",reg.numero) != 1){
		printf("Entrada de datos equivocados");
		fclose(arch);
		exit(-1);
	}
		printf("\nIngrese la colonia: \n");
	
	if(scanf("%s",reg.colonia) != 1){
		printf("Entrada de datos equivocados");
		fclose(arch);
		exit(-1);
	}
	
	fwrite(&reg, sizeof(registro), 1, arch);//fwrite sirve para leer los datos de la memoria principal y los pasa el archivo, en este caso lee los datos ingresados del fichero y los pasa a el struct y el 1 representa las veces en las que se escribiran los datos
    fread(&reg, sizeof(registro), 1, arch);//fread similar a fwrite lee los archivos pero en este caso despues de leerlos los pasa a la memoria principal
	strcat(reg.calle,", ");//strcat concatea la calle ingresada con ","
	strcat(reg.calle,reg.colonia);//se concatea calle con colonia
	strcat(reg.calle,", ");//concatea espacios para que no este todo pegado
	strcat(reg.calle,reg.numero);//concatea con el numero
	
	
	fclose(arch);//fclose sirve para cerrar el archivo 
    continuar();//llamado a la funcion continuar 
}


void telefono()//funcion para añadir el telefono
{
	
	FILE*arch;
	arch=fopen("reg.dat","ab");
	if (arch==NULL)//si el archivo no se puede abrir el programa regresa de valor "1"
        exit(1);
    registro reg;
	printf("\nIngrese el numero de su telefono (solo numeros): \n");
	
	
	if(scanf("%i",reg.telefono) != 1){
		printf("Entrada de datos equivocados");
		fclose(arch);
		exit(-1);
	}
	fflush(stdin);
	fwrite(&reg, sizeof(registro), 1, arch);//fwrite sirve para leer los datos de la memoria principal y los pasa el archivo, en este caso lee los datos ingresados del fichero y los pasa a el struct y el 1 representa las veces en las que se escribiran los datos
    fclose(arch);//fclose sirve para cerrar el archivo 
    continuar();//llamado a la funcion continuar 

}

void correo()//funcion para añadir el correo
{
	FILE*arch;
	arch=fopen("reg.dat","ab");
	if (arch==NULL)//si el archivo no se puede abrir el programa regresa de valor "1"
        exit(1);
    registro reg;
	printf("\nIngrese el  su correo: \n");
	
	if(scanf("%c",reg.correo) != 1){
		printf("Entrada de datos equivocados");
		fclose(arch);
		exit(-1);
	}
	fwrite(&reg, sizeof(registro), 1, arch);//fwrite sirve para leer los datos de la memoria principal y los pasa el archivo, en este caso lee los datos ingresados del fichero y los pasa a el struct y el 1 representa las veces en las que se escribiran los datos
    fclose(arch);//fclose sirve para cerrar el archivo 
    continuar();//llamado a la funcion continuar 
}


void eliminar()//funcion que no pidio pero considere buena idea añadir para eliminar el archivo binario
{
	FILE *arch;//puntero FILE
    arch=fopen("reg.dat","rb");//se abre el archivo
    if (arch==NULL)
        exit(1);//si no abre el archivo
        registro reg;
        fclose(arch);//para eliminar el archivo binario primero es necesario cerrarlo
        remove("reg.dat");//remove elimina el archivo binario 
        printf("\nArchivo binario eliminado con exito\n");//aviso
        continuar();//llamado a la funcion continuar
}
int main()
{
setlocale(LC_ALL, "spanish");
    
    int key = 0;//se define que key vale 0
     
    while(key != ESC){//mientras que la tecla ingresada no sea esc
    	printf("**********************************");
    printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Ingresar edad.\n");
    printf("\n[F2] Ingresar estatura.\n");
    printf("\n[F3] Ingresar nombre de pila.\n");
    printf("\n[F4] Ingresar Domicilio.\n");
    printf("\n[F5] Ingresar numero de telefono.\n");
    printf("\n[F6] Ingresar Nombre de Archivo. \n");
    printf("\n[F7] Ingresar Correo electronico. \n");
    
    printf("\n[F8] Eliminar archivo. \n");
    printf("\n[ESC]. Salir\n");
    
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//impresion de menu y se solicita la opcion a ejecutar

   key = getch();//se obtiene el valor ingresado de key
        if(key == 0)
            key = -getch();
        
        switch (key) {
            case F1:edad();
                   break;
            case F2:estatura();
                   break;
            case F3:nombrepila();
                   break;
            case F4:domicilio();
                   break;
            case F5:telefono();//llamado a las funciones en cada case
                   break;
            case F6:
            	{
				//intente hacer esto en una funcion pero no se porque me daba error con el isdigit
				
            	char nombre[8];//declaro una variable aparte para la revision de las posiciones
            	int bandera=0;//bandera que necesitare a continuacion
            	int i=0;
            	while(bandera==0){//mientras que la bandera tenga valor 0
				
            	printf("\nIngrese el nombre del archivo (sin numeros en la primera posicion ni caracteres especiales):");
            	scanf("%s",nombre);//se obtiene el nombre
            	for (i = 0; i <8; ++i){
		
        if (((int)nombre[i] != 0) && ((isalnum(nombre[i]) ==0) && (nombre[i] != '_')))
		{
		
		printf("\n\nError\n\n No se permite el uso de caracteres especiales\n");
		return 0;
		}
	}
            	if(isdigit(nombre[0]))//si en la primera posicion del nombre hay un numero 
            	{
				
            		printf("\nError\n El nombre del archivo no puede llevar un digito en la primera posicion\n Vuelva a intentarlo\n");//aviso
				}
			
			else{
					bandera=1;//si no hay ningun numero en la primera posicion del nombre se cambia el valor de la bandera para terminar el while
					strcat(nombre,".dat");//se le añade la extension. No encontre una manera para modificar el nombre del archivo binario segun lo que introduzca el usuario sin que ocurra un error al querer abrir el mismo archivo con las funciones
					FILE*arch;
	arch=fopen("reg.dat","ab");
	if (arch==NULL)//si el archivo no se puede abrir el programa regresa de valor "1"
        exit(1);
    registro reg;
	
	
	reg.nombarch[8]=nombre[8];//la variable del nombre en el struct obtiene el valor comprobado de la variable nombre
	fwrite(&reg, sizeof(registro), 1, arch);//fwrite sirve para leer los datos de la memoria principal y los pasa el archivo, en este caso lee los datos ingresados del fichero y los pasa a el struct y el 1 representa las veces en las que se escribiran los datos
    fclose(arch);//fclose sirve para cerrar el archivo 
    continuar();//llamado a la funcion continuar 
					
				}
				}
				}
			       break;
			
			case F7:correo(); 
			       break;
			
			
			
			       
			  
			case F8:eliminar();//llamado al resto de las funciones 
			       break;      
        }
    }
    return 0;//finaliza programa
}//!No se olvide de borrar el archivo binario
//que tenga un buen dia.

