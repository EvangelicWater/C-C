#include <stdio.h>
int main(void){
int p,n;
printf("ingrese un numero\n");
p=scanf("%d",&n); /*Esto porque scanf devuelve valor 0 cuando el valor ingresado no es del formato solicitado*/
while(!p){
printf("ERROR, no es un numero, intentelo nuevamente\n");
scanf("%d",&n);
}
printf("Es un numero!\n");
return 0;
}
