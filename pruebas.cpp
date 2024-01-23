#include <stdio.h>
#include <stdlib.h>
 
int main() {
    
    char p_oct[255];
    int p_o_v;
    
    printf("Ingrese numero\n");
    scanf("%s",p_oct);
    p_o_v=atoi(p_oct); /* atoi convierte el numero ingresado como cadena en entero
    en caso de ser posible, de lo contrario retorna 0*/
    
    if(p_o_v!=0) 
        printf("El numero es: %d\n",p_o_v);
    else
        printf("No es un numero\n");
    
    return 0;
    
}
