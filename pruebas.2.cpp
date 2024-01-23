#include <windows.h>
#include <iostream>   
#include <locale.h> 
#include <stdio.h>
#include <conio.h> //librerias

#define ESC 27 //definimos que esc corresponde a 27 del codigo ascii
 
#define F1  -59
#define F2  -60
#define F3  -61
#define F4  -62
//se define cada tecla f con su respectivo valor del codigo ascii
 
 
 
int main()//inicializa main
{
    int key = 0;//se define que key vale 0
    printf("\nMenu usando Cadenas\n");
    printf("\n[F1] Valor ASCII\n");
    printf("\n[F2] Sin Vocales\n");
    printf("\n[F3] Inspeccion Cadena\n");
    printf("\n[F4] Triangulo de letras\n");
    printf("\nESC. Salir\n");
    printf("\nSeleccione una opcion: ");
    
   
    while(key != ESC)//mientras que la tecla ingresada sea diferente a ESC se ejecutara lo siguiente
    {
        key = getch();//se obtiene el valor ingresado de key
        if(key == 0)
            key = -getch();
        switch(key)//inicio de switch con el valor de key
        {
        case F1: {
			printf("\nValor ASCII ha sido ingresado\n");
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	     char nombre[300];
    int ascii=0;
    memset(nombre, 0, sizeof(nombre));
    printf("\nIngresa la cadena de caracteres: \n");
    fgets(nombre, sizeof(nombre), stdin);

    size_t n = strlen(nombre);
    if (n > 0 && nombre[n - 1] == '\n') {
        nombre[n - 1] = '\0';

        --n;
       
    }

    for (size_t i = 0; i < n; i++){
        int e = nombre[i];
         ascii=ascii+nombre[i];
        printf("El valor ASCII de la letra %c es : %d  y el resultado de la suma es : %d\n", nombre[i], e,ascii);
    }


    
    printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");

	    
	    
		}
            break;//fin de primer case
        case F2://inicio de segundo case F2
        	{
        		printf("\nSin Vocales ha sido ingresado\n");
        		system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    char cadena[50];
char tmpCad[80];

int i, s, j = 0;

printf("Ingrese la cadena: \n");

gets(cadena);
printf("Cadena original: %s",cadena);
s = strlen(cadena);


for (i = 0; i < s; i++)
{
    if (cadena[i] != 'a' && cadena[i] != 'e' && cadena[i] != 'i' && cadena[i] != 'o' && cadena[i] != 'u' && cadena[i] != 'A' && cadena[i] !='E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U')
    {
        tmpCad[j] = cadena[i];
        j++;
    }
}

tmpCad[j] = '\0';

printf("\ncadena sin vocales: %s\n", tmpCad);
	    
	     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
	    
			}
          
            break;//fin del segundo case
        case F3://inicio del tercer case
          {
          	printf("\nInspeccion Cadena ha sido ingresado\n");
          	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
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
     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
    
            } break;//fin de case
        case F4://inicio de case
            {
            	printf("\nTriangulo de letras ha sido ingresado\n");
            	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    int valor;
	    printf("Valor: ");
			scanf("%d",&valor);
			if(valor=1){
				printf("error");
			}
			else if(valor=2){
				printf("exito");
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
