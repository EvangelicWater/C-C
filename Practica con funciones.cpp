#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <conio.h>

void recuadro(char,int,int );
int main()
{
    int al,an,x,y,alt,a;
    char c,ch;
	setlocale(LC_ALL,"spanish");
    printf("Introduce el  caracter que desea usar para el recuadro: ");
    scanf("%c",&c);

    printf("ingresa la altura del recuadro: ");
    scanf("%d",&al);
 
    printf("Ingrese el ancho del recuadro: ");
    scanf("%d",&a);
    printf("\n");
   void recuadro(char c, int al, int a);
   
    for(x=0;x<al;x++)
    {
        for(y=0;y<a; y++)
        {
           printf("%c",c);
        }
        
        printf("\n");
    }
    
    return 0;
}
