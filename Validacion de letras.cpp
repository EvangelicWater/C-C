//VALIDACI?N DE UN NOMBRE O CADENA DE CARACTERES

#include<stdio.h>
#include<conio.h>
#include<string.h>

int validarNombre(char nombre[]);
int main()
{
     char nombre[20];
     int validacion;

     do
     {
         printf("\nINGRESA UN NOMBRE: ");
         scanf("%s",nombre);
         validacion=validarNombre(nombre);

     }while(validacion==0);

     printf("\nVALIDACION EXITOSA TU NOMBRE ES: %s"\n,nombre);

    getch();
    return 1;
}
//////////////////////////////////////
void validarNombre(char nombre[])
{
    int i;
    for(i=0 ; i<strlen(nombre); i++)
    {
        if(!(nombre[i]>=65 && nombre[i]<=90 || nombre[i]>=97 && nombre[i]<=122))
        {
            printf("\nSOLO INGRESA LETRAS\n");
            return 0;
        }
    }
    return 1;
}

