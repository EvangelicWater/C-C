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
    printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Primer case\n");
    printf("\n[F2] Segundo case\n");
    printf("\n[F3] Tercer case\n");
    printf("\n[F4] Cuarto case\n");
    printf("\n[F5] Quinto case\n");
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
			printf("\nPrimer case.\n");
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    
    printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso

	    
	    
		}
            break;//fin de primer case
        case F2://inicio de segundo case F2
        	{
        		printf("\nSegundo case.\n");//aviso
        		system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    
	     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso
	    
			}
          
            break;//fin del segundo case
        case F3://inicio del tercer case
          {
          	printf("\ntercer case.\n");//impresion
          	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
    
            } break;//fin de case
        case F4://inicio de case
            {
			
            	printf("\ncuarto case.\n");//aviso
            	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	   
      printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso
}

			
    
        break;//fin de case
        
		case F5://inicio de case
		{
			printf("\nquinto case.\n");
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	   
      printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso
		   } break;//fin de case
		    
        default://default por si no se ingresa ninguna opcion del menu
            printf("\n no se selecciono ninguna opcion del menu.  \n");//aviso
			
            break;//fin de default
 
        }//fin de switch
    }//fin de while
    return 0;
}//fin de main
