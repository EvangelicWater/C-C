#include<conio.h>
#include<stdio.h>
#include<locale.h>

int main()
{
    char nombre[20];
    
    setlocale (LC_ALL, "spanish");
    printf( "Introduzca su nombre: " );
    scanf( "%s", nombre );
    printf( "Hola %s, buenos días.", nombre );

    getch(); 

    return 0;
}
