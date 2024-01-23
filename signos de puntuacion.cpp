#include <iostream>
#include <cctype>
#include <cstdio>
 
using namespace std;
 
int main ()
{
    char cadena[51];
    int consonantes=0,vocales=0,digitos=0,punt=0,mayusculas=0,minusculas=0,espacios=0;
    int i,total;
    printf(" \nIngrese la cadena: "); 
    gets(cadena);
 
    for(i=0;i<51;i++)  // Cuento los caractes para luegousar los "for" sólo
    {                  // hasta donde haga falta y no hacerlo siempre hasta 51.
        if (!cadena[i])
        {
            total=i;
            break;
        }
    }
    for(i=0;i<total;i++)
    {
        
        
        if (isspace(cadena[i])) espacios++;  // Cuenta espacios en blanco
        if (isalpha(cadena[i]))  // Cuenta letras y números
        {
            if(isupper(cadena[i])) mayusculas++;  // Cuenta mayusculas
            else minusculas++;  // Cuenta minúsculas
            cadena[i]=tolower(cadena[i]);  // Pasamos letras a minusculas para contarlas
            switch(cadena[i])
            {
                case ('a'):  // cuenta vocales
                case ('e'):  //
                case('i'):  //
                case('o'):  //
                case('u'):  //
                vocales++;
                break;
               
            }
        }
    }
    printf(" \nEn la cadena hay: \n");   // Impresion de resultados
    
    printf(" \nVocales: %d \n",vocales);
    printf(" \nMayusculas: %d \n",mayusculas);
    printf(" \nMinusculas: %d \n",minusculas);
    printf(" \nEspacios en blanco: %d \n",espacios);
    
   
    return 0;
}
