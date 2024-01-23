#include "score4.h"
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
// Función principal del programa
int main(int argc, char *argv[])
{
  // Declaración de variables a utilizar
  int contador;
  int filas;
  int posiciones;
  int asteriscos;
  char c;
  // Solicitud del numero de filas a visualizar
  printf("No. de Filas : ");
  scanf(" %d",&filas);
  printf("caracter: ");
  scanf(" %c",&c);
  // Visualizar primera piramide
  posiciones=filas*2;
  for(contador=1;contador<=posiciones;contador+=2) {
     printf("%*c",posiciones-contador,'*');
     for(asteriscos=1;asteriscos<contador;asteriscos++) {
        printf("%c",c);
     }
     printf("\n");
  }
  // Visualizar segunda piramide
  posiciones=filas*2;
  for(contador=1;contador<=posiciones;contador+=2) {
     printf("%*c",(posiciones/2),'*');
     for(asteriscos=1;asteriscos<contador;asteriscos++) {
        printf("%c",c);
     }
     printf("\n");
  }
    // Visualizar tercera piramide
  posiciones=filas*2;
  for(contador=1;contador<=posiciones;contador+=2) {
     printf("%*c",((posiciones-(contador))/2)+1,'*');
     for(asteriscos=1;asteriscos<contador;asteriscos++) {
        printf("%c",c);
     }
     printf("\n");
  }
  system("PAUSE");
  return 0;
}
    
