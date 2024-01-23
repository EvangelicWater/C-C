#include <stdio.h>
#include <string.h>

int main() {

char cadena[50];
char tmpCad[80];
char cadena2[50];
int i, s, j = 0;

printf("Ingrese la cadena: \n");

gets(cadena);
printf("Cadena original: %s",cadena);
s = strlen(cadena);


for (i = 0; i < s; i++)
{
    if (cadena[i] != 'a' && cadena[i] != 'e' && cadena[i] != 'i' && cadena[i] != 'o' && cadena[i] != 'u')
    {
        tmpCad[j] = cadena[i];
        j++;
    }
}

tmpCad[j] = '\0';

printf("\ncadena sin vocales: %s\n", tmpCad);
return 0;
}
