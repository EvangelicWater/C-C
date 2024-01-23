#include <iostream> 
#include <ios>
#include <ostream>        
#include <locale.h> 
#include <windows.h>
#include <stdio.h>
#include <conio.h> //librerias



#define ESC 27 //definimos que esc corresponde a 27 del codigo ascii
 
#define F1  -59
#define F2  -60
#define F3  -61
#define F4  -62
//se define cada tecla f con su respectivo valor del codigo ascii
 
 using namespace std;
 
int main(void)//inicializa main
{
    int key = 0;//se define que key vale 0
    printf("\nMenu usando Cadenas\n");
    printf("\n[F1] Valor ASCII\n");
    printf("\n[F2] Sin Vocales\n");
    printf("\n[F3] Inspeccion Cadena\n");
    printf("\n[F4] Triangulo de letras\n");
    printf("\nESC. Salir\n");
    printf("\nSeleccione una opcion: ");//menu
    
   
    while(key != ESC)//mientras que la tecla ingresada sea diferente a ESC se ejecutara lo siguiente
    {
        key = getch();//se obtiene el valor ingresado de key
        if(key == 0)
            key = -getch();
        switch(key)//inicio de switch con el valor de key
        {
        case F1: { //inicio del primer case
			printf("\nValor ASCII ha sido ingresado\n");
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	     char nombre[300];//declaracion de variables
    int ascii=0;
    memset(nombre, 0, sizeof(nombre));// copia de caracteres mediante el uso de la funcion memset
    printf("\nIngresa la cadena de caracteres: \n");//impresion
    fgets(nombre, sizeof(nombre), stdin);//se obtiene la cadena mediante fegets

    size_t n = strlen(nombre);//size adquiere el valor de el tamaño de la variable nombre
    if (n > 0 && nombre[n - 1] == '\n') {//si n es menor que 0 y nombre es igual a \n
        nombre[n - 1] = '\0';//nombre es igual a \0

        --n;//decremento de n
       
    }

    for (size_t i = 0; i < n; i++){//inicio de for
        int e = nombre[i];//variable
         ascii=ascii+nombre[i];//declaracion para la suma de los variables ascii
        printf("El valor ASCII de la letra %c es : %d  y el resultado de la suma es : %d\n", nombre[i], e,ascii);//impresion
    }//fin de for


    
    printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso

	    
	    
		}
            break;//fin de primer case
        case F2://inicio de segundo case F2
        	{
        		printf("\nSin Vocales ha sido ingresado\n");//aviso
        		system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    char cadena[50];
char tmpCad[80];

int i, s, j = 0;//declaracion de variables

printf("Ingrese la cadena: \n");//solicita cadena

gets(cadena);//recive cadena
printf("Cadena original: %s",cadena);//se imprime primero la cadena original para la comparacion
s = strlen(cadena);//s es igual a la cantidad de caracteres en cadena


for (i = 0; i < s; i++)//inicio de for
{
    if (cadena[i] != 'a' && cadena[i] != 'e' && cadena[i] != 'i' && cadena[i] != 'o' && cadena[i] != 'u' && cadena[i] != 'A' && cadena[i] !='E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U')//if para identificar vocales
    {
        tmpCad[j] = cadena[i];// cambio de valores 
        j++;//incremento de j
    }//fin de if
}//fin de for

tmpCad[j] = '\0';//cambio de valores

printf("\ncadena sin vocales: %s\n", tmpCad);//impresion de la cadena sin vocales
	    
	     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso
	    
			}
          
            break;//fin del segundo case
        case F3://inicio del tercer case
          {
          	printf("\nInspeccion Cadena ha sido ingresado\n");//impresion
          	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	     char cadena[51];
    int consonantes=0,vocales=0,digitos=0,punt=0,mayusculas=0,minusculas=0,espacios=0;
    int i,total;//declaracion de variables
    printf(" \nIngrese la cadena: "); //impresion
    gets(cadena);//obtiene cadena
 
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
     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
    
            } break;//fin de case
        case F4://inicio de case
            {
			
            	printf("\nTriangulo de letras ha sido ingresado\n");//aviso
            	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    char cad[50];
	int i,j;//declaracion de variables
	
	printf("\nIngrese la cadena de caracteres: ");//impresion
	gets(cad);//obtiene valores
 string pal = cad;//cambio de valores
  if (pal == cad){//si pal es igual a la cadena

  for (int i= 0; i < pal.length(); i++){//for con limite de la cantidad de variables ingresadas en pal que cambio su valor a los valores ingresados en cad
        for (int j = 0; j <= i; j++){//segundo for
          printf("%c",pal[j]);//impresion de la cadena ingresada
        }
        printf("\n");//impresion de espacios
      }
      printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso
}

			
    }
            break;//fin de case
        
		   
        default://default por si no se ingresa ninguna opcion del menu
            printf("\n no se selecciono ninguna opcion del menu.  \n");//aviso
			
            break;//fin de default
 
        }//fin de switch
    }//fin de while
    return 0;
}//fin de main
