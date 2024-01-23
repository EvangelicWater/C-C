#include <stdlib.h>
#include <time.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <stdio.h>
void noRepetir(int * vector, int tamVector);

int main()
{
  int const TamVector = 10;
  int vector[TamVector] = {'\0'};

  int opc = 0;
  do {
    noRepetir(vector,TamVector);
    printf("\nDesea volver a ingresar otro dato? (1=Si | 0=NO): )");
    scanf("%d",&opc);
  } while (opc == 1);
  for(int i=0;i<10;i++){
  	printf("\nValores ingresados: %d ",vector[i]);
  }

  return EXIT_SUCCESS;
}

void noRepetir(int * vector, int tamVector)
{
  int valor;
  printf("\nIngrese el valor: ");
  scanf("%d",&valor);

  int i;
  bool unica = true;
  for( i=0; i<tamVector && vector[i] != '\0' && unica; i++ )
    unica = (vector[i] != valor);

  if( unica )
  {
    if( i < tamVector )
      vector[i] = valor;
  }
  else
  {
    printf("\nEste valor ya ha sido ingresado\n");
  }
  
}

