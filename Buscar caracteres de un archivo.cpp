/*
programa realizado por:
 - Andrés Humberto Martínez Escobedo
 - Diego Rodolfo Vargas Vega
 - Mireya Lizette Cisneros Sandoval 
fecha de elaboración 08/10/21
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct {
    char linea[150];
    
    int separador;//esto es un sepoarador de los char esta puesto para que al mostrar no se mesclen los caracteres.
   
}Amigo;
char filename[20];
/*Funciones de Archivo*/
void Crear(void);
void visualizar(void);
void Agregar(void);
void buscar(void);




FILE *abrir_fichero_b(char cadena[], int metodo);

int main(){
    FILE *fp;
    int opc;
    char cad[10];

    fp = abrir_fichero_b(filename,0);
    do{
    system("cls");
        printf("\n\t\t\tMENU\n");
        printf("\n\t1. Crear Archivo ");
        printf("\n\t2. Agregar Al Registro \n\t3. Visualizar Registro \n\t4. Salir\n");
        printf("\n Escoga una de las OPCIONES: ");

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
    
        }

        /*Solo parar cuando sea una de las opciones*/
        if(opc<4)
        {
            puts("\n\nPresiona Cualquier Tecla para Regresar al Menu");
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
 

		
		puts(" Ingresa el nombre del archivo: ");
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
	
}

void visualizar(void){
   FILE *fp;
   int i=1;
   int v = 0, c = 0, n = 0, s = 0;
   Amigo aux;
    fp = abrir_fichero_b(filename,0);
   if(!(fp))
       printf("\n Error de archivo de registro\n");
   else{
      printf("\n\t\t\t  REGISTRO \n");
      printf("---------------------------------------------------------------\n");
      while ((fread(&aux, sizeof(aux), 1, fp))!=0){
        printf("\t\t=> Datos del Registro %d\n\n",i);
        printf("\tLinea: %s \n",aux.linea);
         for (int x = 0; aux.linea[x]!='\0'; ++x)
    {
        if (aux.linea[x] == 'a' || aux.linea[x] == 'e' || aux.linea[x] == 'i' || aux.linea[x] == 'o' || aux.linea[x] == 'u' || aux.linea[x] == 'A' || aux.linea[x] == 'E' || aux.linea[x] == 'I' || aux.linea[x] == 'O' || aux.linea[x] == 'U')
            ++v;
        else if ((aux.linea[x] >= 'a' && aux.linea[x] <= 'z') || (aux.linea[x] >= 'A' && aux.linea[x] <= 'Z'))
                ++c;
             else if (aux.linea[x] >= '0' && aux.linea[x] <= '9')
                      ++n;
                  else
                      ++s;
    }
    printf("\tCantidad de Vocales: %d\n",v);
    printf("\tCantidad de Consonantes: %d\n",c);
    printf("\tCantidad de Numeros: %d\n",n);
    printf("\tCantidad de espacios en blanco/caracteres especiales: %d\n",s);
    
        
        i++;
      }
      printf("---------------------------------------------------------------\n");
      fclose(fp);
   }
}

void Agregar(void){
   FILE *fp;
   Amigo aux;
   char cad[3];
   
   printf("\n\t\t\t REGISTRANDO \n\n");
   fp=abrir_fichero_b(filename,2);
   if(!(fp))
        printf("\n Error de archivo de registro\n");
   else{
        /*Introduciendo los Datos */
        
        printf("\tLINEA: ");
        
        gets(aux.linea);
        fflush(stdin);
     
        

        fwrite(&aux, sizeof(aux), 1, fp);
        fclose(fp);
   }
}




FILE *abrir_fichero_b(char cadena[], int metodo){
    FILE *x;
    switch(metodo){
        case 0:
            x = fopen(cadena,"rb");
            break;
        case 1:
            x = fopen(cadena,"wb");
            break;
        case 2:
            x = fopen(cadena,"ab");
            break;
        case 3:
            x = fopen(cadena,"r+b");
            break;
    }
    return x;
}
