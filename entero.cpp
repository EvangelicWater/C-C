#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <conio.h>
int main() {
  float f; 
  int ent;

  printf("Ingrese un numero: ");
  scanf("%f",&f);

  ent = f;

  if(f - ent) {
    printf("\nEl numero ingresado es decimal.\n");
  }
  else {
    printf("\nEl numero ingresado es entero.\n");
  }
  return 0;
}








