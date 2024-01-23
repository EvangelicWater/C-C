/*
programa realizado por:
 - Andrés Humberto Martínez Escobedo
  - Diego Rodolfo Vargas Vega
 - Mireya Lizette Cisneros Sandoval 
 
fecha de elaboración 11/10/21
*/
//librerías necesarias para el funcionamiento del programa
#include <stdio.h>
#include <conio.h>
#include <clocale>
#include <windows.h>
#define BUFFER_SIZE 1000

typedef struct {
    char texto[300];
   
    int separador;//esto es un sepoarador de los char esta puesto para que al mostrar no se mesclen los caracteres.
    
}Fichero;
	
//variables globales 
char filename[20];
char letra[50];
int w;

/*Prototipos de funciones de Archivo*/
void Crear(void);
void visualizar(void);
void Agregar(void);
int Contar(FILE *fp, const char *w);

//FILE *abrir_fichero_b(char cadena[], int metodo);

int main(){ //programa principal 
    
    int opc;
    char cad[10];
	setlocale(LC_CTYPE,"spanish");
    //fp = abrir_fichero_b(filename,0);
    do{
    system("cls");
        printf("\n\t       MENU\n");
        printf("\n\t1. Crear Archivo");
        printf("\n\t2. Ingresar texto \n\t3. Buscar palabra \n\t4. Salir\n");
        printf("\n Escoja una de las OPCIONES: ");

        opc = atoi(gets(cad));
        while(opc<0 || opc>4) /*Limitando la entrada de las opciones*/
            opc = atoi(gets(cad));
        system("cls");
        switch(opc)
        {
        case 1:
                Crear();
                break;
        case 2:
                Agregar();
                break;
        case 3:
                visualizar();
                break;
        case 4:
                printf("\n Saliendo... ");
                return 0;
                break;

        }

        /*Solo parar cuando sea una de las opciones*/
        if(opc<5)
        {
            puts("\n\n Presiona Cualquier Tecla para Regresar al Menu");
            getch();
        }
    }
    while(opc!=4);

}

// FUNCION PARA CREAR UN ARCHIVO
/*****************************************************************
*/
void Crear(void){
   FILE *fp;
		puts("\n Ingresa el nombre del archivo: ");
		gets(filename);
		strcat(filename,".txt"); //se define la extension del archivo
		fp=fopen(filename, "w");
		if(fp==NULL)
		{
		puts(" Error al abrir el archivo");
		system("pause");
		exit(1);
		}
		puts(" se ha creado el archivo correctamente");
		fclose(fp);
	
}

void visualizar(void){ // muestra las repeticiones de las palabras
   int i=1;
   int c=0;
   Fichero aux;
   FILE *fp = fopen(filename, "r");
   if(!(fp))
       printf("\n Error de archivo de registro\n");
   else{
      printf("\n\t BUSCAR PALABRA \n");
      printf("---------------------------------------------------------------\n");
     
	  
     printf("\n Ingresa la palabra a buscar: ");
    scanf("%s", letra);
     w = Contar(fp, letra);

    printf("\n '%s' se encontró y la cantidad de veces que se repite es: %d.\n", letra, w); 
    printf("---------------------------------------------------------------\n");
    fflush(stdin);
    fclose(fp);
    }
	
   }


void Agregar(void){ //funcion que escribe el texto
   FILE *fp;
   Fichero aux;
   char cad[3];

   printf("\n\t REGISTRO \n\n");
   fp=fopen(filename, "w");
   if(!(fp))
        printf("\n Error de archivo de registro\n");
   else{
        /*Introduciendo el texto*/
        aux.texto[0]='\0';
        fflush(stdin);
	    printf(" Ingrese el texto: ");
        gets(aux.texto);
        fputs(aux.texto,fp);
        fclose(fp);
   }
}


int Contar(FILE *fp, const char *letra) //función que cuenta
{
    char str[BUFFER_SIZE];
    char *pos;

    int index, c;
    
    c = 0;

    
    while ((fgets(str, BUFFER_SIZE, fp)) != NULL)
    {
        index = 0;

       
        while ((pos = strstr(str + index, letra)) != NULL)
        {
            
            index = (pos - str) + 1;

            c++;
        }
    }

    return c;
}


