//VALIDACIÓN DE UN NÚMERO ENTERO
#include<conio.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool validar_numeros(char numero[]);
//////////////////////////////////////////////////////////
int main()
{
    char cadena[20];
    bool valido=false;
    int N;

    do
    {
        printf("INGRESA UN NUMERO: ");
        scanf("%s",cadena);
        valido=validar_numeros(cadena);

    }while(valido==false);

    N=atoi(cadena);

    printf("\n EL VALOR DE N ES: %i",N);


   getch();
   return 1 ;
}
////////////////////////////////////////////////////////////
bool validar_numeros(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(numero[i]>=48 && numero[i]<=57))
        {
            printf("SOLO INGRESA NUMEROS\n");
            return false;
        }
    }
    return true;
}
