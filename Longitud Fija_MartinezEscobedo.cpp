/*
programa realizado por:
 - Andrés Humberto Martínez Escobedo
 
fecha de elaboración 06/10/21
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nom[25];
    char direccion[25];
    int separador;//esto es un sepoarador de los char esta puesto para que al mostrar no se mesclen los caracteres.
    char telefono[15];
    char edad[35];
    char cp[10];
}Amigo;
char filename[20];
/*Funciones de Archivo*/
void Crear(void);
void visualizar(void);
void Agregar(void);





FILE *abrir_fichero_b(char cadena[], int metodo);

int main(){
    FILE *fp;
    int opc;
    char cad[10];

    fp = abrir_fichero_b(filename,0);
    do{
    system("cls");
        printf("\n\t\t\tMENU\n");
        printf("\n\t1. Crear Archivo (Cuidado, elimina lo que ya se tiene en el Archivo)");
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
   Amigo aux;
    fp = abrir_fichero_b(filename,0);
   if(!(fp))
       printf("\n Error de archivo de registro\n");
   else{
      printf("\n\t\t\t USUARIOS EN EL REGISTRO \n");
      printf("---------------------------------------------------------------\n");
      while ((fread(&aux, sizeof(aux), 1, fp))!=0){
        printf("\t\t=> Datos del USUARIO %d\n\n",i);
        printf("\tNombre: %s  | Direccion: %s  | Telefono: %s\n",aux.nom,aux.direccion,aux.telefono);
        printf("\tEdad: %s    | Codigo Postal: %s\n\n",aux.edad,aux.cp);
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

   printf("\n\t\t\t REGISTRANDO USUARIO AL REGISTRO\n\n");
   fp=abrir_fichero_b(filename,2);
   if(!(fp))
        printf("\n Error de archivo de registro\n");
   else{
        /*Introduciendo los Datos del Amigo*/
        aux.nom[0]='\0';
        printf("\tNOMBRE: ");
        gets(aux.nom);
        aux.direccion[0]='\0';
        printf("\tDIRECCION: ");
        gets(aux.direccion);
        aux.telefono[0]='\0';
         printf("\tTELEFONO: ");
        gets(aux.telefono);
        aux.edad[0]='\0';
        printf("\tEDAD: ");
        gets(aux.edad);
        aux.cp[0]='\0';
        printf("\tCP: ");
        gets(aux.cp);
        

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
