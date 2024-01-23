#include <ostream>        
#include <windows.h>
#include <conio.h> 
#include <stdio.h>
#include <ctype.h>//librerias



#define ESC 27 //definimos que esc corresponde a 27 del codigo ascii
 
#define F1  -59
#define F2  -60
#define F3  -61
#define F4  -62
#define F5  -63
#define F6  -64
#define F7  -65
#define F8  -66
#define F9  -67
//se define cada tecla f con su respectivo valor del codigo ascii
 
 using namespace std;
 
int main(void)//inicializa main
{
    int key = 0;//se define que key vale 0
    char cad1[80];
    char cad2[80];
    char c;
    char d;
    int longitud;
    int ret=0;
    int i=0;
    printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Unir dos cadenas con strcat\n");
    printf("\n[F2] Copiar una cadena a otra cadena vacia con strncpy\n");
    printf("\n[F3] Invertir cadena con strrev\n");
    printf("\n[F4] Encontrar la longitud de la cadena con strlen\n");
    printf("\n[F5] Comparar dos cadenas con strcmp\n");
    printf("\n[F6] Convertir letras de una cadena a mayusculas con toupper\n");
    printf("\n[F7] Convertir letras de una cadena a minusculas con tolower\n");
    printf("\n[F8] Comprobar si una cadena se encuentra dentro de otra con strpbrk \n");
    printf("\n(no se deben de ingresar espacios en las cadenas)\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//menu
    
   
    while(key != ESC)//mientras que la tecla ingresada sea diferente a ESC se ejecutara lo siguiente
    {
        key = getch();//se obtiene el valor ingresado de key
        if(key == 0)
            key = -getch();
        switch(key)//inicio de switch con el valor de key
        {
        case F1: { //inicio del primer case
			printf("\nFuncion strcat.\n");
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    printf("La funcion strcat une una cadena al final de otra\n\n");
	    system("pause");
	    printf("\nIngrese la primera cadena:");
	    scanf("%s",cad1);
	    printf("\nIngrese la segunda cadena:");
	    scanf("%s",cad2);
	    strcat(cad1,cad2);
	    printf("\nCadena unida:%s\n",cad1);
	    system("pause");
	    
	    
     printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Unir dos cadenas con strcat\n");
    printf("\n[F2] Copiar una cadena a otra cadena vacia con strncpy\n");
    printf("\n[F3] Invertir cadena con strrev\n");
    printf("\n[F4] Encontrar la longitud de la cadena con strlen\n");
    printf("\n[F5] Comparar dos cadenas con strcmp\n");
    printf("\n[F6] Convertir letras de una cadena a mayusculas con toupper\n");
    printf("\n[F7] Convertir letras de una cadena a minusculas con tolower\n");
    printf("\n[F8] Comprobar si una cadena se encuentra dentro de otra con strpbrk \n");
    printf("\n(no se deben de ingresar espacios en las cadenas)\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//aviso

	    
	    
		}
            break;//fin de primer case
        case F2://inicio de segundo case F2
        	{
        		printf("\nFuncion strncpy.\n");//aviso
        		system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    printf("La funcion strncpy copia los n primeros caracteres de una cadena en otra\n\n");
	    system("pause");
	    printf("\nIngrese la primera cadena:");
	    scanf("%s",cad1);
	    printf("\nEn este caso la segunda cadena se encuentra vacia.\n");
	    strncpy (cad2,cad1,sizeof(cad2));
	    printf("\nSegunda cadena despues de aplicar strncpy:%s\n\n",cad2);
	    system("pause");
	    
	     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
		
     printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Unir dos cadenas con strcat\n");
    printf("\n[F2] Copiar una cadena a otra cadena vacia con strncpy\n");
    printf("\n[F3] Invertir cadena con strrev\n");
    printf("\n[F4] Encontrar la longitud de la cadena con strlen\n");
    printf("\n[F5] Comparar dos cadenas con strcmp\n");
    printf("\n[F6] Convertir letras de una cadena a mayusculas con toupper\n");
    printf("\n[F7] Convertir letras de una cadena a minusculas con tolower\n");
    printf("\n[F8] Comprobar si una cadena se encuentra dentro de otra con strpbrk \n");
    printf("\n(no se deben de ingresar espacios en las cadenas)\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//aviso
	    
			}
          
            break;//fin del segundo case
        case F3://inicio del tercer case
          {
          	printf("\nFuncion strrev.\n");//impresion
          	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    printf("La funcion strrev invierte una cadena\n\n");
	    system("pause");
	    printf("\nIngrese la cadena que desea invertir:");
	    scanf("%s",cad1);
	    printf("\nCadena invertida:%s\n\n",strrev(cad1));
	    system("pause");
     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
     printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Unir dos cadenas con strcat\n");
    printf("\n[F2] Copiar una cadena a otra cadena vacia con strncpy\n");
    printf("\n[F3] Invertir cadena con strrev\n");
    printf("\n[F4] Encontrar la longitud de la cadena con strlen\n");
    printf("\n[F5] Comparar dos cadenas con strcmp\n");
    printf("\n[F6] Convertir letras de una cadena a mayusculas con toupper\n");
    printf("\n[F7] Convertir letras de una cadena a minusculas con tolower\n");
    printf("\n[F8] Comprobar si una cadena se encuentra dentro de otra con strpbrk \n");
    printf("\n(no se deben de ingresar espacios en las cadenas)\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");
    
            } break;//fin de case
        case F4://inicio de case
            {
			
            	printf("\nFuncion strlen.\n");//aviso
            	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    printf("La funcion strlen devuelve la longitud de una cadena\n\n");
	    system("pause");
	    printf("\nIngrese la cadena que desea calcular:");
	    scanf("%s",cad1);
	    longitud = strlen(cad1);
        printf ("\nLongitud de la cadena: %d\n", longitud);
        system("pause");
	    
	   
      printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
	   printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Unir dos cadenas con strcat\n");
    printf("\n[F2] Copiar una cadena a otra cadena vacia con strncpy\n");
    printf("\n[F3] Invertir cadena con strrev\n");
    printf("\n[F4] Encontrar la longitud de la cadena con strlen\n");
    printf("\n[F5] Comparar dos cadenas con strcmp\n");
    printf("\n[F6] Convertir letras de una cadena a mayusculas con toupper\n");
    printf("\n[F7] Convertir letras de una cadena a minusculas con tolower\n");
    printf("\n[F8] Comprobar si una cadena se encuentra dentro de otra con strpbrk \n");
    printf("\n(no se deben de ingresar espacios en las cadenas)\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//aviso
}

			
    
        break;//fin de case
        
		case F5://inicio de case
		{
			printf("\nFuncion strcmp.\n");
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    printf("La funcion strcmp compara dos cadenas alfabeticamente.\ndevuelve 0 si las dos cadenas son iguales.\nDevuelve menor a 0 si la primera cadena es menor que la segunda cadena.\nDevuelve mayor que cero si la primera cadena es mayor a la segunda cadena.\n\n");
	    system("pause");
	    printf("\nIngrese la primera cadena:");
	    scanf("%s",cad1);
	    printf("\nIngrese la segunda cadena:");
	    scanf("%s",cad2);
	    ret = strcmp(cad1,cad2);

 
    if (ret == 0) {
    	printf("Las dos cadenas son equivalentes\n");
       
    } 
     else {
        	printf("Las dos cadenas no son equivalentes\n");
    }
    printf("Valor resutlado de strcmp:%d\n",ret);
    system("pause");
	   
      printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
	   printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Unir dos cadenas con strcat\n");
    printf("\n[F2] Copiar una cadena a otra cadena vacia con strncpy\n");
    printf("\n[F3] Invertir cadena con strrev\n");
    printf("\n[F4] Encontrar la longitud de la cadena con strlen\n");
    printf("\n[F5] Comparar dos cadenas con strcmp\n");
    printf("\n[F6] Convertir letras de una cadena a mayusculas con toupper\n");
    printf("\n[F7] Convertir letras de una cadena a minusculas con tolower\n");
    printf("\n[F8] Comprobar si una cadena se encuentra dentro de otra con strpbrk \n");
    printf("\n(no se deben de ingresar espacios en las cadenas)\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//aviso
		   } break;//fin de case
		    
		case F6:
		{
			printf("\nFuncion toupper.\n");
			system("pause");
			system("cls");
			printf("La funcion toupper devuelve la mayuscula asociada a caracter, si la tiene; si no, devuelve el mismo caracter. \n\n");
			system("pause");
			printf("\nIngrese la cadena:");
			scanf("%s",cad1);
			 
			 printf("\nCadena en Mayusculas:");
             while (cad1[i])
             {
            c=cad1[i];
            
             putchar (toupper(c));
               i++;
             }
			printf("\n");
			printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
			 printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Unir dos cadenas con strcat\n");
    printf("\n[F2] Copiar una cadena a otra cadena vacia con strncpy\n");
    printf("\n[F3] Invertir cadena con strrev\n");
    printf("\n[F4] Encontrar la longitud de la cadena con strlen\n");
    printf("\n[F5] Comparar dos cadenas con strcmp\n");
    printf("\n[F6] Convertir letras de una cadena a mayusculas con toupper\n");
    printf("\n[F7] Convertir letras de una cadena a minusculas con tolower\n");
    printf("\n[F8] Comprobar si una cadena se encuentra dentro de otra con strpbrk \n");
    printf("\n(no se deben de ingresar espacios en las cadenas)\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//aviso
			}break;//fin de case
			
		case F7:
		{
			printf("\nFuncion tolower.\n");
			system("pause");
			system("cls");
			printf("La funcion tolower devuelve la minuscula asociada a caracter, si la tiene; si no, devuelve el mismo caracter.\n\n");
			system("pause");
			printf("\nIngrese la cadena:");
			scanf("%s",cad1);
			 
			 printf("\nCadena en Minusculas:");
             while (cad1[i])
             {
            d=cad1[i];
            
             putchar (tolower(d));
               i++;
             }
			printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
			 printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Unir dos cadenas con strcat\n");
    printf("\n[F2] Copiar una cadena a otra cadena vacia con strncpy\n");
    printf("\n[F3] Invertir cadena con strrev\n");
    printf("\n[F4] Encontrar la longitud de la cadena con strlen\n");
    printf("\n[F5] Comparar dos cadenas con strcmp\n");
    printf("\n[F6] Convertir letras de una cadena a mayusculas con toupper\n");
    printf("\n[F7] Convertir letras de una cadena a minusculas con tolower\n");
    printf("\n[F8] Comprobar si una cadena se encuentra dentro de otra con strpbrk \n");
    printf("\n(no se deben de ingresar espacios en las cadenas)\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//aviso
			}break;//fin de case
		case F8:
		{
			
			printf("\nFuncion strpbrk.\n");
			system("pause");
			system("cls");
			printf("La funcion strpbrk encuentra la primera ocurrencia de alguno de los caracteres de una cadena dada en otra\n\n");
			system("pause");
			printf("\nIngrese la primera cadena:");
			scanf("%s",cad1);
			printf("\nIngrese la cadena que desea buscar en %s:",cad1);
			scanf("%s",cad2);
			if(strpbrk(cad1,cad2)!= NULL)
             printf("\nstrpbrk encontro la cadena %s en = %s\n",cad2, strpbrk( cad1, cad2 ) );
             else{
   	         printf("\nstrpbrk no encontro ninguna aparicion de %s en %s\n",cad2,cad1);
                }
			
			printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
			 printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Unir dos cadenas con strcat\n");
    printf("\n[F2] Copiar una cadena a otra cadena vacia con strncpy\n");
    printf("\n[F3] Invertir cadena con strrev\n");
    printf("\n[F4] Encontrar la longitud de la cadena con strlen\n");
    printf("\n[F5] Comparar dos cadenas con strcmp\n");
    printf("\n[F6] Convertir letras de una cadena a mayusculas con toupper\n");
    printf("\n[F7] Convertir letras de una cadena a minusculas con tolower\n");
    printf("\n[F8] Comprobar si una cadena se encuentra dentro de otra con strpbrk \n");
    printf("\n(no se deben de ingresar espacios en las cadenas)\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//aviso
			}break;//fin de case	    
		    
        default://default por si no se ingresa ninguna opcion del menu
            printf("\n no se selecciono ninguna opcion del menu.  \n");//aviso
			
            break;//fin de default
 
        }//fin de switch
    }//fin de while
    return 0;
}//fin de main
